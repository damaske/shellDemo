#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
 
void fullname(char *filename)
{
    char *path;
    char full_path[1024];
    char path_copy[1024];
    int existence;
    path = getenv("PATH");
 
    if (!path)
    {
        perror("Error");
        return;
    }
    strcpy(path_copy, path);
    char* dir = strtok(path, ":");
    while (dir != NULL)
    {
        if (strlen(dir) + strlen(filename) + 2 > sizeof(full_path))
        {
            fprintf(stderr, "dumbass shorter name\n");
            continue;
        }
 
        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, filename);
 
        existence = access(full_path, X_OK);
        if (existence == 0)
        {
            printf("We did not shit ourselves bratan:\n %s\n", full_path);
            return;
        } else
        {
            fprintf(stderr, "not found or no permission: %s\n", full_path);
        }
 
        dir = strtok(NULL, ":");
    }
}
 
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        return EXIT_FAILURE;
    }
 
    for (int i = 1; i < argc; i++)
    {
        fullname(argv[i]);
    }
 
    return EXIT_SUCCESS;
}
