#include <stdio.h>

int main()
{
    
    int a = 1;
    int b = 2;

    printf("a : %d \t b : %d \n",a,b);

    int c = a;
    a = b;
    b = c;

    printf("a : %d \t b : %d",a,b);

    return 0;
}
