#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>



void *philosopher1(void *ptr);
void *philosopher2(void *ptr);
void *philosopher3(void *ptr);
void *philosopher4(void *ptr);
void *philosopher5(void *ptr);

volatile int global = 0;
pthread_mutex_t fork1;
pthread_mutex_t fork2;
pthread_mutex_t fork3;
pthread_mutex_t fork4;
pthread_mutex_t fork5;



int main(){

	
	pthread_t thread1, thread2, thread3, thread4, thread5;

	int i = 1;
	int j = 2;
	int k = 3;
	int z = 4;
	int y = 5;
	
	pthread_create(&thread1, NULL, philosopher1, (void*) &i);
	pthread_create(&thread2, NULL, philosopher2, (void*) &j);
	pthread_create(&thread3, NULL, philosopher3, (void*) &k);
	pthread_create(&thread4, NULL, philosopher4, (void*) &z);
	pthread_create(&thread5, NULL, philosopher5, (void*) &y);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	pthread_join(thread5, NULL);
	
}

void *philosopher1 (void *ptr){

	int *threadID = (int *)ptr;
	int i, j;
	while(1)
	{

		j = pthread_mutex_trylock(&fork1);

		i = pthread_mutex_trylock(&fork5);
		if((i == 0)&&(j == 0)){
			printf("ThreadID %d\n", *threadID);
			usleep(100000); 	
			pthread_mutex_unlock(&fork5);
			pthread_mutex_unlock(&fork1);
		}
		else {
			pthread_mutex_unlock(&fork5);
			//printf("Cannot eat 1 ");
			pthread_mutex_unlock(&fork1);
			
		}
		
	}
}

void *philosopher2 (void *ptr){
	int *threadID = (int *)ptr;
	int i, j;
	while(1)
	{

		j = pthread_mutex_trylock(&fork2);
		i = pthread_mutex_trylock(&fork5);
		if((i == 0)&&(j == 0)){
			printf("ThreadID %d\n", *threadID);
			usleep(100000); 	
			pthread_mutex_unlock(&fork1);
			pthread_mutex_unlock(&fork2);
		}
		else {
			pthread_mutex_unlock(&fork1);
			//printf("Cannot eat 2 ");
			pthread_mutex_unlock(&fork2);
		
		}
		
	}
}

void *philosopher3 (void *ptr){

	int *threadID = (int *)ptr;
	int i, j;
	while(1)
	{

		j = pthread_mutex_trylock(&fork3);
		i = pthread_mutex_trylock(&fork2);
		if((i == 0)&&(j == 0)){
			printf("ThreadID %d\n", *threadID);
			usleep(100000); 	
			pthread_mutex_unlock(&fork2);
			pthread_mutex_unlock(&fork3);
		}
		else {
			pthread_mutex_unlock(&fork2);
			//printf("Cannot eat 3 ");
			pthread_mutex_unlock(&fork3);
		
		}
	}
}

void *philosopher4 (void *ptr){

	int *threadID = (int *)ptr;
	int i, j;
	while(1)
	{

		j = pthread_mutex_trylock(&fork4);
		i = pthread_mutex_trylock(&fork3);
		if((i == 0)&&(j == 0)){
			printf("ThreadID %d\n", *threadID);
			usleep(100000); 	
			pthread_mutex_unlock(&fork3);
			pthread_mutex_unlock(&fork4);
		}
		else {
			pthread_mutex_unlock(&fork3);
			//printf("Cannot eat 4 ");
			pthread_mutex_unlock(&fork4);
		
		}
		
	}
}

void *philosopher5 (void *ptr){
	int *threadID = (int *)ptr;
	int i, j;
	while(1)
	{

		j = pthread_mutex_trylock(&fork5);
		i = pthread_mutex_trylock(&fork4);
		if((i == 0)&&(j == 0)){
			printf("ThreadID %d\n", *threadID);
			usleep(100000); 	
			pthread_mutex_unlock(&fork4);
			pthread_mutex_unlock(&fork5);
		}
		else {
			pthread_mutex_unlock(&fork4);
			//printf("Cannot eat 5 ");
			pthread_mutex_unlock(&fork5);
			
		}
		
	}
}


