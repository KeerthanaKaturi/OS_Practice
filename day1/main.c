#include <stdio.h>
#include "arith.h"
#include "arith1.h"
int main()
{
    int sum = add(10,20);
    printf("sum = %d\n",sum);
    int diff = sub(10,20);
    printf("difference = %d\n",diff);
    int prod = mul(10,20);
    printf("product = %d\n",prod);
    int quo = div(20,10);
    printf("Quotient = %d\n",quo);
    return 0;
}