#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>



void megszakitas(int jel);
void kilepes(int jel);

unsigned int megszakitasok = 0;

int main(void)
{
    if (signal(SIGINT, megszakitas) == SIG_ERR)
    {
        printf("Nem sikerult\n");
        return 0;
    }

    if (signal(SIGQUIT, kilepes) == SIG_ERR)
    {
        printf("Nem sikerult!\n");
        return 0;
    }

    while(megszakitasok < 2)
    {
        printf("Varakozas a jelre...\n");
        sleep(1);
    }

    printf("Megvan a masodik SIGINT jel!");
    return 0;
}

void megszakitas(int jel)
{
    printf("SIGINT jel: %d\n", jel);
    megszakitasok++;
}

void kilepes(int jel)
{
    printf("SIGQUIT jel: %d\n", jel);
}
