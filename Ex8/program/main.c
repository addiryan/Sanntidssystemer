#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]){

	int i;
	for (i = 0; i < 10; i++){
		printf("Print %d\n", i);
		usleep(1000000);
	}

	return 0;
}
