#include <stdio.h>

int main(void)
{
    int n = 0x11223344; //그림필기
    int *p1 = &n;
    char *p2 = &n;
    short *p3 = &n;
    float *p4 = &n;

    printf("%p : %x\n", p1, *p1);
    printf("%p : %x\n", p2, *p2);
    printf("%p : %x\n", p3, *p3);
    printf("%p : %x\n", p4, *p4);
}

int main(void)
{
    int n = 0x11223344;
    int *p1 = &n;
    char *p2 = &n;
    short *p3 = &n;
    float *p4 = &n;

    printf("%p : %x\n", p1, *p1); //1000 11223344
    //4바이트 가져온다.
    printf("%p : %x\n", p2, *p2); //1000 44
    //한바이트만 가져온다
    printf("%p : %x\n", p3, *p3); //1000 3344
    //두바이트만 가져온다
    printf("%p : %x\n", p4, *p4); //1000 0.000000전혀없던값이 나온다
    //정수와 실수는 저장하는 방식이 다르다
}

/*
그림필기

p1~p4의 포인터 변수가 저장하는 메모리 주소는 모두 동일하다

하지만 동일한 주소의 메모리에 있는 데이터를 해석하는 방법은 다르다
int *p1 = &n;   //4바이트 크기의 정수
char *p2 = &n;  //1바이트 크기의 정수
short *p3 = &n; //2바이트 크기의 정수
float *p4 = &n; //4바이트 크기의 실수

일반적인 포인터 변수는 2가지 정보를 가지고 있디
1.메모리주소
2.메모리에 보관된 데이터에 대한 정보(크기,종류(실수/정수,signed/unsigned))

대상체의 주소는 메모리에 보관되지만, 데이터에 대한 정보는 별도로 저장되지는 않고
"컴파일할때 포인터 변수의 타입"을 통해서 알아낸다
*/

int main(void)
{
    int n = 0x11223344;
    int *p1 = &n;
    char *p2 = &n;
    short *p3 = &n;
    float *p4 = &n;
    //명시적 캐스팅
    int *p1 = &n;
    char *p2 = (char *)&n;
    short *p3 = (short *)&n;
    float *p4 = (float *)&n;
}

/*
변수의 주소를 다른 타입의 포인터 변수에 저장하는 것은?
메모리에 있는 "데이터를 해석하는 방식을 변경"하겠다는 의도
위험하므로 되도록 사용하지 않은 것이 좋다.
꼭 필요하다면 명시적 캐스팅을 사용하는 것이 좋다
char *p2 = (char*)&n;
short *p3 = (short*)&n;
float *p4 = (float*)&n;
이걸 보면 '아! 이사람은 실수가 아닌 의도구나!' 파악이 가능
C++은 명시적캐스팅안하면 error가 뜬다
C언어는 경고다
*/