/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:19 by nranna            #+#    #+#             */
/*   Updated: 2024/12/13 22:36:24 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <sys/time.h>

long int    ft_time(void)
{
    long int time;
    struct timeval tv2;

    gettimeofday(&tv2, NULL);
    time = tv2.tv_sec * 1000 + tv2.tv_usec / 1000;
    return (time);
}

long int	ft_logtime(long int start_time)
{
    long int actual_time;

    actual_time = ft_time() - start_time;
    return (actual_time);
}

void    smart_sleep(long int ms, t_table *table)
{
    long int start_time;
    long int actual_time;

    start_time = ft_time();
    actual_time = ft_time();
    while ((actual_time - start_time) < ms)
    {
        usleep(100);
        actual_time = ft_time();
        if (table->end_simulation == true)
		    break ;
    }
    return ;
}