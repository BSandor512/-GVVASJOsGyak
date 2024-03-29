#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#define MSGKEY 654321L

struct msgbuf1 {
	long mtype;
	char mtext[512];
} sndbuf, *msgp;



int main()
{
	int msgid;
	key_t key;
	int msgflg;
	int rtn, msgsz;

	key = MSGKEY;
	msgflg = 00666 | IPC_CREAT;
	msgid = msgget( key, msgflg);
 	if ( msgid == -1) {
                perror("\n Az msgget rendszerh�v�s sikertelen!");
                exit(-1);
        }
	printf("\n Az msgid %d, %x : ", msgid, msgid);




	msgp = &sndbuf;
	msgp->mtype = 1;
 	strcpy(msgp->mtext,"Az egyik �zenet");
	msgsz = strlen(msgp->mtext) + 1;



    rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);
	printf("\n Az 1. msgsnd visszaadott %d-t", rtn);
	printf("\n A kik�ld�tt �zenet: %s", msgp->mtext);


	strcpy(msgp->mtext,"M�sik �zenet");
	msgsz = strlen(msgp->mtext) + 1;
	rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);
	printf("\n A 2.  msgsnd visszaadott %d-t", rtn);
	printf("\n A kik�ld�tt �zenet: %s \n", msgp->mtext);

	exit (0);
}
