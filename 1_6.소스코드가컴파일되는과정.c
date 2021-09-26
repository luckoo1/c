#include <stdio.h>

#define MAX 256

int main(void)
{
    char msg[MAX] = "Hello";

    printf("%s\n", msg);
}
//여기 파일명이 "hello.c"라고 가정하겠다

/*
1.매크로를 포함 소스코드
"gcc hello.c -E"하면 전처리(Preprocessor)과정을 거치게 된다.
"gcc hello.c -E"입력하면 전처리된 소스를 확인할 수 있다.
전처리과정을 거치면 매크로가 제거(치환)된 소스코드가 나온다.

2.매크로가 제거(치환)된 소스코드
"gcc hello.c -S"입력하면 컴파일(Compile)과정을 거치게 된다.
"gcc hello.c -S"입력하면 어셈블리 소스 코드가 나온다.

3.어셈블리 소스 코드(.ams/.s)_기계어코드
"gcc hello.c -c" 어셈블(Assemble)과정을 거치게 된다.
"gcc hello.c -c"입력하면 기계어로 된 목적 코드가 나온다.

4.기계어로 된 목적 코드(.obj,.o)
"gcc hello.o" 링킹(Linking)과정을 거치게된다.
"gcc hello.o"입력하면 "a.exe"라는 출력파일이 나온다.
 
5.실행 파일(.exe/a.out)

요즘은 3,4번을 합쳐서 컴파일한다고도 부른다.
*/