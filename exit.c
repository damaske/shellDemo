//void exit(int status);

#include <stdlib.h>
#include <stdio.h>

int main() {
    
	printf("Starting program...\n")
		
		if (1)
		{
			fprintf(stderr, "An error occurred.\n");
			exit(EXIT_FAILURE); //exit(1)
		}

    printf("This will not be printed.\n");
    exit(EXIT_SUCCESS); //exit(0)
}

