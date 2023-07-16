#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <pid_processus_A>\n", argv[0]);
        return 1;
    }

    pid_t pid_processus_A = atoi(argv[1]);

    // Envoi du signal SIGUSR1 au processus A
    kill(pid_processus_A, SIGUSR1);

    sleep(1);

    // Envoi du signal SIGUSR2 au processus A
    kill(pid_processus_A, SIGUSR2);

    return 0;
}
