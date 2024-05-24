/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:19:30 by nranna            #+#    #+#             */
/*   Updated: 2024/05/24 13:22:28 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	if (fork() == 0)
		printf("I'm a child!! and my pid is: %d\n", getpid());
	else
		printf("I'm old.... and my pid is: %d\n", getpid());
	return (0);
}
