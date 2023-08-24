/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux_unix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:29:03 by tvo               #+#    #+#             */
/*   Updated: 2023/08/24 20:38:32 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_handle_signal(int signal_num)
{
	if (signal_num == SIGUSR1)
		printf("signal %d <SIGUSR1> est bien recu\n", signal_num);
	else if (signal_num == SIGUSR1)
		printf("signal %d <SIGUSR1> est bien recu\n", signal_num);
	exit(signal_num);
}

int	main()
{
	if (signal(SIGUSR1, ft_handle_signal) == SIG_ERR)
	{
		printf("error!");
		return 1;
	}
	if (signal(SIGUSR2, ft_handle_signal) == SIG_ERR)
	{
		printf("error!");
		return 1;
	}

	printf("PID du processus : %d\n", getpid());
	while (1)
	{
		sleep(3);
	}
	return 0;
}
