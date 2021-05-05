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

        FILE *fajl;
        fajl = fopen("fajl_ird_bele.txt", "w");


        key_t key= 1234;
        int shmid;
        char *tartalom;
        if ((shmid = shmget(key,sizeof(char)* fseek(fajl,0L,SEEK_END), 0666 | IPC_CREAT)) < 0){
                perror("shmget");
                exit(1);
        }
        if((tartalom = shmat(shmid,NULL,0)) == (char *) -1){
                perror("shmat");
                exit(1);
        }
        printf("A memoria szegmensbol kiolvasott adat: ");
        printf("%s", tartalom);
        fprintf(fajl,"%s", tartalom);
        fclose(fajl);
        shmdt(tartalom);
        exit(0);
}
