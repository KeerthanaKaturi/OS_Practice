#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int count =0;
void *incThread(void *data)
{
    while(1)
    {
        count++;
        printf("Inc: %d\n",count);
    }
}
void *decThread(void *data)
{
    while(1)
    {
        count--;
        printf("Inc: %d\n",count);
    }
}
int main()
{
    pthread_t incId,decId;
    pthread_attr_t thread_attr;
    pthread_attr_init(&thread_attr);
    pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);
    pthread_create(&incId,&thread_attr,incThread,NULL);
    pthread_create(&decId,NULL,decThread,NULL);
    sleep(1);
    pthread_join(incId,NULL);
    pthread_join(decId,NULL);
    pthread_detach(incId);
    pthread_detach(incId);
    pthread_attr_destroy(&thread_attr);
    //pthread_exit(NULL);
    return 0;
}