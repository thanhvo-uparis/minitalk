#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int nsig[64];
void traitement(int s)
{
    printf("Signal %d a reçu %d fois!\n", s, ++nsig[s]);
}

int main()
{
    
    for (int s = 1; s < 64; s++)
    {
        if (signal(s, traitement) == SIG_ERR)
        {
            printf("Signal numéro %d est traitement par défault!\n", s);
            nsig[s] = 0;
        }
    }
    while(1) pause();
}