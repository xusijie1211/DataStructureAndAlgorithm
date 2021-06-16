#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	printf("start fork test\n");
	pid = fork();
	if (pid < 0) {
		printf("fork error: %s\n", strerror(errno));
	} else if (pid == 0) {
		printf("child ...\n");
		while (1) {
			printf("Hello, child.\n");
			sleep(1);
		}
	} else {
		printf("parent ...\n");
		while (1) {
			printf("Hello, parent.\n");
			sleep(2);
		}
	}
	return 0;
}
