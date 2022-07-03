#include <stdio.h>

int add(int a,int b); //함수의 선언부가 필수적으로 있어야 한다.

int main()
{
    int ret= add(1,2);
    printf("%d\n",ret);
}

/*
gcc 6_2.maic.c 6_2.add.c
동시에 해야한다.
*/

/*
다른 파일에 있는 함수를 호출하려면 함수선언부가 있어야한다.
*/