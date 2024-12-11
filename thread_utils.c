/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:29:23 by nranna            #+#    #+#             */
/*   Updated: 2024/12/11 18:07:15 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*ft_nothing(void *ft);
void	i_eat(void *phil);
void	*routine(void *phil);

void	give_threads(t_table *table, int philo_amount)
{
	int	i;

	i = 0;
	while (i < philo_amount)
	{
		if (pthread_create(&table->philo[i]->thread_id,
					NULL, &routine, table->philo[i]))
			error_exit("Pthread_create error...\n");
		i++;
	}
	i = 0;
	while (i < philo_amount)
	{
		if (pthread_join(table->philo[i]->thread_id, NULL))
			error_exit("Pthread_join error... \n");
		i++;
	}
	return ;
}

void	*routine(void *phil)
{
	printf("Thread: cheguei aqui\n ");
	i_eat(phil);
	return (NULL);
}

void	i_eat(void *phil)
{
	t_philo	*philo = (t_philo *)phil;

	pthread_mutex_lock(&philo->left_fork->mutex);
	printf("timestamp_in_ms %d has taken the left fork\n", philo->philo_id);
	pthread_mutex_lock(&philo->right_fork->mutex);
	printf("timestamp_in_ms %d has taken the right fork\n", philo->philo_id);
	printf("I'll eat for %ld seconds", philo->table->start_time);
	sleep(philo->table->rules->time_to_eat);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	return ;
}

void	*ft_nothing(void *ft)
{
	t_philo	*philo = (t_philo *)ft;

	printf("Thread %d: I wont eat nor think... but I'll sleep!\n",
		philo->philo_id);
	while (1)
		sleep(1);
	return (NULL);
}