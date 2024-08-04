/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:47:56 by nranna            #+#    #+#             */
/*   Updated: 2024/08/03 23:49:31 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	nbr = 0;

void	*update(void *data)
{
	nbr = nbr + 1;
	return NULL;
}

int	main(void)
{
	pthread_t	threads[100];
	int	i;

	i = 0;
	while (i < 100)
	{
		if (pthread_create(&threads[i], NULL, update, NULL))
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < 100)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	printf("%d\n", nbr);
	return (0);
}
