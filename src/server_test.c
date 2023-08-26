#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static int bit_count = 0;
static int received_char = 0;

void handle_signal(int sig) {
    if (sig == SIGUSR1) {
        received_char |= (0x01 << bit_count);
    }
    bit_count++;
	printf("bit: %d and decimal:[%d]\n", bit_count, received_char);
    if (bit_count == 8) {
        printf("Serveur : Caractère reçu : '%c'\n", received_char);

        bit_count = 0;
        received_char = 0;
    }
}

int main() {
    printf("Serveur new : En attente de caractères...\n");

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);

    while (1) {
        pause();
    }

    return 0;
}
