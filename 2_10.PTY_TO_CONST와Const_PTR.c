#include <stdio.h>

int main(void)
{
    int n = 10;

    const int *p1 = &n;
    int *const p2 = &n;
    
    //c1과 c2는 동일
    const int c1 = 10;
    int const c2 = 10;
}

/*
*를 기준으로 const의 위치 조사

▣상수를 가리키는 포인터
const int *p1 = &n;
p1자체는 const가 아닌데 나를 따라가보면 const int가 있다.
즉 가리키는 대상체가 const

▣상수포인터
int *const p2 = &n;
p2자체가 const인데 나를 따라가면 int가 있다.
P2가 const
P2를 따라가면 int가 있다.
P2자체가 const
*/
// 2-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n = 10;

    const int *p1 = &n;
    int *const p2 = &n;

    //아래 코드를 생각해보자
    int n2 = 10;

    p1 = &n2;
    *p1 = 20;
    p2 = &n2;
    *p2 = 20;
}

/*
p1 = &n2; //OK p1자체는 const가 아니라서 바뀔 수 있다.
*p1 = 20; //NG P1을 따라가면 const int가 있으니 값을 바꿀 수 없다.
p2 = &n2; //NG P2자체는 const라서 바꿀 수 없다
*p2 = 20; //OK P2를 따라가면 int가 있으니 바꿀 수 있다.
*/

// 2-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int n = 10;

    const int *p1 = &n;
    int *const p2 = &n;

    int const *p3 = &n;
    /*
    const int *p1 = &n;
    int *const p2 = &n;
    둘중에 뭐랑 같을까?
    */
}

/*
int const *p3 = &n;
*기준으로 const가 앞에 있으니깐
const int *p1 = &n;와 같은거다.
*/

/*
정리
★포인터 변수 선언시 const해석 방법
포인터 연산자(*)를 기준으로 const의 위치가 왼쪽에 있는 경우
const int *p1;
int const *p1;
대상체가 const
상수를 가리키는 포인터

포인터 연산자(*)를 기준으로 const의 위치가 오른쪽에 있는 경우
int* const p2;
포인터 자체가 const
상수 포인터
*/