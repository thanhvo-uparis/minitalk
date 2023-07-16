#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int received_bit = 0;
char received_message[100];

void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        received_bit = 1;
    } else if (signum == SIGUSR2) {
        received_bit = 0;
        printf("%c", received_message[0]);
        for (int i = 1; received_message[i] != '\0'; i++) {
            printf("%c", received_message[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Serveur PID: %d\n", getpid());

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1) {
        sleep(1);
    }

    return 0;
}
