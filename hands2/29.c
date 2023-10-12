#include<sys/msg.h>
#include<stdio.h>

int main()
{
	int msgid;
	key_t key;

	struct msqid_ds mq;

	key = ftok(".", 'b');
	msgid = msgget(key, 0);

	msgctl(msgid, IPC_RMID, &mq);

	return 0;


}
