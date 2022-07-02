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
