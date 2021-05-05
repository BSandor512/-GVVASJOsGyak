#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>


int main(int argc, char *argv[])
{
        printf("Beadando 12. feladat, keszitette: Balogh Sandor GVVASJ \n");
        printf("Irjon c nyelvu programokat, amivel hozzon letre egy osztott memoria szegmenst \n, ebbe olvassa be egy file tartalmat, egy masik program pedig olvassa ki az osztott memoria szegmensbol \n, es irja bele egy masik fileba, vegul szuntesse meg az shm szegmenst\n");
        FILE *fajl;
        char *tartalom;
        fajl = fopen("fajl_sandor.txt","r");
        if(fajl==NULL)
        {
        perror("Nem sikerult elerni a fajlt, hozza letre, ha nem letezik..");
        exit(1);
        }
        printf("\nA fajl letezik!\n");
        printf("\nFajl tartalmanak a kiolvasasa...\n");
        for(int i=0;i<5;i++)
        {
        printf(".\n");
        }
        fscanf(fajl, "%[^/t]",tartalom);
        printf("A fajl tartalma amit beolvastunk: ");
        printf("%s",tartalom);
        printf("\n");
        key_t key=1234;
        int shmid;
        char *adatok;
        if((shmid=shmget(key,1024,IPC_CREAT | 0666)) <0)
        {
        perror("shmget");
        exit(1);
        }

        if((adatok=shmat(shmid,NULL,0))==(char *) -1)
        {
        perror("shmat");
        exit(1);
        }

        strcpy(adatok,tartalom);

        shmdt(adatok);
        fclose(fajl);
        exit(0);
        return 0;
}

