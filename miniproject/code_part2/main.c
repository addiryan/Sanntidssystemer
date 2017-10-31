#include "client/miniproject.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <semaphore.h>


#define Kp 3
#define Ti 500
#define d 0.006
#define clockConstant 1000000
#define runtime 0.5

static struct udp_conn conn;

void* controllerFunc(void* ptr);
void* receiveFunc(void* ptr);
void* sendFunc(void* ptr);

static pthread_t controller;
static pthread_t receive;
static pthread_t sender;

pthread_mutex_t controlGet;
pthread_mutex_t controlGetAck;
pthread_mutex_t controlSet;
pthread_mutex_t controlSignal;

sem_t semControlY;
double set; 
double getAck; 
int setValid; 
int getAckValid; 
int getValid;
int signalValid;

int main(){

	void* ptr;

	sem_init(&semControlY, 0, 0);
	printf("Starting controller\n");

	if(udp_init_client(&conn, 9999, "192.168.0.1")){
		//Handle error
		printf("Cannot initialize connection\n");
		exit(1);
	}

	if(pthread_create(&receive, NULL, receiveFunc, (void*) ptr)){
		printf("Failed to create receive thread\n");
		exit(1);
	}
	if(pthread_create(&controller, NULL, controllerFunc, (void*) ptr)){
		printf("Failed to create controller thread\n");
		exit(1);
	}	
	if(pthread_create(&sender, NULL, sendFunc, (void*) ptr)){
		printf("Failed to create sender thread\n");
		exit(1);
	}


	char buf[125] = "START";
	udp_send(&conn, buf, 6);

	pthread_join(controller, NULL);
	//finished = 1;
	strcpy(buf, "STOP");
	udp_send(&conn, buf, 5);

	return 0;
}

void* sendFunc(void* ptr){

	while(1){

		int i = pthread_mutex_trylock(&controlGet);
		if(i == 0){
			if(getValid == 1){
				udp_send(&conn, "GET", 4);
				getValid = 0;
			}
			pthread_mutex_unlock(&controlGet);
		}

		int j = pthread_mutex_trylock(&controlSet);
		if(j == 0){			
			if(setValid == 1){
				char sendBuf[128];
				sprintf(sendBuf, "SET:%3.3f", set);
				udp_send(&conn, sendBuf, 12);
				setValid = 0;	
			}
			pthread_mutex_unlock(&controlSet);
		}

		int k = pthread_mutex_trylock(&controlSignal);
		if(k == 0){
			if(signalValid == 1){
				udp_send(&conn, "SIGNAL_ACK", 11);	
				signalValid = 0;				
			}	
			pthread_mutex_unlock(&controlSignal);		
		}
	}
	return 0;
}


void* controllerFunc(void* ptr){
	double e, r, y, u, integral = 0;
	struct timespec next, start, stop, wait;
	long sleeptime = clockConstant * d;
	long sleep;
	clock_gettime(CLOCK_REALTIME, &next);
	int iterations = 0;
	int numIterations = runtime / d;
	r = 1;
	
	printf("Number of iterations: %d\n", numIterations);
	while(iterations < numIterations){

		clock_gettime(CLOCK_REALTIME, &start);

		pthread_mutex_lock(&controlGet);
		getValid = 1;
		pthread_mutex_unlock(&controlGet);


		sem_wait(&semControlY);
		y = getAck;
	
		//Compute
		e = r - y;
		integral = integral + (e * d);
		u = Kp * e + Ti * integral;

		//Send out result
		pthread_mutex_lock(&controlSet);
		set = u;
		setValid = 1;		
		pthread_mutex_unlock(&controlSet);

		//Sleep
		clock_gettime(CLOCK_REALTIME, &stop);
		sleep = sleeptime - ((stop.tv_nsec - start.tv_nsec)/1000);

		if(sleep > 0){
			timespec_add_us(&next, sleep);
			clock_nanosleep(&next);
		}
		iterations++;	
	}
	return 0;
}

void* receiveFunc(void *ptr){
	char receiveBuf[128];

	char* command;

	while(1){

		udp_receive(&conn, receiveBuf, 128);

		if (strncmp(receiveBuf, "GET_ACK", 7) == 0) {
			command = strtok(receiveBuf, ":");
			getAck = atof(strtok(NULL, ":"));
			//Send y to controller func
			sem_post(&semControlY);

		} else if (strncmp(receiveBuf, "SIGNAL", 6) == 0) {
			pthread_mutex_lock(&controlSignal);
			signalValid = 1;
			pthread_mutex_unlock(&controlSignal);
			//Send signal to sendfunc
		}
	}
	return 0;
}

