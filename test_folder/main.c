//1-------------------------------------------------
#include <stdio.h>
int main(void)
{
    int n = 10;

    printf("%d\n", n);
    printf("%d\n", sizeof(n));
    printf("%p", &n);

    int *p = &n; //포인터 변수 p

    printf("%p\n", &p);
    printf("%p\n", p);
    printf("%d\n", *p);
    printf("%p\n", sizeof(p));
}