/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:12:23 by nranna            #+#    #+#             */
/*   Updated: 2024/12/14 16:50:37 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_table t_table;

/*
typedef enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;*/

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
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	t_table		*table;
	pthread_t	thread_id;
	int			last_eat;
	int			philo_id;
	int			meals_eaten;
	bool		full;
	bool		left_lock;
	bool		right_lock;
	t_fork		*left_fork;
	t_fork		*right_fork;
}	t_philo;

typedef struct s_table
{//it makes no sense for it to be a **, because there is only [0][0 ... n] TODO: change it later
	t_philo	**philo;
	t_fork	**fork;
	t_rules	*rules;
	struct timeval tv;
	long	start_time;
	bool	end_simulation;
}	t_table;

/* table utils */
t_table	create_table(t_table *table, t_rules rules);
void	give_forks(t_table *table, int philo_amount);
void	give_threads(t_table *table, int philo_amount);

/* utils */
void	error_exit(const char *error);

long int ft_time(void);
long int	ft_logtime(long int start_time);
void    waiter(t_table *table);
void    smart_sleep(long int ms, t_table *table);
void	unlock_forks2(t_philo *philo);



void	*routine(void *phil);
