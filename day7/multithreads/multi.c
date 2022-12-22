#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *add(void *data)
{
    printf("Inside thread1\n");
    int a = 10;
    int b = 20;
    int c = a+b;
    //sleep(10);
    printf("Value of sum = %d\n",c);
}
void *sub(void *data)
{
    printf("Inside thread2\n");
    int a = 10;
    int b = 20;
    int c = a-b;
    sleep(10);
    printf("Value of diff = %d\n",c);
}
void *mul(void *data)
{
    printf("Inside thread3\n");
    int a = 10;
    int b = 20;
    int c = a*b;
    printf("Value of product = %d\n",c);
}
void *div(void *data)
{
    printf("Inside thread4\n");
    int a = 40;
    int b = 20;
    int c = a/b;
    sleep(10);
    printf("Value of quotient = %d\n",c);
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;
    printf("In main\n");
    printf("Before threads\n");
    pthread_create(&thread1,NULL,add,NULL);
    pthread_create(&thread2,NULL,sub,NULL);
    pthread_create(&thread3,NULL,mul,NULL);
    pthread_create(&thread4,NULL,div,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_join(thread4,NULL);
    printf("After threads\n");
    return 0;
}