#ifndef FIFO__H

#include <pthread.h>

#define TRUE 1
#define FALSE 0

//fifo parameters
#define LENGTH 4
#define WIDTH 255



struct fifo_t {
	pthread_mutex_t resource_mutex;
	char fifo[LENGTH][WIDTH];
	int blocked_id[LENGTH];
	int blockedTail, blockedHead;
	int fifoTail, fifoHead;
	int status[LENGTH]; //status[i] = 1(data present) | 0 (cell empty)
};

typedef struct fifo_t fifo_t;

int init_fifo(fifo_t * fifo);

//adds a string to the fifo
int fifo_add_string(fifo_t *fifo,char array[WIDTH]);
//copys the next string into "string" and removes it from the fifo
void fifo_rem_string(fifo_t *fifo, char * string);

//adds a id to the blocked list
int fifo_add_blocked_id(fifo_t *fifo, int id);
//returns the next id from the blocked list
int fifo_rem_blocked_id( fifo_t* fifo);

//returns the status of the fifo, 0 = empty, 1 = non-empty
int fifo_status(fifo_t * fifo);

//prints the fifo list
void fifo_print(fifo_t *fifo);

//prints the blocked id list
void fifo_print_blocked_ids(fifo_t *fifo);







#endif
