#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sched.h>
#include <pthread.h>
#include <native/task.h>
#include <native/timer.h>
#include <native/sem.h>
#include <rtdk.h>
#include <sys/io.h>


#define NUMBEROFTASKS 3

RT_SEM semaphore;
RT_TASK tasks[NUMBEROFTASKS];

void waitForSemaphore(void *ptr);
void syncTasks(void);

int main(){

	rt_print_auto_init(1);

	mlockall(MCL_CURRENT|MCL_FUTURE);

	if(rt_sem_create(&semaphore, "sem", 0, S_PRIO)){
		rt_printf("Failed to create semaphore\n");
		exit(1);
	}

	int *chan;

	int i;
	for(i = 0; i<NUMBEROFTASKS; i++){

		chan = malloc(sizeof(int));
		*chan = i+1;

		if(i == (NUMBEROFTASKS-1)){
			if(rt_task_shadow(&tasks[i], NULL, 99, T_CPU(1))){
				rt_printf("Failed to convert main to shadow task\n");
				exit(1);
			}
		}
		else{

			if(rt_task_create(&tasks[i], NULL, 0, i, T_CPU(1))){
				rt_printf("Failed to create RT-task\n");
				exit(1);
			}

			if(rt_task_start(&tasks[i], &waitForSemaphore, chan)){
				rt_printf("Failed to start RT-task\n");
				exit(1);
			}
		}
	}

	usleep(100000);
	syncTasks();
	usleep(100000);

	if(rt_sem_delete(&semaphore)){
		rt_printf("Failed to delete semaphore\n");
		exit(1);
	}
	rt_printf("Exit with success!\n");
	return 0;
}

void waitForSemaphore(void *ptr){
	int threadID = *((int *) ptr);
	free(ptr);

	if(rt_sem_p(&semaphore, TM_INFINITE)){
		rt_printf("Failed to wait for semaphore\n");
		exit(1);
	}

	rt_printf("Task %d finished\n", threadID);

}

void syncTasks(void){
	rt_printf("Broadcasting\n");
	if(rt_sem_broadcast(&semaphore)){
		rt_printf("Failed to broadcast semaphore\n");
		exit(1);
	}
	
}