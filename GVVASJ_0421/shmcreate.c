#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#define SHMKEY 13

int main()
{
  int shmid;
  key_t kulcs;
  int meret = 512;
  int flag;

  kulcs = SHMKEY;
  flag = 0;
  if((shmid = shmget(kulcs, meret, flag)) < 0)
  {
    //Szegmens l�trehoz�sa
     flag = 00666 | IPC_CREAT;
     if((shmid = shmget(kulcs, meret, flag)) < 0)
     {
    perror("\n Sikertelen volt az shmget!\n");
    exit(-1);
     }
  }
//Ha m�r van szegmens
  printf("Az azonos�t�: %d\n", shmid);
  return 0;
}
