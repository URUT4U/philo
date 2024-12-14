/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:43:54 by nranna            #+#    #+#             */
/*   Updated: 2024/12/13 17:00:29 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	while (42)
	{
		gettimeofday(&tv, NULL);
		printf("the actual time is: %ld\n", tv.tv_usec);
		sleep(3);
	}
	gettimeofday(&tv, NULL);
	return (0);
}
