/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:29:23 by nranna            #+#    #+#             */
/*   Updated: 2024/12/13 15:34:54 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

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

