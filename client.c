#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void send_message(pid_t pid, const char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        char current_bit = message[i];

        for (int j = 0; j < 8; j++) {
            if (current_bit & (1 << j)) {
                kill(pid, SIGUSR1);
            } else {
                kill(pid, SIGUSR2);
            }
            usleep(100);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <serveur_pid> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    const char *message = argv[2];

    send_message(server_pid, message);

    return 0;
}
