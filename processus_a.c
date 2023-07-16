#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Signal SIGUSR1 reçu.\n");
    } else if (signum == SIGUSR2) {
        printf("Signal SIGUSR2 reçu.\n");
    }
}

int main() {
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    printf("PID du processus A : %d\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}
