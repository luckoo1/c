//1-------------------------------------------------
#include <stdio.h>
int main(void)
{
    int n = 10;

    printf("%d\n", n);
    printf("%d\n", sizeof(n));
    printf("%p", &n);

    int *p = &n; //포인터 변수 p

    printf("%p\n", &p);
    printf("%p\n", p);
    printf("%d\n", *p);
    printf("%p\n", sizeof(p));
}

/*
그림필기1 참조
int n = 10;

printf("%d\n", n); //10
printf("%d\n", sizeof(n)); //4
printf("%p", &n); //0x1000(주소값)

int *p = &n;

printf("%p\n", &p); //0x2000(주소값) : p변수의 주소
printf("%p\n", p);  //0x1000(주소값) : 10의 주소
printf("%p\n", *p); //10 : p가 가리키는곳의 값을 출력
printf("%p\n", sizeof(p)); //32bit : 4, 64bit : 8
                           //포인터 변수(p)의 크기
*/

/*
정리
변수의 주소를 구하려면 "주소연산자(&)를 사용한다"
포인터 변수를 선언하려면 변수이름 앞에 "포인터연산자(*)"를 붙인다
포인터 변수가 가리키는 주소에서 값을 꺼내려면 "포인터 변수 dereference(*)"하면 된다
*/

//2-------------------------------------------------
//그림필기
#include <stdio.h>
int main(void)
{
    int n = 10;
    char c = 0;

    printf("%d\n", sizeof(n));
    printf("%d\n", sizeof(c));

    int *pn = &n;
    char *pc = &c;

    printf("%d\n", sizeof(pn));
    printf("%d\n", sizeof(pc));

    printf("%p, %p\n", pn, pn + 1);
    printf("%p, %p\n", pc, pc + 1);

    int *pn2 = pn + 1;

    printf("%d\n", pn2 - pn);
    printf("%d\n", pn2 - pn);
}
//3-------------------------------------------------
//출력값 확인

#include <stdio.h>
int main(void)
{
    int n = 10;
    char c = 0;

    printf("%d\n", sizeof(n)); //4
    printf("%d\n", sizeof(c)); //1

    int *pn = &n;
    char *pc = &c;
    /*
    모든 타입의 포인터 변수 크기는 동일하다
    32비트에서는 4바이트, 64비트에서는 8바이트
    */
    printf("%d\n", sizeof(pn)); //32bit : 4
    printf("%d\n", sizeof(pc)); //32bit : 4

    //포인터 변수의 값에 1을 더하면 "자신이 가리키는 대상체의 크기"만큼 증가
    printf("%p, %p\n", pn, pn + 1); //1000 1004
    printf("%p, %p\n", pc, pc + 1); //2000 2001

    int *pn2 = pn + 1; //pn2는 1004 pn1은 1000

    printf("%d\n", pn2 - pn); //4가 나올것 같지만 1이 나온다.
    //이 주소 사이에 대상체는 하나 들어갈 수 있다는 뜻으로 1이 나옴
    printf("%d\n", pn2 + pn); //error

    /*
    포인터-포인터=정수
    그래서 "printf("%d\n", pn2 - pn);"에서 %d를 썼다.

    pn2와 pn사이 대상체는 하나 들어갈수 있음을 표현한거라 생각
    포인터 변수끼리 '-'연산을 수행할 경우는 두 주소 사이에 있는 대상체의 개수가 나온다.
    포인터 변수끼리의 덧셈,곱셈,나눗셈 연산은 허용되지 않는다
    */
}

// 4-------------------------------------------------

//포인터와 정수의 연산
pn + 1; //포인터 + 정수 //Ok
pn - 1; //포인터 - 정수 //Ok
pn * 1; //포인터 * 정수 //NG
pn / 1; //포인터 / 정수 //NG

//포인터끼리의 연산
pn + pn2; //포인터 + 포인터 //NG
pn - pn2; //포인터 - 포인터 //OK
pn *pn2;  //포인터 * 포인터 //NG
pn / pn2; //포인터 / 포인터 //NG