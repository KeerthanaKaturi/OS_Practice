#include <stdio.h>
#include "arith.h"
int main()
{
    int sum = add(10,20);
    printf("sum = %d\n",sum);
    int diff = sub(10,20);
    printf("difference = %d\n",diff);
    return 0;
}