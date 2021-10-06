//1-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int *p = 0;
    *p = 100; //runtime error
    //내가 지정한 메모리에 값을 넣으려고 했다.

    printf("%p\n", p);
}

//2-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int *p = 0;

    printf("%p\n", p);
    //내가 지정한 주소를 출력하려 한다
    //출력에는 지장이 없다. => 00000000
}

//3-------------------------------------------------
#include <stdio.h>

int main(void)
{
    int *p = (int *)1000;

    printf("%p\n", p);
    //내가 지정한 주소를 출력하려 한다
    //출력에는 지장이 없다. => 00000000
}

/*
할당되지 않은 임의의 메모리에
값을 읽거나 쓰는 것은 오류이다
하지만 메모리의 주소를 출력하는 것은 오류가 아니다.
*/

//4-------------------------------------------------
#include <stdio.h>

struct People
{
    char name[8];
    int age;
    int height;
};
typedef struct People PEOPLE;

int main(void)
{
    PEOPLE pe;
    printf("%p\n", &pe);       //0x1000
    printf("%p\n", &(pe.age)); //0x1008
    //메모리그림 그림필기 참조
    PEOPLE *p = 0;
    printf("%p\n", p); //0
    p->age = 10;       //runtime error(내가 지정한 메모리에 값을 넣으려고 했음)

    printf("%p\n", &(p->age)); //이건 에러일까? 몇번지를 출력을 할까?
}

/*
답은 8이 나온다
age가 people 구조체로 부터 8바이트 떨어져있다는 사실을 바로 알 수 있다.
*/

//4-------------------------------------------------
#include <stdio.h>

struct People
{
    char name[8];
    int age;
    int height;
};
typedef struct People PEOPLE;

int main(void)
{
    PEOPLE *p = 0;
    printf("%p\n", p);         //0
    printf("%p\n", &(p->age)); //8

    size_t n = (size_t) & (((PEOPLE *)0)->age);
    /*
    (PEOPLE *)0
    0번지지만 PEOPLE의 포인터로로 캐스팅해서 PEOPLE TYPE다

    ((PEOPLE *)0)->age
    이걸로 나이에 접근

    &(((PEOPLE *)0)->age)
    접근한것의 주소를 구해보자

    (size_t)&(((PEOPLE *)0)->age)
    unsigned int로 강제로 캐스팅해서 "size_t n"에 넣어보자
    */

    printf("%d\n", n); //8
}

/*
size_t n = (size_t) & (((PEOPLE *)0)->age);
즉 age가 people이라는 구조체에서 age가 얼마나 떨어져있는지 조사하는 거다.
*/

//5-------------------------------------------------
#include <stdio.h>

#define offsetof(TYPE, MEMBER) \
    (size_t) & (((TYPE *)0)->MEMBER);

struct People
{
    char name[8];
    int age;
    int height;
};
typedef struct People PEOPLE;

int main(void)
{
    PEOPLE *p = 0;
    size_t n = offsetof(PEOPLE, age);

    printf("%d\n", n);
}

/*
PEOPLE구조체에서 age가 얼마나 떨어져 있는지 알고 싶다.
*/

/*
offsetof 매크로
임의의 구조체 안에서 특정한 멤버가 어디에 위치했는지
(구조체의 시작 부분부터 몇 바이트 떨어진 곳에 있는지)을 알아내는 매크로 기술

<stddef.h>헤더 파일에서 C표준으로 제공한다.
*/

//5-------------------------------------------------
#include <stdio.h>
#include <stddef.h>

struct People
{
    char name[8];
    int age;
    int height;
};
typedef struct People PEOPLE;

int main(void)
{
    PEOPLE *p = 0;
    size_t n = offsetof(PEOPLE, age);

    printf("%d\n", n);
}

//일반화된(generic linked list)등을 사용할때 주로 사용