#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid = getpid();
    pid_t parent_pid = getppid();
    printf("PID = %d\n",pid);
    printf("Parent_PID = %d\n",parent_pid);
    return 0;
}