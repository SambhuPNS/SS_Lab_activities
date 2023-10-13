#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct msqid_ds mq;
	key_t key = ftok(".", 'a');
	int msgid = msgget(key, 0);
	msgctl(msgid, IPC_STAT, &mq);
	mq.msg_perm.mode = 0644;

	int msgset = msgctl(msgid, IPC_SET, &mq);
	if(msgset == -1)
	{
		perror("Unable to change permissions ");
		exit(0);
	}
	return 0;
}
