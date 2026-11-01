
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        // Child process
        for (int i = 1; i <= 10; i++)
        {
            printf("%d\n", i);
        }
    }
    else if (pid > 0)
    {
        // Parent process
        wait(NULL);
        printf("Parent process completed.\n");
    }
    else
    {
        printf("Fork failed!\n");
    }

    return 0;
}
