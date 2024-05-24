/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:50 by nranna            #+#    #+#             */
/*   Updated: 2024/05/24 14:02:50 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_info(char **argv);

//each philo is a thread
int	main(int argc, char **argv)
{
	if (argc == 5)
	{
		printf("Number of philosophers: %d\n", atoi(argv[1]));
		printf("Time to die in ms: %d\n", atoi(argv[2]));
		printf("Time to eat in ms: %d\n", atoi(argv[3]));
		printf("Time to sleep in ms: %d\n", atoi(argv[4]));
	}
	if (argc == 6)
	{
		print_info(argv);
		printf("Philosophers must eat [%d] times\n", atoi(argv[5]));
	}
	return (0);
}

void	print_info(char **argv)
{
	printf("Number of philosophers: %d\n", atoi(argv[1]));
	printf("Time to die in ms: %d\n", atoi(argv[2]));
	printf("Time to eat in ms: %d\n", atoi(argv[3]));
	printf("Time to sleep in ms: %d\n", atoi(argv[4]));
	return ;	
}
