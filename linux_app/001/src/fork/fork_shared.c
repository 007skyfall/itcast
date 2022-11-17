#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* .data */
int a = 100;

int main(int argc, const char *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid == 0)
	{
		//son
		a = 2000;
		printf("child, a = %d\n", a);
	}
	else
	{
		sleep(1);	//保证son先运行
		printf("parent, a = %d\n", a);
	}

	return 0;
}
