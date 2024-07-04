/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:20:37 by nranna            #+#    #+#             */
/*   Updated: 2024/07/04 20:55:36 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void	handle_thread_error(int status, t_opcode opcode);

void	mutex_handle(pthread_mutex_t mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	/*else if (opcode == CREATE)
		pthread_mutex_
	else if (opcode == JOIN)
	else if (opcode == DETACH)*/
	else
		error_exit("Error: Wrong opcode for mutex handle.\n");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		error_exit("Error: Can't create a new thread!\n");
	else if (status == EPERM)
		error_exit("Error: Missing permission!\n");
	else if ((status == EINVAL) && (CREATE == opcode))
		error_exit("Error: The value specified by attr is invalid!\n");
	else if ((status == EINVAL) && (JOIN == opcode || DETACH == opcode))
		error_exit("Error: Can't join this specific thread!\n");
	else if (ESRCH == status)
		error_exit("Error: No thread found with that ID!\n");
	else if (EDEADLK == status)
		error_exit("Error: A deadlock was found...\n");
}
