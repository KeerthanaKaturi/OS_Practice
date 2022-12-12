#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
int main(int argc,const char* argv[])
{
    int fd_file1;
    int fd_file2;
    unsigned char buff[128];
    ssize_t nbytes_read;
    ssize_t nbytes_write;
    int ret_cls1;
    int ret_cls2;

    fd_file1 = open(argv[1],O_RDONLY);

    if(fd_file1 == -1)
    {
        printf("In the source file\n");
        printf("Error No. :: %d\n",errno);
        printf("Error");
        exit(EXIT_FAILURE);
    }
    nbytes_read = read(fd_file1,buff,128);

    fd_file2 = open(argv[2],O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(fd_file2 == -1)
    {
        perror("Destination File Error");
        exit(EXIT_FAILURE);
    }

    nbytes_write = write(fd_file2, buff, strlen(buff));
    if(nbytes_write == -1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    ret_cls1 = close(fd_file1);
    if(-1 == ret_cls1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    ret_cls2 = close(fd_file2);
    if(-1 == ret_cls2)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    return 0;
}