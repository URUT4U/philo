/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:29:23 by nranna            #+#    #+#             */
/*   Updated: 2024/07/01 12:00:14 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*ft_nothing(void *ft);

void	give_threads(t_table *table)
{
	pthread_t	n_thread;
	
	table->philo[0]->thread_id = pthread_create(&n_thread, NULL,
			&ft_nothing, NULL);
	return ;
}

void	*ft_nothing(void *ft)
{
	printf("I wont eat nor think... but I'll sleep!\n");
	sleep(10);
	return (NULL);
}
