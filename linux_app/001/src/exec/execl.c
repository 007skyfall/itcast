#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	pid_t pid = fork();

	if (pid > 0)
	{
		execl("output", "output", NULL);
	}
	else if (pid == 0)
	{
		printf("i'm parent pid = %d\n", getpid());
	}

	return 0;
}
