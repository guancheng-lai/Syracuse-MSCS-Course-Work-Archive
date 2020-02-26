#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fd1 = fopen("./hw2.output", "w");
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0){
		fprintf(fd1, "Child");
		printf("Child");
	}
	else {
		fprintf(fd1, "Parent");
		printf("Parent");
	}
	return 0;
}
