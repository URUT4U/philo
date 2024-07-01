/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:29:23 by nranna            #+#    #+#             */
/*   Updated: 2024/07/01 14:06:30 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*ft_nothing(void *ft);

void	give_threads(t_table *table)
{
	pthread_t	thread_id;
	int	i;

	i = 0;
	while (table->philo[i])
	{
		pthread_create(&thread_id, NULL, &ft_nothing, NULL);
		table->philo[i]->thread_id = thread_id;
		pthread_join(thread_id, NULL);
		i++;
	}
	return ;
}

void	*ft_nothing(void *ft)
{
	printf("I wont eat nor think... but I'll sleep!\n");
	return (NULL);
}
