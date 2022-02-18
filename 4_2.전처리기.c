//매크로 분석시 전처리만 돌려보면 편하다
#include <stdio.h>

#define MAX 256
#define SQUARE(n) ((n) * (n)) 


int main(void)
{
    char name[MAX];

    int a = 3;
    int n2 = SQUARE(++a);
}

/*
매크로가 포함된 C/C++소스
"전처리에 의한 전처리"과정을 거침

매크로가 제거된 C/C++소스
"컴파일러에 의한 컴파일"과정을 거침

.obj/.o
"링커에 의한 링킹"과정을 거침

실행파일
*/

// gcc 4_2.전처리기.c -E
// gcc 4_2.전처리기.c -E > macro.txt

/*
위의 실행결과로 앞에 뭐가 많은건 #include<stdio.h>때문이다.
#include<stdio.h>지우면 더 깔끔하게 보일거다.

int main(void)
{
    char name[256];

    int a = 3;
    int n2 = ((++a) * (++a));
}
결과가 나옴을 확인
*/