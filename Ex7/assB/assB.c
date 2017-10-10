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
#include <native/mutex.h>
#include <rtdk.h>
#include <sys/io.h>


#define NUMBEROFTASKS 3

RT_SEM semaphore;
RT_SEM resource;
RT_TASK tasks[NUMBEROFTASKS];
RT_MUTEX mutexResource;

void waitForSemaphore(void *ptr);
void syncTasks(void);
int rt_task_sleep_ms(unsigned long delay);
void print_pri(RT_TASK *task, char *s);
void busy_wait_ms(unsigned long delay);


int main(){

	rt_print_auto_init(1);

	mlockall(MCL_CURRENT|MCL_FUTURE);

	if(rt_sem_create(&semaphore, "sem", 0, S_PRIO)){
		rt_printf("Failed to create semaphore\n");
		exit(1);
	}

	/*if(rt_sem_create(&resource, "res", 1, S_PRIO)){
		rt_printf("Failed to create resource\n");
		exit(1);
	}
	*/

	rt_mutex_create(&mutexResource, "mutexResource");

	int *chan;

	int i;
	for(i = 0; i<NUMBEROFTASKS; i++){

		chan = malloc(sizeof(int));
		*chan = i+1;

		if(i == (NUMBEROFTASKS-1)){
			if(rt_task_create(&tasks[i], NULL, 0, 99, T_CPU(1))){
				rt_printf("Failed to create high prio task\n");
				exit(1);
			}
			if(rt_task_start(&tasks[i], &waitForSemaphore, chan)){
				rt_printf("Failed to start RT-task\n");
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
	usleep(2000000);

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

	if(threadID == 1){
		/*if(rt_sem_p(&resource, TM_INFINITE)){
			rt_printf("Failed to lock resource\n");
			exit(1);
		}
		*/
		rt_mutex_acquire(&mutexResource, TM_INFINITE);
		rt_printf("Low pri lock\n");
		busy_wait_ms(100);
		busy_wait_ms(100);
		busy_wait_ms(100);
		rt_printf("Low pri unlock\n");
		/*if(rt_sem_broadcast(&resource)){
			rt_printf("Failed to broadcast semaphore\n");
			exit(1);
		}
		*/
		rt_mutex_release(&mutexResource);

	}
	else if(threadID == 2){
		rt_printf("med pri start\n");
		rt_task_sleep_ms(100);
		busy_wait_ms(100);
		busy_wait_ms(100);
		busy_wait_ms(100);
		busy_wait_ms(100);
		busy_wait_ms(100);
		rt_printf("Medpri finish\n");
	}
	else if(threadID == 3){
		rt_printf("Highpri start\n");
		rt_task_sleep_ms(100);
		rt_task_sleep_ms(100);
		/*if(rt_sem_p(&resource, TM_INFINITE)){
			rt_printf("Failed to lock resource\n");
			exit(1);
		}
		*/
		rt_mutex_acquire(&mutexResource, TM_INFINITE);
		rt_printf("Highpri lock\n");
		busy_wait_ms(100);
		busy_wait_ms(100);
		rt_printf("Highpri unlock\n");
		/*if(rt_sem_broadcast(&resource)){
			rt_printf("Failed to broadcast semaphore\n");
			exit(1);
		}
		*/
		rt_mutex_release(&mutexResource);
	}
	else{
		rt_printf("ThreadID out of range");
		exit(1);
	}


	//rt_printf("Task %d finished\n", threadID);

}

void syncTasks(void){
	rt_printf("Broadcasting\n");
	if(rt_sem_broadcast(&semaphore)){
		rt_printf("Failed to broadcast semaphore\n");
		exit(1);
	}
	
}

int rt_task_sleep_ms(unsigned long delay){
	return rt_task_sleep(1000*1000*delay);
}

void print_pri(RT_TASK *task, char *s){
	struct rt_task_info temp;
	rt_task_inquire(task, &temp);
	rt_printf("b:%i c:%i ", temp.bprio, temp.cprio);
	rt_printf(s);
}

void busy_wait_ms(unsigned long delay){
	unsigned long count = 0;
	while (count <= delay*10){
		rt_timer_spin(1000*100);
		count++;
	}
}
