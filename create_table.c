/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:22:15 by nranna            #+#    #+#             */
/*   Updated: 2024/12/14 15:38:08 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"

static t_philo	*create_philo(int index);
static t_fork	*create_fork(int index);

t_table	create_table(t_table *table, t_rules rules)
{
	t_philo	**philos;
	t_fork	**forks;
	int		i;
	
	philos = malloc(sizeof(t_philo *) * rules.philo_amount);
	forks = malloc(sizeof(t_fork *) * rules.philo_amount);
	i = 0;
	while (i < rules.philo_amount)
	{
		forks[i] = create_fork(i);
		philos[i] = create_philo(i);
		philos[i]->table = table;
		i++;
	}
	table->philo = philos;
	table->fork = forks;
	return (*table);
}

static t_philo	*create_philo(int index)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->philo_id = (index + 1);
	philo->last_eat = 0;
	return (philo);
}

static t_fork	*create_fork(int index)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->fork_id = (index + 1);
	printf("Fork ID: %i\n", fork->fork_id);
	pthread_mutex_init(&fork->mutex, NULL);
	return (fork);
}

void	give_forks(t_table *table, int philo_amount)
{
	printf("Philo amount: %d\n", philo_amount);
	int	i;

	i = 1;
	table->philo[0]->left_fork = table->fork[philo_amount - 1];
	table->philo[0]->right_fork = table->fork[0];
	printf("Philo ID: %d\n", table->philo[0]->philo_id);
	while (i <= (philo_amount - 1))
	{
		table->philo[i]->left_fork = table->fork[i - 1];
		table->philo[i]->right_fork = table->fork[i];
		printf("Philo ID: %d\n", table->philo[i]->philo_id);
		i++;
	}
	table->philo[i - 1]->left_fork = table->fork[i - 1];
	table->philo[i - 1]->right_fork = table->fork[i - 2];
	return ;
}
