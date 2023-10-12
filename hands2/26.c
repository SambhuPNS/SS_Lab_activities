#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>

int main()
{
	int msgid, size;
	key_t key;

	struct msg
	{
		long int mtype;
		char message[50];
	}mq;

	key = ftok(".", 'b');
	msgid = msgget(key, IPC_CREAT | 0744);

	printf("Enter message type : ");
       	scanf("%ld", &mq.mtype);	

	printf("Enter message : ");
	scanf(" %[^\n]", mq.message);

	size = strlen(mq.message);

	msgsnd(msgid, &mq, size+1, 0);

	return 0;
}
