#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0){
		printf("Child");
		wait(NULL);
	}
	else {
		int rc_wait = wait(NULL);
		printf("Parent waiting for %d", rc_wait);
	}
	return 0;
}
