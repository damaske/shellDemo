#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;

    if (stat("test.txt", &fileStat) == -1) 
    {
	    perror("stat");
	    return 1;
    }

    printf("size of file°: %ld\n", fileStat.st_size);
    return 0;
}
