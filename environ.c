#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
	char **env
	for (*env = environ; *env != NULL; env++)
	{
		printf("%s", *env);
	}

	return 0
}
