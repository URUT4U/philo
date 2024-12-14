/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:19 by nranna            #+#    #+#             */
/*   Updated: 2024/12/12 20:43:36 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <sys/time.h>

int ft_time(void)
{
    int time;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    time = tv.tv_usec / 1000;
    return (time);
}
