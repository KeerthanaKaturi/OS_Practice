#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("desd.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    if(-1 == fd)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    write(fd,"hello desd\n",11);
    close(fd);
    return 0;
}