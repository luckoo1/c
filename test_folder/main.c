#include <stdio.h>
extern int num1; 
int main()
{
    printf("%d\n", num1);    // 전역 변수 num1의 값 출력. 컴파일 에러

    return 0;
}