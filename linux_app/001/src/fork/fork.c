#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int var = 34;

int main(int argc, const char *argv[])
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid > 0)
	{
		sleep(2);
		var = 55;
		printf("I'm parent pid = %d, parentID = %d, var = %d\n", getpid(), getppid(), var);
	}
	else if (pid == 0)
	{
		var = 100;
		printf("child  pid = %d, parentID=%d, var = %d\n", getpid(), getppid(), var);
	}

	printf("var = %d\n", var);

	return 0;
}
