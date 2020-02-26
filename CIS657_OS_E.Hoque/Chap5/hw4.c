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
		char * args[3];
		args[0] = strdup("/bin/ls");
		args[1] = NULL;
		args[2] = NULL;
		execvpe(args[0], args);
	}
	else {
		printf("Parent");
	}
	return 0;
}
