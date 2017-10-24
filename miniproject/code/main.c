#include "client/miniproject.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define Kp 8
#define Ti 1000
#define d 0.003
#define clockConstant 1000000
#define MaxWindup 10000
#define MinWindup -10000
#define runtime 0.5
static struct udp_conn conn;

void* controllerFunc(void* ptr);
void* receiveFunc(void* ptr);

//static pthread_t receive;
static pthread_t controller;

int main(){
	
	void* ptr;
	printf("Starting controller\n");

	if(udp_init_client(&conn, 9999, "192.168.0.1")){
		//Handle error
		printf("Cannot initialize connection");
		exit(1);
	}

	//pthread_create(&receive, NULL, receiveFunc, (void*) ptr);
	pthread_create(&controller, NULL, controllerFunc, (void*) ptr);


	char buf[128] = "START";
	//int size = sizeof(buf);
	udp_send(&conn, buf, 6);
	//buf = NULL;

	//pthread_join(receive, NULL);
	pthread_join(controller, NULL);
	strcpy(buf, "STOP");
	udp_send(&conn, buf, 6);

	return 0;
}

void* controllerFunc(void* ptr){
	double e, r, y, u, integral = 0;
	struct timespec next;
	long sleeptime = clockConstant * d;
	clock_gettime(CLOCK_REALTIME, &next);
	int iterations = 0;
	int numIterations = runtime / d;
	r = 1;
	char receiveBuf[128];
	char sendBuf[128];
	char* command;
	printf("Number of iterations: %d\n", numIterations);
	while(iterations < numIterations){	
		//Get variables
		udp_send(&conn, "GET", 4);
		udp_receive(&conn, receiveBuf, 128);
		if (strncmp(receiveBuf, "GET_ACK", 7) == 0) {
			command = strtok(receiveBuf, ":");
			y = atof(strtok(NULL, ":"));
			printf("\ny = %lf\n", y);
		}
		//Compute
		e = r - y;

		integral = integral + (e * d);
		
		if(integral > MaxWindup){
			integral = MaxWindup;
		}
		else if(integral < MinWindup){
			integral = MinWindup;
		}

		u = Kp * e + Ti * integral;

		//Send out result
		sprintf(sendBuf, "SET:%3.3f", u);
		printf(sendBuf);
		udp_send(&conn, sendBuf, 12);
		//Sleep

		timespec_add_us(&next, sleeptime);
		clock_nanosleep(&next);
		iterations++;
	}
	return 0;
}

void* receiveFunc(void *ptr){
	char receiveBuf[128];
	int received = 0;
	while(received < 10){
		udp_receive(&conn, receiveBuf, 128);
		received++;
		if (strncmp(receiveBuf, "GET_ACK", 7) == 0) {
			printf(receiveBuf);
		} else if (strncmp(receiveBuf, "SIGNAL", 6) == 0) {
			printf(receiveBuf);
			//udp_send(&conn, "")
		}
	}
	return 0;
}
