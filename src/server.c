/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:48:08 by tvo               #+#    #+#             */
/*   Updated: 2023/08/24 21:12:19 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	ft_handle_signal(int signal_num)
{
	static int	bit;
	static int	i;

	if (signal_num == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
	{
		printf("Error\n");
		return (1);
	}
	printf("PID du processus: %d\n", getpid());
	while (ac == 1)
	{
		signal(SIGUSR1, ft_handle_signal);
		signal(SIGUSR2, ft_handle_signal);
		pause ();
	}
	return (0);
}
