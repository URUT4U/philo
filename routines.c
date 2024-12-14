/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:31:25 by nranna            #+#    #+#             */
/*   Updated: 2024/12/14 16:52:51 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"

static void	i_eat(t_philo *philo);
static void	i_sleep(t_philo *philo);
static void	i_think(t_philo *philo);
static void	unlock_forks(t_philo *philo);
static void	i_eat_odd(t_philo *philo);

void	*routine(void *phil)
{
	t_philo *philo = (t_philo *)phil;

 	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (philo->table->end_simulation == false)
	{
	//	printf("Philo %d got in the routine\n", philo->philo_id);
		if (philo->philo_id % 2 == 0)
			i_eat(philo);
		else
			i_eat_odd(philo);
		i_sleep(philo);
		i_think(philo);
		philo->meals_eaten++;
		if (philo->meals_eaten == philo->table->rules->max_meals)
			philo->table->end_simulation = true;
		//printf("[%s] Philo %d has eaten %d times\n", philo->table->end_simulation?"true":"false", philo->philo_id, philo->meals_eaten);
	}
	//printf("Philo %d left the routine\n", philo->philo_id);
	return (NULL);
}

static void	i_eat(t_philo *philo)
{
	//printf("Philo %d got in the eat function\n", (philo)->philo_id);
	long int	start_time;

	start_time = philo->table->start_time;
	printf("[DEBUG] Philo %d is waiting RIGHT fork\n", philo->philo_id);
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_lock = true;
	if (philo->table->end_simulation == true)
		return (unlock_forks(philo), (void)0);
	printf("%ld %d has taken the right fork\n", ft_logtime(start_time), philo->philo_id);
	printf("[DEBUG] Philo %d is waiting LEFT fork\n", philo->philo_id);
	if (philo->left_fork != philo->right_fork)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		philo->left_lock = true;
		printf("%ld %d has taken the left fork\n", ft_logtime(start_time), philo->philo_id);
	}
	if (philo->table->end_simulation == true)
		return ;
	if (philo->left_lock && philo->right_lock)
	{
		printf("%ld %d is eating\n", ft_logtime(start_time), philo->philo_id);
		philo->last_eat = ft_logtime(start_time);
	}
	smart_sleep(philo->table->rules->time_to_eat, philo->table);
	if (philo->table->end_simulation == true)
		return ;
	printf("%ld Philo %d has FINISHED eating\n", ft_logtime(start_time), philo->philo_id);
	return (unlock_forks(philo), (void)0);
}

static void	i_sleep(t_philo *philo)
{
	long int	start_time;

	start_time = philo->table->start_time;
	if (philo->table->end_simulation == true)
		return ;
	printf("%ld %d is sleeping\n", ft_logtime(start_time), philo->philo_id);
	smart_sleep(philo->table->rules->time_to_sleep, philo->table);
	//printf("%ld %d is awake\n", ft_logtime(start_time), philo->philo_id);
	return ;
}

static void	i_think(t_philo *philo)
{
	long int	start_time;

	start_time = philo->table->start_time;
	if (philo->table->end_simulation == true)
		return ;
	printf("%ld %d is thinking\n", ft_logtime(start_time), philo->philo_id);
	return ;
}

static void	unlock_forks(t_philo *philo)
{
	if (philo->left_lock == true)
		pthread_mutex_unlock(&philo->left_fork->mutex);
	printf("[DEBUG] %ld Philo %d unlocked (left) Fork %d\n",  ft_logtime(philo->table->start_time), philo->philo_id, philo->left_fork->fork_id);
	philo->left_lock = false;
	if (philo->right_lock == true)
		pthread_mutex_unlock(&philo->right_fork->mutex);
	printf("[DEBUG] %ld Philo %d unlocked (right) Fork %d\n",  ft_logtime(philo->table->start_time), philo->philo_id, philo->right_fork->fork_id);
	philo->right_lock = false;
	return ;
}

static void	i_eat_odd(t_philo *philo)
{
	//printf("Philo %d got in the eat function\n", (philo)->philo_id);
	long int	start_time;

	start_time = philo->table->start_time;
	//printf("[DEBUG] Philo %d is waiting LEFT fork\n", philo->philo_id);
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_lock = true;
	if (philo->table->end_simulation == true)
		return (unlock_forks2(philo), (void)0);
	printf("%ld %d has taken the left fork\n", ft_logtime(start_time), philo->philo_id);
	//printf("[DEBUG] Philo %d is waiting RIGHT fork\n", philo->philo_id);
	if (philo->right_fork != philo->left_fork)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		philo->right_lock = true;
		printf("%ld %d has taken the right fork\n", ft_logtime(start_time), philo->philo_id);
	}
	if (philo->table->end_simulation == true)
		return ;
	if (philo->left_lock && philo->right_lock)
	{
		printf("%ld %d is eating\n", ft_logtime(start_time), philo->philo_id);
		philo->last_eat = ft_logtime(start_time);
	}
	smart_sleep(philo->table->rules->time_to_eat, philo->table);
	if (philo->table->end_simulation == true)
		return ;
	//printf("%ld Philo %d has FINISHED eating\n", ft_logtime(start_time), philo->philo_id);
	return (unlock_forks2(philo), (void)0);
}