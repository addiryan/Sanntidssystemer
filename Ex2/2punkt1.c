#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>



void *increment(void *ptr);

volatile int global = 0;

sem_t semaphore;

int main(){

	sem_init(&semaphore, 0, 3);
	pthread_t thread1, thread2, thread3, thread4, thread5;

	int i = 1;
	int j = 2;
	int k = 3;
	int z = 4;
	int y = 5;
	
	pthread_create(&thread1, NULL, increment, (void*) &i);
	pthread_create(&thread2, NULL, increment, (void*) &j);
	pthread_create(&thread3, NULL, increment, (void*) &k);
	pthread_create(&thread4, NULL, increment, (void*) &z);
	pthread_create(&thread5, NULL, increment, (void*) &y);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);
	
}

void *increment (void *ptr){
	int local = 0;
	int *threadID = (int *)ptr;
	
	while(1)
	{

		sem_wait(&semaphore);
		printf("ThreadID %d\n", *threadID);
		usleep(1000000); 	
		sem_post(&semaphore);	
		
	}
}



