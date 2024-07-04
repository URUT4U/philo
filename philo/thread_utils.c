/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:29:23 by nranna            #+#    #+#             */
/*   Updated: 2024/07/04 13:14:48 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*im_alive(void *arg)
{
	printf("im alive\n");
	return (0);
}

void	give_threads(t_table *table, int philo_amount)
{
	int	i;

	i = 0;
	while (i <= (philo_amount - 1))
	{
		printf("Thread number: %d\n", i);
		pthread_create(&table->philo[i]->thread_id, NULL, im_alive, NULL);
		sleep(1);
		i++;
	}
	i = 0;
	while (i <= (philo_amount - 1))
	{
		pthread_join(table->philo[i]->thread_id, NULL);
		i++;
	}
	return ;
}
