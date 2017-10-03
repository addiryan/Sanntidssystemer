#include <stdio.h>
#include "io.h"
#include <rtdk.h>
#include <native/task.h>
#include <native/timer.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sched.h>
#include <pthread.h>


#define NUMBEROFTASKS 3
#define TASKPRIORITY 50
#define SUCCESS 0
#define SLEEP 9000
#define NUMBEROFDISTURBANCETASKS 10


int set_cpu(int cpu_number);
static void task_function(void *ptr);
static void *disturbancefunction(void *ptr);

int main(){


	mlockall(MCL_CURRENT | MCL_FUTURE);

	RT_TASK tasks[NUMBEROFTASKS];

	int *chan;

	int ret = io_init();
	if(ret<1){
		rt_printf("io init failed");
		return 1;
	}
	rt_print_auto_init(1);
	int i;
	for (i = 0; i < NUMBEROFTASKS; i++){

		chan = malloc(sizeof(int));
		*chan = i+1;
		if(rt_task_create(&tasks[i], NULL, 0, TASKPRIORITY, 0) != SUCCESS){
			rt_printf("Failed to create RT-task\n");
			exit(1);
		} 

		if(rt_task_set_periodic(&tasks[i], TM_NOW, SLEEP) != SUCCESS){
			rt_printf("Failed to set periodic RT-task\n");
			exit(1);
		}

		if(rt_task_start(&tasks[i], task_function, chan) != SUCCESS){
			rt_printf("Failed to start RT-task\n");
			exit(1);
		}
	}


	if (NUMBEROFDISTURBANCETASKS > 0){
		int j;
		pthread_t disturbancethreads[NUMBEROFDISTURBANCETASKS];
		for(j = 0; j < NUMBEROFDISTURBANCETASKS; j++){
			if(pthread_create(&disturbancethreads[j], NULL, disturbancefunction, NULL) != SUCCESS){
				rt_printf("Failed to create disturbancethread");
				exit(1);
			}
		}

		for(j = 0; j < NUMBEROFDISTURBANCETASKS; j++){
			pthread_join(disturbancethreads[j], NULL);
		}
	}
	else{
		while(1){
			usleep(1000);
		}
	}

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


static void task_function(void *ptr){
	int threadID = *((int *) ptr);
	free(ptr);
	while(1){
		rt_task_wait_period(NULL);
		if(io_read(threadID) == 0){
			io_write(threadID, 1);
			usleep(5);
			io_write(threadID, 0);
		}
	}

	
}

static void *disturbancefunction(void *ptr){
	set_cpu(1);
	int i;
	while(1){
		i++;
		if(i>9000){
			i = 0;
		}
	}
	return 0;
}