/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:29:23 by nranna            #+#    #+#             */
/*   Updated: 2024/12/12 20:34:08 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*ft_nothing(void *ft);
void	i_eat(void *phil);
void	i_sleep(void *phil);
void	*routine(void *phil);

void	give_threads(t_table *table, int philo_amount)
{
	int	i;

	i = 0;
	while (i < philo_amount)
	{
		table->philo[i]->table = table;
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
	t_philo *philo = (t_philo *)phil;

	printf("max meals: %d\n\n\n\n", philo->table->rules->max_meals);
	while (philo->table->end_simulation == false)
	{
		printf("entrei aqui\n");
		i_eat(phil);
		i_sleep(phil);
		philo->meals_eaten++;
		if (philo->meals_eaten == philo->table->rules->max_meals)
			philo->table->end_simulation = true;
		printf("[%s] Philo %d has eaten %d times\n", philo->table->end_simulation?"true":"false", philo->philo_id, philo->meals_eaten);
	}
	printf("aklahydaslkj\n");
	return (NULL);
}

void	i_eat(void *phil)
{
	t_philo	*philo = (t_philo *)phil;

	pthread_mutex_lock(&philo->left_fork->mutex);
	printf("moment I got the fork %d \n", ft_time());
	printf("[%ld] %d has taken the left fork\n", (ft_time() - philo->table->start_time), philo->philo_id);
	pthread_mutex_lock(&philo->right_fork->mutex);
	printf("[%ld] %d has taken the right fork\n", (ft_time() - philo->table->start_time), philo->philo_id);
	printf("Philo %d is eating for %d seconds\n", philo->philo_id, philo->table->rules->time_to_eat);
	usleep(philo->table->rules->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	return ;
}

void	i_sleep(void *phil)
{
	t_philo	*philo = (t_philo *)phil;

	printf("[%ld] %d is sleeping\n", (ft_time() - philo->table->start_time), philo->philo_id);
	usleep(philo->table->rules->time_to_sleep * 1000);
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