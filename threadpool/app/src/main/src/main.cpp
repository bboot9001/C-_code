#include "stdio.h"
#include "tools/tools.h"
int main()
{
    int a = 12, b = 34, c= 44 ,d = 22;
    int sum = add(a,b);
    printf("the sum %d + %d is:%d\n",a,b,sum);
    int s = sub(c,d);
    printf("the sub %d - %d is :%d\n",c,d,s);
    return 0;
}