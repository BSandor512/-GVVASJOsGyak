#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int pid;
    int status;
    if ((pid = fork()) < 0)
    {
        perror("Hiba a forkban");
        exit(5);
    }
    else if (pid == 0)

    abort();
    if(wait(&status)!=pid)
    {
        perror("Hiba");
    }
    if(WIFEXITED(status))
        printf("Sikerult a kilepes");

    return 0;
}
