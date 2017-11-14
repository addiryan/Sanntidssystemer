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

void* init_memloc();
void message_client(void* i);
int set_priority(int priority);
int get_priority();

struct pid_data{
	pthread_mutex_t pid_mutex;
	pid_t pid;
};

struct message_info{
	pid_t pid;
	pid_t thread_ID;
	char toServer[8];
};

struct message_info sendMessage;
char receiveFromServer [12];
pid_t PID;

int main(int argc, char *argv[]) {
	//set_priority(35);
	struct pid_data* ptr;
	ptr = (struct pid_data*)init_memloc();
	const pthread_mutexattr_t myattr;
	pthread_mutexattr_init(&myattr);
	pthread_mutexattr_setpshared(&myattr, PTHREAD_PROCESS_SHARED);
	pthread_mutex_init(&ptr->pid_mutex, &myattr );
	printf("Server PID is: %d\n", ptr->pid);
	printf("Client PID is: %d\n", getpid());
	//message_client(ptr->pid);
	PID = ptr->pid;
	pthread_t threads[4];

	printf("Main threadID is: %d\n", gettid());
	int i;
	for (i=0; i<4; i++){
		pthread_create(&(threads[i]),NULL, message_client ,(void*) i);
	}

	for (i=0; i<4; i++){
		pthread_join(threads[i],NULL);
	}

	return EXIT_SUCCESS;
}

void message_client(void* i){
	//int threadNum = *((int *) i);

	int channelID;
	channelID = ConnectAttach(0, PID, 1, 0, 0);
	sendMessage.pid = getpid();
	sendMessage.thread_ID = gettid();
	set_priority(((int)sendMessage.thread_ID)*10);
	strcpy(sendMessage.toServer, "Fuck You");
	MsgSend(channelID, &sendMessage, sizeof(sendMessage), &receiveFromServer, sizeof(receiveFromServer));
	printf("Server responded with: %s\n", receiveFromServer);
	ConnectDetach(PID);
}

void* init_memloc(){
	int fileDesc;
	fileDesc = shm_open("/sharedpid", O_RDWR, S_IRWXU);
	//memSize = ftruncate(fileDesc, sizeof(struct pid_data));
	return mmap(0, sizeof(struct pid_data), PROT_READ|PROT_WRITE, MAP_SHARED, fileDesc, 0);
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
