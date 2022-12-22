#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *add(void *data)
{
    printf("Inside thread\n");
    int a = 10;
    int b = 20;
    int c = a+b;
    printf("Value of c = %d\n",c);
}
int main()
{
    pthread_t thread;
    printf("In main\n");
    printf("Before thread\n");
    pthread_create(&thread,NULL,add,NULL);
    pthread_join(thread,NULL);
    printf("After thread\n");
    return 0;
}