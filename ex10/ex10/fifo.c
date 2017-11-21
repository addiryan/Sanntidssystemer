#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "fifo.h"

char Empty[WIDTH]= "";
int init_fifo(fifo_t * fifo)
{
	int i;
	fifo->blockedHead = 0;
 	fifo->blockedTail = 0;
 	fifo->fifoHead = 0;
 	fifo->fifoTail = 0;
 	pthread_mutex_init(&(fifo->resource_mutex), NULL);
	
 
 	for (i = 0; i < LENGTH; i++)
 	{
 		strcpy(fifo->fifo[i],Empty);
 		fifo->blocked_id[i] = 0;
 		fifo->status[i] = 0;
 	}
	
		
	return TRUE;
}

int fifo_add_string(fifo_t *fifo,char array[WIDTH])
{
	if (!fifo->status[fifo->fifoTail])
	{
		memcpy(fifo->fifo[fifo->fifoTail], array,WIDTH);
		fifo->status[fifo->fifoTail] = 1;
		//printf("fifo_add_string: %s, Head: %i\n", array, fifo->fifoHead);
		if (fifo->fifoTail >= LENGTH-1)
		{
			fifo->fifoTail = 0;
		}
		else 
		{
			fifo->fifoTail++;
		}
		//printf("fifoTail = %i \n", fifo->fifoTail);

		return TRUE;
	}
	return FALSE;
}

void fifo_rem_string(fifo_t *fifo, char array[WIDTH])
{
	if (fifo->status[fifo->fifoHead])
	{
		memcpy(array, fifo->fifo[fifo->fifoHead],WIDTH);
		memcpy(fifo->fifo[fifo->fifoHead], Empty,WIDTH);
		fifo->status[fifo->fifoHead]=0;
	//	printf("fifo_rem_string: out: %s, next: %s Tail: %i \n", array, fifo->fifo[fifo->fifoHead],fifo->fifoTail);
		if (fifo->fifoHead >= LENGTH-1)
		{
			fifo->fifoHead = 0;
		}
		else 
		{
			fifo->fifoHead++;
		}
	//	printf("fifoHead = %i \n", fifo->fifoHead);

	}
}

int fifo_add_blocked_id(fifo_t *fifo, int id)
{
	if (fifo->blocked_id[fifo->blockedTail] == 0)
	{
		fifo->blocked_id[fifo->blockedTail] = id;
		if (fifo->blockedTail >= LENGTH-1) 
		{
			fifo->blockedTail = 0;
		} 
		else 
		{
			fifo->blockedTail++;
		}
		return TRUE;
	}
	return FALSE;
}

int fifo_rem_blocked_id(fifo_t * fifo)
{
	int temp;

	if (fifo->blocked_id[fifo->blockedHead] != 0)
	{	
		temp = fifo->blocked_id[fifo->blockedHead];
		fifo->blocked_id[fifo->blockedHead] = 0;
		if (fifo->blockedHead >= LENGTH-1) 
		{
			fifo->blockedHead = 0;
		}
		else
		{
			fifo->blockedHead++;
		}
		
		return temp;
	}
	return -1;
}

void fifo_print(fifo_t *fifo)
{
	int i;
	for (i = 0; i < LENGTH; i++)
	{
		printf("fifo[%i] = %s\n", i, fifo->fifo[i]);
	}
}

void fifo_print_blocked_ids(fifo_t *fifo)
{
	int i;
	for (i = 0; i < LENGTH; i++)
	{
		printf("blocked[%i] = %i\n", i, fifo->blocked_id[i]);
	}
}

int fifo_status(fifo_t * fifo)
{
	if (fifo->status[fifo->fifoHead] == 0){
		return 0;
	}
	else
	{
		return 1;
	}

}





