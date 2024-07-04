/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:29:23 by nranna            #+#    #+#             */
/*   Updated: 2024/07/03 14:11:27 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*ft_nothing(void *ft);

void	give_threads(t_table *table, int philo_amount)
{
	int	i;

	i = 0;
	while (i < philo_amount)
	{
		pthread_create(&table->philo[i]->thread_id, NULL, ft_nothing, NULL);
		i++;
	}
	i = 0;
	return ;
}

void	*ft_nothing(void *ft)
{
	printf("I wont eat nor think... but I'll sleep!\n");
	return (NULL);
}
