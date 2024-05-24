/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:25:41 by nranna            #+#    #+#             */
/*   Updated: 2024/05/24 13:32:53 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	grandpa = getpid();
	int	parent;

	if ((parent = fork()) == 0)
	{
		int	child;
		if ((child = fork()) == 0)
		{
			usleep(200);
			printf("im a child!\n");
		}
		else
		{
			usleep(100);
			printf("im a dad!\n");
		}
	}
	else
		printf("I'm old...\n");
	return (0);
}
