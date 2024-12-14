/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:31:25 by nranna            #+#    #+#             */
/*   Updated: 2024/12/14 13:03:30 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"

static int		i_eat(void *phil);
static int		i_sleep(void *phil);
static int		i_think(void *phil);
static void 	unlock_forks(t_fork *fork1, t_fork *fork2);

void	*routine(void *phil)
{
	t_philo *philo = (t_philo *)phil;

	while (philo->table->end_simulation == false)
	{
	//	printf("Philo %d got in the routine\n", philo->philo_id);
		if (i_eat(phil) == EXIT_FAILURE)
			break ;
		if (i_sleep(phil) == EXIT_FAILURE)
			break ;
		if (i_think(phil) == EXIT_FAILURE)
			break ;
		philo->meals_eaten++;
		if (philo->meals_eaten == philo->table->rules->max_meals)
			philo->table->end_simulation = true;
		//printf("[%s] Philo %d has eaten %d times\n", philo->table->end_simulation?"true":"false", philo->philo_id, philo->meals_eaten);
	}
	//printf("Philo %d left the routine\n", philo->philo_id);
	return (NULL);
}

static int	i_eat(void *phil)
{
	t_philo		*philo;
	long int	start_time;
	int			id;

	philo = (t_philo *)phil;
	if (philo->table->end_simulation == true)
		return (EXIT_FAILURE);
	start_time = philo->table->start_time;
	id = philo->philo_id;
	pthread_mutex_lock(&philo->left_fork->mutex);
	if (philo->table->end_simulation == true)
		return (unlock_forks(philo->left_fork, NULL), EXIT_FAILURE);
	printf("%ld %d has taken the left fork\n", ft_logtime(start_time), id);
	if (philo->right_fork != philo->left_fork)
		pthread_mutex_lock(&philo->right_fork->mutex);
	if (philo->table->end_simulation == true)
		return (unlock_forks(philo->left_fork, philo->right_fork), 1);
	printf("%ld %d has taken the right fork\n", ft_logtime(start_time), id);
	printf("%ld %d is eating\n", ft_logtime(start_time), id);
	philo->last_eat = ft_logtime(start_time);
	smart_sleep(philo->table->rules->time_to_eat * 1000, philo->table);
	unlock_forks(philo->left_fork, philo->right_fork);
	return (EXIT_SUCCESS);
}

static int	i_sleep(void *phil)
{
	t_philo		*philo;
	long int	start_time;
	int			id;

	philo = (t_philo *)phil;
	start_time = philo->table->start_time;
	id = philo->philo_id;
	if (philo->table->end_simulation == true)
		return (EXIT_FAILURE);
	printf("%ld %d is sleeping\n", ft_logtime(start_time), id);
	smart_sleep(philo->table->rules->time_to_sleep * 1000, philo->table);
	return (EXIT_SUCCESS);
}

static int	i_think(void *phil)
{
	t_philo		*philo;
	long int	start_time;
	int			id;

	philo = (t_philo *)phil;
	start_time = philo->table->start_time;
	id = philo->philo_id;
	if (philo->table->end_simulation == true)
		return (EXIT_FAILURE);
	printf("%ld %d is thinking\n", ft_logtime(start_time), id);
	return (EXIT_SUCCESS);
}

static void unlock_forks(t_fork *fork1, t_fork *fork2)
{
    if (fork1)
        pthread_mutex_unlock(&fork1->mutex);
    if (fork2 && fork2 != fork1)
        pthread_mutex_unlock(&fork2->mutex);
    return ;
}

/* void	i_eat(void *phil)
{
	printf("Philo %d got in the eat function\n", ((t_philo *)phil)->philo_id);
	t_philo	*philo = (t_philo *)phil;
	long int	start_time;
	struct timeval	tv;

	start_time = philo->table->start_time;
	tv = philo->table->tv;
	//printf("Philo %d is waiting left fork\n", philo->philo_id);
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_lock = true;
	if (philo->table->end_simulation == true)
		return ;
	printf("%ld %d has taken the left fork\n", ft_logtime(start_time), philo->philo_id);
	if (philo->left_fork != philo->right_fork)
			pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_lock = true;
	if (philo->table->end_simulation == true)
		return ;
	printf("%ld %d has taken the right fork\n", ft_logtime(start_time), philo->philo_id);
	printf("%ld %d is eating\n", ft_logtime(start_time), philo->philo_id);
	philo->last_eat = ft_logtime(start_time);
	smart_sleep(philo->table->rules->time_to_eat * 1000, philo->table);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	if (philo->left_fork == philo->right_fork)
		return ;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	if (philo->table->end_simulation == true)
		return ;
	return ;
}

void	i_sleep(void *phil)
{
	t_philo	*philo = (t_philo *)phil;
	long int	start_time;
	struct timeval	tv;

	start_time = philo->table->start_time;
	tv = philo->table->tv;
	if (philo->table->end_simulation == true)
		return ;
	printf("%ld %d is sleeping\n", ft_logtime(start_time), philo->philo_id);
	smart_sleep(philo->table->rules->time_to_sleep * 1000, philo->table);
	return ;
}

void	i_think(void *phil)
{
	t_philo	*philo = (t_philo *)phil;
	long int	start_time;
	struct timeval	tv;

	start_time = philo->table->start_time;
	tv = philo->table->tv;
	if (philo->table->end_simulation == true)
		return ;
	printf("%ld %d is thinking\n", ft_logtime(start_time), philo->philo_id);
	return ;
} */
