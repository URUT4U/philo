/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:11:53 by nranna            #+#    #+#             */
/*   Updated: 2024/05/24 10:21:35 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	my_turn(void);
void	*ur_turn(void *arg);

//when main ends, my thread ends as well. that's important.
int	main(void)
{
	pthread_t	n_thread;

	pthread_create(&n_thread, NULL, ur_turn, NULL);
	my_turn();
	return (0);
}

void	my_turn(void)
{
	int	i;
	
	i = 3;
	while (i >= 0)
	{
		printf("\n[ The program will end in... %d ]\n\n", i);
		sleep(1);
		i--;
	}	
	return ;
}

void	*ur_turn(void *arg)
{
	int	i;

	i = 8;
	while (i >= 0)
	{
		printf("I will NOT end in... %d\n", i);
		sleep(1);
		i--;
	}
	return (NULL);
}
