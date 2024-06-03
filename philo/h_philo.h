/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:12:23 by nranna            #+#    #+#             */
/*   Updated: 2024/06/03 16:43:42 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_table
{
}	t_table;

typedef struct s_fork
{
	int	fork_id;
}	t_fork;

typedef struct s_philo_info
{
	int	philo_id;
	int	meals_eaten;
	t_fork	*left_fork;
	t_fork	*right_fork;
}	t_philo_info;

