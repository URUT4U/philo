/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads04.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:51:12 by nranna            #+#    #+#             */
/*   Updated: 2024/06/03 16:25:14 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void	*function(void *arg)
{
	//that's a nice workaround to get our void *ptr
	//and see our variable value
	int	*n;

	n = (int *)arg;
	//dereference ftw
	printf("I'm alive and I'm the thread number: %d\n", *n);
	printf("Now I'll wait for main function to end\n");
	return (NULL);
}

int	main(void)
{
	int		ft = 42;
	pthread_t	thread;
	
	//this way we can pass a value to the thread
	pthread_create(&thread, NULL, function, (void *)&ft);
	pthread_join(thread, NULL);
	for (int i = 3; i != 0; i--)
	{
		printf("zZzZ..\n");
		sleep(1);
	}
	return (0);
}
