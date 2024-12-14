/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:48:23 by nranna            #+#    #+#             */
/*   Updated: 2024/12/14 16:50:07 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"

void	unlock_forks2(t_philo *philo)
{
	if (philo->right_lock == true)
		pthread_mutex_unlock(&philo->right_fork->mutex);
	printf("[DEBUG] %ld Philo %d unlocked (right) Fork %d\n",  ft_logtime(philo->table->start_time), philo->philo_id, philo->right_fork->fork_id);
	philo->right_lock = false;
	if (philo->left_lock == true)
		pthread_mutex_unlock(&philo->left_fork->mutex);
	printf("[DEBUG] %ld Philo %d unlocked (left) Fork %d\n",  ft_logtime(philo->table->start_time), philo->philo_id, philo->left_fork->fork_id);
	philo->left_lock = false;
	return ;
}
