#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,const char* argv[])
{
    pid_t id;
    printf("Before fork\n");
    id = fork();
    if(0 == id)
    {
        printf("Child process\n");
    }
    else
    {
        printf("Parent process\n");
        sleep(10);
    }
    return 0;
}