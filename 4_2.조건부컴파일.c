//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int value = 10;

#ifdef DEBUG
    printf("%d\n", value);
#endif
    /*
    DEBUG를 정의하지 않으면
    printf("%d\n", value);가 돌아가지 않는다.
    */
}

//2-------------------------------------------------
#include <stdio.h>

#define DEBUG //DEBUG정의했다.

int main(void)
{
    int value = 10;

#ifdef DEBUG
    printf("%d\n", value);
#endif
    /*
    DEBUG를 정의했으므로
    printf("%d\n", value);가 돌아간다.
    */
}

/*
조건부 컴파일
조건에 따라서 소스코드를 컴파일에 포함하거나 제외하는 기술
*/

//3-------------------------------------------------
#include <stdio.h>

#define VERSION 1000
#define DEBUG //DEBUG란 심볼을 정의만 하겠다.
#undef DEBUG  //DEBUG란 심볼을 정의하지 않겠다.

int main(void)
{
//1.
#ifdef DEBUG
    //DEBUG심볼이 정의되면 여기 수행
#else
    //DEBUG심볼이 정의되지 않았다면 여기 수행
#endif

//2.
#ifndef DEBUG
    //DEBUG심볼이 정의되지 않았다면 여기 수행
#endif

//3.
//심볼값조사
#if VERSION < 1000
    printf("Under 1000\n")
#elif VERSION == 100
    printf("1000\n");
#else
    printf("Upper 1000\n");
#endif

#if 0
이부분을 주석처리 하고싶다!
#endif
}

/*
정리

심볼만 정의
#define DEBUG
#undef DEBUG

심볼만 정의 조사방법
#ifdef
#ifndef

심볼값 정의
#define VERSION 1000

심볼값 정의 조사방법
#if
*/

/*
조건부 컴파일과 관련된 매크로
#if
#ifdef
#ifndef
#elif
#else
#endif
*/

/*
#if 0
주석대신 사용하는 개발자도 있다.
*/

//4-------------------------------------------------
#include <stdio.h>

#define DEBUG
#define VERSION 1000

int main(void)
{
#ifdef DEBUG
    printf("DEBUG MESSAGE\n");
#endif

#if VERSION == 1000
    printf("VERSION : 1000\n");
#endif
}

/*
매크로 심볼을 정의하는 방법

1.소스 코드에 정의
#define DEBUG
#define VERSION 1000

2.컴파일시에 컴파일러 옵션을 통해서 정의
gcc 4_3.매크로심볼정의.c -D DEBUG
gcc 4_3.매크로심볼정의.c -D DEBUG VERSION=1000

3.IDE환경을 사용하는 경우 매크로 심볼을 정의하는 메뉴가 있는 경우가 있다.
*/