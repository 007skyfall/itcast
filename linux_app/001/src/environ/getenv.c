#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char* my_getenv(const char *name)
{
	char *p = NULL;
	int i, len;

	for (i = 0; environ[i] != NULL; i++)
	{
		p = strstr(environ[i], "=");
		len = p - environ[i];
		if (strncmp(name, environ[i], len) == 0)
		{
			return p + 1;
		}
	}

	return NULL;
}

int main(int argc, const char *argv[])
{
	char *p = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage %s <env_var>\n", argv[0]);
		return -1;
	}

#if 1
	p = getenv(argv[1]);
#else
	p = my_getenv(argv[1]);
#endif

	if (p == NULL)
	{
		printf("there is no match\n");
	}
	else
	{
		printf("%s\n", p);
	}

	return 0;
}

