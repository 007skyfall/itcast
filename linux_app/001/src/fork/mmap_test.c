#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
	int len;
	int fd = open("test.txt", O_RDWR | O_CREAT, 0664);
	//int fd = open("test.txt", O_RDWR);

	char *p = NULL;

    ftruncate(fd, 4);

	len = lseek(fd, 0, SEEK_END);

	p = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (p == MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}
	strcpy(p, "aaa");

	printf("%s\n", p);
	if (p)
	{
		munmap(p, len);
		p = NULL;
	}

	return 0;
}
