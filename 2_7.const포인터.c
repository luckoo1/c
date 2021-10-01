//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n = 10;

    //c1과 c2는 완전히 동일
    const int c1 = 10;
    int const c2 = 10;

    int n = 10;
    //p1과 p2는 다르다
    const int *p1 = &n; //상수를 가리키는 포인터(Pointer To constant)
    int *const p2 = &n; //상수포인터(Constant 포인터)
    /*
    *를 기준으로 const의 위치를 조사

    const int *p1 = &n;
    p1자체는 const가 아닌데 나를 따라가보면 "const int"가 있다라는 뜻
    대상체가 const

    int *const p2 = &n;
    p2자체가 const인데 나를 따라가면 "int"가 있다라는 뜻
    포인터가 const
    */
}

//2-------------------------------------------------

int main(void)
{
    int n = 10;

    const int *p1 = &n; //상수를 가리키는 포인터
    int *const p2 = &n; //상수포인터

    int n2 = 10;

    p1 = &n2; //OK
    //p1자체는 바뀔 수 있다.
    *p1 = 20; //Error
    //p1을 따라가면 const가 있으니깐 값을 바꿀수 없다

    p2 = &n2; //Error
    //p2자체가 const
    *p2 = 20; //OK
    //p2를 따라간 곳은 int가 있다.
}

//3-------------------------------------------------

int main(void)
{
    int n = 10;

    const int *p1 = &n; //상수를 가리키는 포인터
    int *const p2 = &n; //상수포인터

    int const *p3 = &n;
    //*를 기준으로 const가 앞쪽에 있으니깐 "상수를 가리키는 포인터"가 된다
}