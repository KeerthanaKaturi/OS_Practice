#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t id;
    int fd[2];
    int k=10;
    char buff[128];
    pipe(fd);
    id = fork();
    if(0 == id)
    {
        close(fd[1]);
        read(fd[0],buff,128);
        printf("Child k =%d\n",k);
        printf("Parent sent: %s",buff);
        close(fd[0]);
    
    }
    else
    {
        close(fd[0]);
        write(fd[1],"desd\n",5);
        k=20;
        printf("Parent k =%d\n",k);
        close(fd[1]);
    }
    return 0;
}