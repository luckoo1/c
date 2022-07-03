#include <stdio.h>
#include "6_3.add.h"

int main()
{
    int ret= add(1,2);
    printf("%d\n",ret);
}

/*
헤더파일
함수의 선언부를 제공하기 위해 만드는 파일
*/
/*
int add(int a,int b);
int main()
{
    int ret= add(1,2);
    printf("%d\n",ret);
}
전처리에서 이렇게 나옴을 볼수 있다.
#include "6_3.add.h"에 치환됨이라 생각하자
*/