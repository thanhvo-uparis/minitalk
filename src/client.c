/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvo <tvo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:12:59 by tvo               #+#    #+#             */
/*   Updated: 2023/08/24 21:22:13 by tvo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int receiver_pid = 321005; // PID du récepteur (à remplacer par le PID réel)

    // Envoyer les bits un par un
    for (int i = 0; i < 8; i++) {
        if ((receiver_pid >> i) & 0x01) {
            kill(receiver_pid, SIGUSR1);
        } else {
            kill(receiver_pid, SIGUSR2);
        }
        usleep(500000); // Pause de 0.5 seconde entre chaque bit
    }
	// printf("abc");

    return 0;
}
