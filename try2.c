
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == 0)
    {
        printf("Child 1 PID: %d\n", getpid());
        printf("Child 1 Parent PID: %d\n", getppid());
        return 0;
    }

    pid2 = fork();

    if (pid2 == 0)
    {
        printf("Child 2 PID: %d\n", getpid());
        printf("Child 2 Parent PID: %d\n", getppid());
        return 0;
    }

    if (pid1 > 0 && pid2 > 0)
    {
        wait(NULL);
        wait(NULL);
        printf("Parent process PID: %d\n", getpid());
    }

    return 0;
}
