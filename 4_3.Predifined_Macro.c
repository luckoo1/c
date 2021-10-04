//1-------------------------------------------------
/*
미리 정의되어 있는 매크로들이 있다.

__FILE__
현재 컴파일 하는 파일의 이름

__LINE__
현재소스가 있는 곳의 줄번호

__STDC__
C표준을 따르는 컴파일러라면 1
*/

/*
C와 C++ 구별을 위해
C와 C++컴파일러는 __cplusplus라는 매크로를 정의하고 있다.
*/

/*
어떤 개발 환경인지 알려주기 위해 각 컴파일러마다 정의하는 매크로

OS를 구별하기 위해
Windows : _WIN32, WIN64
Linux : __linux__
MacOS : macintosh

컴파일러를 구별하기 위해
GCC : __GNUC__
Visual C++ : _MSC_VER
CLANG : __clang__
*/
#include <stdio.h>

int main(void)
{
    printf("complier is ");

#ifdef __GNUC__
    printf("gcc\n");
#endif

#ifdef _MSC_VER
    printf("cl\n");
#endif
}