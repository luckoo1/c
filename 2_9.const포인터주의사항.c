//그림필기 참조
#include <stdio.h>

int main(void)
{
    int n = 10;

    int *p1 = &n; //OK
    const int *p2 = &n; //OK
    /*
    나를 따라가면 const int가 있을건데,
    읽기만 할거니깐 문제없다고 2_8에서 배움
    */

    const int c = 10;

    const int *p4 = &c;
    /*
    원본도 const int
    따라가도 const int니깐 문제가 없다.
    */

    int *p3 = &c; //??
}
/*
int *p3 = &c;
p3를 따라가면 int가 있을거야 라고 했는데 const int가 있다.
원본이 가지고 있는 특수함보다 더 많은 일을 하겠다고 하는거다
p3를 통해서 c에 주소에 담긴 값을 바꿀거야 라는 의미가 될수도 있으니 위험
C에서는 경고 C++에는 Error
*/
//2-------------------------------------------------
#include <stdio.h>

int main(void)
{
    const int c = 10;

    int *p3 = (int*)&c; //OK
    /*
    너는 const int였지만 명시적 캐스팅으로 강제로 int로 바꿀래!
    되긴한다.
    */

    *p3 = 20;//이게 된다.
    /*
    그럼 C의 값이 20으로 바뀌게 되는건데
    위에서 const int c = 10;를 썼었잖아
    이런 코드를 사용하면 안된다!
    print("%d",c); 뭐나오지..?
    미정의 동작이다! C표준에도 없다.
    */
}
/*
정리
int *p1 = &int; //OK
const int *p2 = &int; //Ok(원본은 읽고쓰기 다 할수 있는데 접근은 읽기만 하겠다.)
int *p3 = &const int; //경고 또는 에러(명시적 캐스팅 필요)
const int *p4 = &const int; //OK

const 상수의 주소를 "비상수를 가리키는 포인터(int *)"로 명시적 캐스팅 할 수 있지만,
포인터를 사용해서 상수 값을 변경하는 코드를 사용하는 것은 좋지 않다.
*/