/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:33:20 by nranna            #+#    #+#             */
/*   Updated: 2024/06/03 14:18:32 by nranna           ###   ########.fr       */
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
			//we need a sleep because threads get messy
			//when executed at the same time... this way
			//we ensure every thread can write properly
			sleep(1);
			i++;
		}
	}
	return (0);
}
