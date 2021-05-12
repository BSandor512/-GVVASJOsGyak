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
} sndbuf, *msgp;		// �zenet buffer �s pointere

struct msqid_ds ds, *buf;




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


	msgp = &sndbuf;
	msgp->mtype = 1;
 	strcpy(msgp->mtext,"Az egyik �zenet");
	msgsz = strlen(msgp->mtext) + 1;

    rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);

	strcpy(msgp->mtext,"M�sik �zenet");
	msgsz = strlen(msgp->mtext) + 1;
	rtn = msgsnd(msgid,(struct msgbuf *) msgp, msgsz, msgflg);

if (msgp->mtext == "exit"){
    exit(0);
}


	key_t kulcs;
	int tipus;
	int meret;
	kulcs = MSGKEY;
	msgflg = 00666 | IPC_CREAT | MSG_NOERROR;

	msgid = msgget(kulcs, msgflg);
 	if ( msgid == -1) {
                perror("\n Az msgget rendszerh�v�s sikertelen!");
                exit(-1);
        }
	printf("\n Az �zenet ID: %d\n\n",msgid);

	msgp = &sndbuf;
	buf = &ds;
	meret = 20;
	tipus = 0;
	rtn = msgctl(msgid,IPC_STAT,buf);

	rtn = msgrcv(msgid,(struct msgbuf *)msgp, meret, tipus, msgflg);
	rtn = msgctl(msgid,IPC_STAT,buf);

do {
    printf("\n Choose from menu");
    printf("\n 0. Count of messages");
    printf("\n 1. Read a message");
    printf("\n 2. Cancel message");
    printf("\n 3. Exit\n");
    scanf("%d", &msgid);
  }while(msgid < 0 && msgid > 1);

  switch(msgid)
  {
    case 0:
        printf("\n Count of messages: %ld\n",buf->msg_qnum);
        break;

    case 1:
        printf("\n Sent message: %s\n", msgp->mtext);
        break;

    case 2:
        rtn = msgctl(msgid, IPC_RMID, NULL);
        printf("\n Message cancelled\n");
        break;

    case 3:
        exit(0);
  }
}
