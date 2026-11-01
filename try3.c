
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    for (int i = 1; i <= 3; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            printf("Process %d PID: %d\n", i,
                   getpid());

            printf("Process %d Parent PID: %d\n",
                   i, getppid());
        }
        else if (pid > 0)
        {
            wait(NULL);
            break;
        }
        else
        {
            printf("Fork failed!\n");
            return 1;
        }
    }

    return 0;
}
