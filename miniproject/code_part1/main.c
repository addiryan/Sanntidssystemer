#include "client/miniproject.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define Kp 5
#define Ti 900
#define d 0.004
#define clockConstant 1000000
#define MaxWindup 15
#define MinWindup -15
#define runtime 0.5
static struct udp_conn conn;

void* controllerFunc(void* ptr);


static pthread_t controller;

int main(){
	
	void* ptr;
	printf("Starting controller\n");

	if(udp_init_client(&conn, 9999, "192.168.0.1")){
		//Handle error
		printf("Cannot initialize connection");
		exit(1);
	}


	pthread_create(&controller, NULL, controllerFunc, (void*) ptr);

	char buf[128] = "START";
	udp_send(&conn, buf, 6);

	pthread_join(controller, NULL);
	strcpy(buf, "STOP");
	udp_send(&conn, buf, 6);

	return 0;
}

void* controllerFunc(void* ptr){
	double e, r, y, u, integral = 0;
	struct timespec next, start, stop;
	long sleeptime = clockConstant * d;
	long sleep;
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
		clock_gettime(CLOCK_REALTIME, &start);
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
		clock_gettime(CLOCK_REALTIME, &stop);
		sleep = sleeptime - ((stop.tv_nsec - start.tv_nsec)/1000);
		timespec_add_us(&next, sleep);
		clock_nanosleep(&next);
		iterations++;
	}
	return 0;
}

