#include <stdio.h>

int main(void)
{
    int y[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    y;
    *y;
    **y;
    //위에 3개에대해 생각해보자.

    int(*p1)[2] = y;

    printf("%p\n",p1);

    int *p2 = *y;
    printf("%p\n",p2);

    int n = **y;

}