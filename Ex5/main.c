#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include "io.h"

int set_cpu(int cpu_number);
void *busyResponse(void *ptr);
void *disturbance(void * ptr);
int main(){
	//set_cpu(1);
	printf("\nInit\n");
	io_init();
	
	pthread_t A, B, C;
	int i = 1;
	int j = 2;
	int k = 3;
	pthread_create(&A, NULL, busyResponse, (void*) &i);
	pthread_create(&B, NULL, busyResponse, (void*) &j);
	pthread_create(&C, NULL, busyResponse, (void*) &k);

	pthread_join(A, NULL);
	pthread_join(B, NULL);
	pthread_join(C, NULL);
	printf("Init finished\n");
    //while(1){
        //io_write(1,1);
        //usleep(500000);
        //io_write(1,0);
        //usleep(500000);
    //}
    return 0;
}

int set_cpu(int cpu_number)
{
	// setting cpu set to the selected cpu
	cpu_set_t cpu;
	CPU_ZERO(&cpu);
	CPU_SET(cpu_number, &cpu);
	// set cpu set to current thread and return
	return pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpu);
}

void *busyResponse(void *ptr){
	
	int *threadID = (int *)ptr;
	//printf("Thread: %d\n", *threadID);
	//set_cpu(1);
	while(1){
		if(io_read(*threadID) == 0){
			io_write(*threadID, 1);
			usleep(1000);
			io_write(*threadID, 0);
		}
	}
}

void *disturbance(void *ptr){
	int i = 10, j = 0;
	while(1){
		i = i++
		j = j / i;
	}
}