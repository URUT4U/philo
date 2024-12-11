/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:22:15 by nranna            #+#    #+#             */
/*   Updated: 2024/08/04 03:16:10 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"

static t_philo	*create_philo(int index);
static t_fork	*create_fork(int index);

t_table	create_table(int philo_amount)
{
	t_philo	**philos;
	t_fork	**forks;
	t_table	table;
	int		i;

	philos = malloc(sizeof(t_philo *) * philo_amount);
	forks = malloc(sizeof(t_fork *) * philo_amount);
	i = 0;
	while (i < philo_amount)
	{
		forks[i] = create_fork(i);
		philos[i] = create_philo(i);
		i++;
	}
	table.philo = philos;
	table.fork = forks;
	return (table);
}

static t_philo	*create_philo(int index)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->philo_id = (index + 1);
	return (philo);
}

static t_fork	*create_fork(int index)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->fork_id = (index + 1);
	return (fork);
}

void	give_forks(t_table *table, int philo_amount)
{
	int	i;

	i = 1;
	table->philo[0]->left_fork = table->fork[philo_amount - 1];
	table->philo[0]->right_fork = table->fork[0];
	while (i <= (philo_amount - 1))
	{
		table->philo[i]->left_fork = table->fork[i - 1];
		table->philo[i]->right_fork = table->fork[i];
		printf("Hi, my philo ID is: %i\n", table->philo[i]->philo_id);
		i++;
	}
	table->philo[i - 1]->left_fork = table->fork[i - 1];
	table->philo[i - 1]->right_fork = table->fork[0];
	return ;
}
