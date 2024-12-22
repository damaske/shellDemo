#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//int execve(const char *pathname, char *const argv[], char *const envp[]);

int main()
{
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *env[] = {NULL};

	if (execve("/bin/ls", args, env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}

	return (0);
}
