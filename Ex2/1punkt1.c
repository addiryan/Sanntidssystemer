#include <stdio.h>
#include <sys/types.h>

int g = 0;

int main(){

	int local = 0;
	int i;
	pid_t pid = fork();

	for (i = 0; i < 10; i++){
	if (pid == 0){
		local++;
		g++;

		printf("Child process, %i, %i\n", g, local);
	}
	else if(pid > 0){
		local++;
		g++;
		printf("Parent process, %i, %i\n", g, local);
	}
	else {
		printf("Fork failed");
	}
	}
}