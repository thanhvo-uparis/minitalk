/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:06:49 by tvo               #+#    #+#             */
/*   Updated: 2023/08/24 19:55:03 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Exemple d'utilisation de definir une fonction de gestionnaire de signal pour
// afficher un message lors que le signal est recu

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_handle_signal(int signal_num)
{
	printf("Signal %d est bien recu!\n", signal_num);
	exit(signal_num);
}

int	main()
{
	if (signal(SIGINT, ft_handle_signal) == SIG_ERR)
	{
		printf("error!");
		return 1;
	}
	printf("Appuyez CTR-C sur terminal\n");
	while (1)
	{
		sleep(3);
	}
	return 0;
}
