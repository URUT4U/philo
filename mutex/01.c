/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:37:19 by nranna            #+#    #+#             */
/*   Updated: 2024/12/11 16:45:43 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

#define ITER 100

void	increment(void *arg)
{
	while (ITER > 0)
	{
	}
	return ;
}

int	main(void)
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, increment, NULL);
	//thread compartilha variável, ao invés de fazer cópias
	
}
