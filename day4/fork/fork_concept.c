#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t id;
    printf("Before fork...\n PID = %d\t Parent ID = %d\n",getpid(),getppid());
    id = fork();
    printf("After fork...\n PID = %d\t Parent ID = %d",getpid(),getppid());
    printf("\ndummy process");
    if(id == 0)
    {
        printf("\nChild process    PID = %d   PPID = %d  Ret = %d",getpid(),getppid(),id);
    }
    else
    {
        printf("\nParent process   PID = %d   PPID = %d  Ret = %d",getpid(),getppid(),id);
    }
    printf("\ndummy1 process\n");
    return 0;
}