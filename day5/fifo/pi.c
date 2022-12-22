#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,const char* argv[])
{
    int fd = 0;
    unsigned char buff[128];
    fd = open("desdfifo",O_WRONLY);
    write(fd,"DESD-FIFO\n",10);
    close(fd);
    return 0;
}
