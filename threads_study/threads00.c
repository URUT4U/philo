/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:44:36 by nranna            #+#    #+#             */
/*   Updated: 2024/05/24 10:07:19 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*my_turn(void *arg);
void	ur_turn(void);

int	main(void)
{
	pthread_t	n_thread;
	
	//the function that goes into thread is the third arg.
	pthread_create(&n_thread, NULL, my_turn, NULL);
	while (42)
		ur_turn();
	return (0);
}

//every thread function must return a *void and take a *void as param.
void	*my_turn(void *arg)
{
	while (42)
	{
		sleep(1);
		printf("My turn :)\n");		
	}
	return (NULL);
}

void	ur_turn(void)
{
	while (42)
	{
		sleep(3);
		printf("No, your turn >:(\n");		
	}
	return ;
}
