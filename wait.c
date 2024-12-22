#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	if (pid == 0)
	{
		printf("we are in child process and it is executing now\n");
		exit(0);
	}
	else 
	{
		printf("Daddy is waiting when child will finish.\n");
		wait(NULL);
		printf("Yuhuu! child finished!\n");
	}
	return (0);
}
