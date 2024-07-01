/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:12:23 by nranna            #+#    #+#             */
/*   Updated: 2024/07/01 16:38:35 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//forks are mutexes.
typedef struct s_rules
{
	int	philo_amount;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}	t_rules;

typedef struct s_fork
{
	int	fork_id;
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread_id;
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

/* table utils */
t_table	create_table(int philo_amount);
void	give_forks(t_table *table, int philo_amount);
void	give_threads(t_table *table, int philo_amount);
