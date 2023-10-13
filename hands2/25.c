#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main()
{
	struct msqid_ds mq;
	struct ipc_perm perm;
	
	key_t key = ftok(".",'a');
	int msgid = msgget(key, 0);

	msgctl(msgid, IPC_STAT, &mq);
	perm = mq.msg_perm;

	printf("Access Permissions : %03o\n", perm.mode & 0777); 
	printf("UID : %d\n", perm.uid);
	printf("GID : %d\n", perm.gid);
	printf("Time of last message sent : %s", ctime(&mq.msg_stime));
	printf("Time of last message received : %s", ctime(&mq.msg_rtime));
	printf("Time of last change in the message queue : %s", ctime(&mq.msg_ctime));
	printf("Size of the queue : %lu\n", mq.msg_cbytes);
	printf("Number of messages in the queue : %ld\n", mq.msg_qnum);
	printf("Maximum number of bytes allowed : %lu\n", mq.msg_qbytes);
	printf("PID of last msg sent : %d\n", mq.msg_lspid);
	printf("PID of last msg received : %d\n", mq.msg_lrpid);
	
	return 0;
}
