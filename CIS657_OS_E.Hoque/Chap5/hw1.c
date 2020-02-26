#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int val = 100;
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0){
		val = 200;
		printf("Child = %d\n", val);
	}
	else {
		val = 300;
		printf("Parent = %d\n", val);
	}
	return 0;
}
