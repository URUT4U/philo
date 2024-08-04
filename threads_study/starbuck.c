/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starbuck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:26:46 by nranna            #+#    #+#             */
/*   Updated: 2024/08/03 20:46:18 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//small function to compare speed of a function with and without threads.
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
void	make_coffe(char *name)
{
	printf("%s is making your coffe...\n", name);
	sleep(3);
	printf("Ready.");
}

int	main(void)
{
	make_coffe("Nathan");
	make_coffe("Marcelly");
	return (0);
}*/

//usually we pass structs to threads because then we can hold a lot of
//data
void	*make_coffe(void *name)
{
	printf("%s is making your coffe...\n", (char *)name);
	sleep(3);
	printf("Ready.\n");
	return NULL;
}

int	main(void)
{
	char *name1 = "Marcelly";
	char *name2 = "Nathan";
	pthread_t	barista_1;
	pthread_t	barista_2;

	pthread_create(&barista_1, NULL, make_coffe, name1);
	pthread_create(&barista_2, NULL, make_coffe, name2);
	//this function \/ makes the threads WAIT for the main function to end.
	pthread_join(barista_1, NULL);
	pthread_join(barista_2, NULL);
	return (0);
}
