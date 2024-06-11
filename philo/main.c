/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:50 by nranna            #+#    #+#             */
/*   Updated: 2024/06/10 22:11:54 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	print_info(char **argv);
void	start_simulation(t_table *table, char **argv);

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5)
	{
		print_info(argv);
		start_simulation(&table, argv);
	}
	else if (argc == 6)
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

void	start_simulation(t_table *table, char **argv)
{
	t_rules	rules;
	//int	philo_amount;
	//int	time_to_die;
	//int	time_to_eat;
	//int	time_to_sleep;
	//int	max_meals;

	rules.philo_amount = atoi(argv[1]);
	rules.time_to_die = atoi(argv[2]);
	rules.time_to_eat = atoi(argv[3]);
	rules.time_to_sleep = atoi(argv[4]);
	if (argv[5])
		rules.max_meals = atoi(argv[5]);
	*table = create_table(rules.philo_amount);
	give_forks(table, rules);
	return ;
}
