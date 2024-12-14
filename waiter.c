/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:05:22 by nranna            #+#    #+#             */
/*   Updated: 2024/12/13 22:30:49 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"

void unlock_forks(t_table *table)
{
    int i;

    i = 0;
    while (i < table->rules->philo_amount)
    {
        if (table->philo[i]->right_lock == true)
            pthread_mutex_unlock(&table->philo[i]->right_fork->mutex);
        if (table->philo[i]->left_lock == true)
            pthread_mutex_unlock(&table->philo[i]->left_fork->mutex);
        i++;
    }
    return;
}

void waiter(t_table *table)
{
    int i;
    long curr;

    curr = 0;
    printf("HELLO I'm the waiter!\n"); 
    while (!table->end_simulation)
    {
        i = 0;
        while (i < table->rules->philo_amount)
        {
            //printf("WAITER: last time Philosopher %d ate was: %d\n", table->philo[i]->philo_id, table->philo[i]->last_eat);
            curr = ft_time() - table->start_time;
            //printf("WAITER: current time is: %ld\n", curr);
            if ((curr - table->philo[i]->last_eat) >= table->rules->time_to_die)
            {
                unlock_forks(table);
                table->end_simulation = true;
                printf("%ld %d died\n", ft_logtime(table->start_time), table->philo[i]->philo_id);
                break;
            }
            i++;
        }
        usleep(1000);
    }
    return;
}
