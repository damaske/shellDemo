#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int i;
	char *args[] = {"ls", "-l", "/tmp", NULL};
	char *env[] = {NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("childfree");
			exit(1);
		}

		if (pid == 0)
		{
			printf("child number %d : doing ls -l /tmp\n", i + 1);
			if (execve("/bin/ls", args, env) == -1)
			{
				perror("can't change anyprocess");
				exit(1);
			}
		}
		else
		{
			wait(NULL);
			printf("child number %d ready\n", i + 1);
		}
	}
	printf("every child done\n");
	return (0);
}
