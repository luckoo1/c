//그림필기 참조
#include <stdio.h>

int main(void)
{
    int n = 10;

    int *p1 = &n; //OK
    const int *p2 = &n; //OK

    const int c = 10;

    int *p3 = &c; //??
    const int *p4 = &c; //OK
}
/*
int *p3 = &c;
p3를 따라가면 int가 있을거야 라고 했는데 const int가 있다.
원본이 가지고 있는 특수함보다 더 많은 일을 하겠다고 하는거다
C에서는 경고 C++에는 Error
*/
//2-------------------------------------------------
#include <stdio.h>

int main(void)
{
    const int c = 10;

    int *p3 = (int*)&c; //OK
    const int *p4 = &c; //OK

    *p3 = 20;//이게 된다.
    /*그럼 C의 값이 20으로 바뀌게 되는건데
    위에서 const int c = 10;를 썼었잖아
    이런 코드를 사용하면 안된다!
    미정의 동작이다!
    */
}
/*
정리
int *p1 = &int; //OK
const int *p2 = &int; //Ok
int *p3 = &const int; //경고 또는 에러(명시적 캐스팅 필요)
const int *p4 = &const int; //OK

const 상수의 주소를 "비상수를 가리키는 포인터(int *)"로 명시적 캐스팅 할 수 있지만,
포인터를 사용해서 상수 값을 변경하는 코드를 사용하는 것은 좋지 않다.

*/