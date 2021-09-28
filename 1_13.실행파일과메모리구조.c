#if 0
#include <stdio.h>

int main(void)
{
    char s1[] = "Hello";
    //지역변수는 stack에 놓이게 된다.
    char *s2 = "Hello";
    /*
    stack에는 포인터변수가 놓이게 된다
    크기는 4바이트
    */
}
/*
그럼 포인터변수가 가리키는 "Hello"는 어디에 있을까?
s1의 "Hello"와 s2의 "Hello"의 차이는?
*/
#endif

#include <stdio.h>

int g1 = 0x11223344;
char g2[] = "abcdefg";

void foo(void)
{
    static int sx = 0xAABBCCDD;
    int lx = 0x55667788;
    printf("hello world\n");
}

int main(void)
{
    foo();
}
/*
그림필기
실행파일안에는 기계어코드로 들어있다.

실행파일 모양에 대해 좀더 살펴보자
*/