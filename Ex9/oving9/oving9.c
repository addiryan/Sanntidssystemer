#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/dispatch.h>
#include <sys/mman.h>
#include <pthread.h>
#include <process.h>

void init_memlock();
void message_server();
int set_priority(int priority);
int get_priority();


struct pid_data{
	pthread_mutex_t pid_mutex;
	pid_t pid;
};

struct msg_info{
	pid_t pid;
	pid_t thread_ID;
	char fromClient[8];
};

struct pid_data *ptr;
struct msg_info receiveBuf;

char reply[12] = "Fuck You too";


int main(int argc, char *argv[]) {
	set_priority(35);
	init_memlock();
	ptr->pid = getpid();
	printf("PID is: %i\n", ptr->pid);
	message_server();

	//while(1);
	return EXIT_SUCCESS;
}


void message_server(){
	int channelID, messageID;
	channelID = ChannelCreate(0);
	while(1){
		printf("Server priority before receive is: %d\n", get_priority());
		messageID = MsgReceive(channelID, &receiveBuf, sizeof(receiveBuf), NULL);
		printf("Server priority after receive is: %d\n", get_priority());
		printf("Server received:  PID = %d, THREAD_ID = %d, text = %s\n", receiveBuf.pid, receiveBuf.thread_ID, receiveBuf.fromClient);
		MsgReply(messageID, EOK, &reply, sizeof(reply));
	}
}

void init_memlock(){
	int fileDesc, memSize;
	pthread_mutexattr_t myattr;

	fileDesc = shm_open("/sharedpid", O_RDWR|O_CREAT, S_IRWXU);
	memSize = ftruncate(fileDesc, sizeof(struct pid_data));
	ptr = mmap(0, sizeof(struct pid_data), PROT_READ|PROT_WRITE, MAP_SHARED, fileDesc, 0);
	pthread_mutexattr_init(&myattr);
	pthread_mutexattr_setpshared(&myattr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&ptr->pid_mutex, &myattr);

}

int set_priority(int priority)
{
	int policy;
	struct sched_param param;
	// check priority in range
	if (priority < 1 || priority > 63) return
	-
	1;
	// set priority
	pthread_getschedparam(pthread_self(), &policy, &param);
	param.sched_priority = priority;
	return pthread_setschedparam(pthread_self(),
	policy, &param);
}
int get_priority()
{
	int policy;
	struct sched_param param;
	// get priority
	pthread_getschedparam(pthread_self(), &policy, &param);
	return param.sched_curpriority;
}

