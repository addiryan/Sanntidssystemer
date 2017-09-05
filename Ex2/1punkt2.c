#include <stdio.h>
#include <pthread.h>



void *increment(void *ptr);

static int global = 0;

int main(){

	pthread_t thread1, thread2;
	int i = 1;
	int j = 2;
	pthread_create(&thread1, NULL, increment, (void*) &i);
	pthread_create(&thread2, NULL, increment, (void*) &j);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
}

void *increment (void *ptr){
	int local = 0;
	int *threadID = (int *)ptr;
	
	while(1)
	{
		global++;
		local++;
		printf("ThreadID: %d, Global: %i, Local: %i\n", *threadID, global, local);
	}
}



