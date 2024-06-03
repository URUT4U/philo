/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:33:20 by nranna            #+#    #+#             */
/*   Updated: 2024/06/03 15:36:52 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void	*im_alive(void *arg)
{
	printf("im alive\n");
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)	
	{
		pthread_t	n_thread;
		int	i = 1;

		while (i < argc)
		{
			printf("Thread number: %d\n", i);
			pthread_create(&n_thread, NULL, im_alive, NULL);
			sleep(1);
			i++;
		}
	}
	return (0);
}
