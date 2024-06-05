/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:46:32 by nranna            #+#    #+#             */
/*   Updated: 2024/06/05 17:05:00 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "h_philo.h"

static t_fork	*create_fork(int index)
{
	t_fork	*fork;
	
	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->fork_id = (index + 1);
	return (fork);
}

static t_philo	*create_philo(int index)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0 , sizeof(t_philo));
	philo->philo_id = (index + 1);
	return (philo);
}

//maybe it's interesting to turn this into a create_table
t_table	create_table(int philos_amount)
{
	t_philo	**philos;
	t_fork	**forks;
	t_table	table;
	int	i;
	
	philos = malloc(sizeof(t_philo *) * philos_amount);
	forks = malloc(sizeof(t_fork *) * philos_amount);
	i = 0;
	while (i < philos_amount)
	{
		forks[i] = create_fork(i);
		philos[i] = create_philo(i);
		i++;
	}
	table.philo = philos;
	table.fork = forks;
	return (table);
}

int	main(void)
{
	t_table	table;
	
	table = create_table(3);
	return (0);
}
