/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:12:23 by nranna            #+#    #+#             */
/*   Updated: 2024/06/05 15:59:18 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

//forks are mutexes.
typedef struct s_fork
{
	int	fork_id;
}	t_fork;

typedef struct s_philo
{
	int	philo_id;
	int	meals_eaten;
	bool	full;
	t_fork	*left_fork;
	t_fork	*right_fork;
}	t_philo;

typedef struct s_table
{
	t_philo	**philo;
	t_fork	**fork;
}	t_table;
