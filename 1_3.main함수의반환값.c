#include <stdio.h>

int foo()
{
    //반환값이 없다.
}

int main(void)
{
    int n = foo();
    printf("Result : %d\n", n);
}

/*
▣반환값을 가지는 함수에서 값을 반환하지 않는 경우
에러가 아닌 경고(Warning)
gcc의 경우 -Wall옵션 사용시에만 경고 발생
gcc main.c -Wall
위에처럼 하면 확인이 가능하다.
foo의 반환값이 없다는 경고가 나온다.

/*
▣undefined behavior
컴파일시 에러는 없지만 실행 시 결과는 표준에서 정의하지 않는 것
컴파일러마다 다른 결과가 나올 수 있다.
결과를 보면 gcc는 1이나오고 cl은 14023688(이상한 값)나온다

▣Well Defined Behavior
main함수에서 값을 반환하지 않는 경우
자동으로 0이 반환된다.
C/C++표준에서 정의한 동작
"return 0;"을 생략해도 된다.
gcc main.c -Wall
경고가 main에서 나오지 않는다.
*/