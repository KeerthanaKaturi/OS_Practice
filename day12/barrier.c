#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_barrier_t barrier;
int a,b,c,d;
void *thread1(void *data)
{
    printf("Thread1 Init start\n");
    sleep(2);
    printf("Thread1 Init end\n");
    pthread_barrier_wait(&barrier);
    printf("Thread1 functionality start\n");
    a=10;
    printf("a = %d\n",a);
}
void *thread2(void *data)
{
    printf("Thread2 Init start\n");
    sleep(5);
    printf("Thread2 Init end\n");
    pthread_barrier_wait(&barrier);
    printf("Thread2 functionality start\n");
    b=5;
    printf("a+b = %d\n",a+b);
}
void *thread3(void *data)
{
    printf("Thread3 Init start\n");
    sleep(6);
    printf("Thread3 Init end\n");
    pthread_barrier_wait(&barrier);
    printf("Thread3 functionality start\n");
    c=1;
    printf("a+b+c = %d\n",a+b+c);
}
void *thread4(void *data)
{
    printf("Thread4 Init start\n");
    sleep(1);
    printf("Thread4 Init end\n");
    pthread_barrier_wait(&barrier);
    printf("Thread4 functionality start\n");
    d=2;
    printf("a+b+c+d = %d\n",a+b+c+d);
}
int main()
{
    pthread_t th1,th2,th3,th4;
    pthread_barrier_init(&barrier,NULL,4);

    pthread_create(&th1,NULL,thread1,NULL);
    pthread_create(&th2,NULL,thread2,NULL);
    pthread_create(&th3,NULL,thread3,NULL);
    pthread_create(&th4,NULL,thread4,NULL);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_join(th3,NULL);
    pthread_join(th4,NULL);

    pthread_barrier_destroy(&barrier);
    return 0;
}