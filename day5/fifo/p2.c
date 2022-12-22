#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,const char* argv[])
{
    int fd = 0;
    unsigned char buff[128];
    fd = open("desdfifo",O_RDONLY);
    read(fd,buff,128);
    //read(fd,"DESD-FIFO\n",10);
    printf("Received: %s\n",buff);
    close(fd);
    return 0;
}
