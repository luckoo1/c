#include <stdio.h>

#define MSG "Hello"
#define MAX 1000

int main(void)
{
    printf("%s\n", MSG);
    printf("%d\n", MAX);

    printf("%s\n", __FILE__);         //문자열 : 파일의 이름
    printf("%d\n", __LINE__);         //정수 : 줄번호
    printf("%s\n", __TIME__);         //문자열 : 현재시간
    printf("%s\n", __DATE__);         //문자열 : 날짜
    printf("%s\n", __func__);         //문자열 : 함수이름(c11 부터)
    printf("%d\n", __STDC__);         //정수 : 컴파일러가 C표준을 지원하면 1
    printf("%d\n", __STDC_VERSION__); //정수 : 컴파일러가 사용하는 "C언어의 버전"
}

/*
cl 컴파일러는 __STDC__를 사용하려면 /Za 옵션이 필요
cl 컴파일러는 __STDC_VERSION__를 제공하지 않음

gcc는 C표준을 엄격하게 지키는 편이고
cl은 C++ 컴파일이라서 C11에 추가된 기술을 지원하지 않는 경우도 있다.
*/