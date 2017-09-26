#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include "io.h"

int set_cpu(int cpu_number);
void *busyResponse(void *ptr);
void *disturbance(void *ptr);
void timespec_add_us(struct timespec *t, long us);
int main(){
	set_cpu(1);
	printf("\nInit\n");
	io_init();

	pthread_t A, B, C;
	pthread_t dist[10];
	int i = 1;
	int j = 2;
	int k = 3;
	pthread_create(&A, NULL, busyResponse, (void*) &i);
	pthread_create(&B, NULL, busyResponse, (void*) &j);
	pthread_create(&C, NULL, busyResponse, (void*) &k);
	int l;
	for(l = 0; l < 10; l++){
		pthread_create(&dist[l], NULL, disturbance, (void*) &l);
		pthread_join(dist[l], NULL);
	}
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
	struct timespec next;
	int *threadID = (int *)ptr;
	printf("Thread: %d\n", *threadID);
	set_cpu(1);
	while(1){
		clock_gettime( CLOCK_REALTIME, &next );
		timespec_add_us( &next, 100 );
		if(io_read(*threadID) == 0){
			io_write(*threadID, 1);
			clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next, NULL);
			io_write(*threadID, 0);
		} else{
			clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next, NULL);
		}
		
	}
}

void *disturbance(void *ptr){
	int i = 10; 
	int j = 1000;
	int k;
	set_cpu(1);
	while(1){
		k = j / i;
	}
}

void timespec_add_us(struct timespec *t, long us)
{
	// add microseconds to timespecs nanosecond counter
	t->tv_nsec += us*1000;

	// if wrapping nanosecond counter, increment second counter
	if (t->tv_nsec > 1000000000) {
		t->tv_nsec = t->tv_nsec-1000000000;t->tv_sec += 1;
	}
}