/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:33:20 by nranna            #+#    #+#             */
/*   Updated: 2024/05/24 14:55:15 by nranna           ###   ########.fr       */
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
		int	i = 0;

		while (i <= argc)
		{
			pthread_create(&n_thread, NULL, im_alive, NULL);
			i++;
		}
	}
	return (0);
}
