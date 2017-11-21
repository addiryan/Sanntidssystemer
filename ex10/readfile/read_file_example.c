#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	printf("Reading from file example \n");
	int res;
	char buf[100];
	int fd = open("/dev/myresource", O_RDONLY);
	//int fd = open("/dev/myresource", O_RDONLY|O_NONBLOCK);
	res = read(fd, buf, 100);
	buf[res] = '\0';

	printf("Read: %s\n", buf);


	close(fd);
	return EXIT_SUCCESS;
}

