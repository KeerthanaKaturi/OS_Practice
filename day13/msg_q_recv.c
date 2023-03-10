#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

#define BUFF_SIZE 64
char buff[BUFF_SIZE];
struct mq_attr desd_mq_attr;
int main()
{
    mqd_t desd_mq_desc;
    int mq_sd_er,mq_close_er,mq_r;
    desd_mq_attr.mq_flags = 0;
    desd_mq_attr.mq_maxmsg = 4;
    desd_mq_attr.mq_msgsize = 64;
    desd_mq_attr.mq_curmsgs = 0;

    desd_mq_desc = mq_open("/desd_mq",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,&desd_mq_attr);
    if(-1 == desd_mq_desc)
    {
        perror("Error: mq_open\n");
        exit(EXIT_FAILURE);
    }
    mq_sd_er = mq_receive(desd_mq_desc,buff,64,0);
    if(-1 == mq_sd_er)
    {
        perror("Error: mq_receive\n");
        exit(EXIT_FAILURE);
    } 
    printf("Rcvd msg: %s\n",buff); 
    mq_close_er = mq_close(desd_mq_desc);
    if(-1 == mq_close_er)
    {
        perror("Error: mq_close\n");
        exit(EXIT_FAILURE);
    } 
    return 0;
}