#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>



void *threadFunc1(void *ptr);
void *threadFunc2(void *ptr);

int running = 1;
int var1 = 0;
int var2 = 0;
pthread_mutex_t lock;


int main(){


	pthread_t thread1, thread2, thread3, thread4, thread5;
		
	pthread_create(&thread1, NULL, threadFunc1, NULL);
	pthread_create(&thread2, NULL, threadFunc2, NULL);
	

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	
}

void *threadFunc1 (void *ptr){		
	while(running)
	{
		pthread_mutex_lock(&lock);
		var1++;
		var2 = var1;		
		pthread_mutex_unlock(&lock);
	}
}

void *threadFunc2 (void *ptr){	

	int i;

	for(i = 0; i < 20; i++){
		printf("Number 1 is %i, number 2 is %i\n", var1, var2);
		usleep(100000);
		}
	running = 0;	
}