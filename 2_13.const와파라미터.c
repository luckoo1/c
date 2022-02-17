//1-------------------------------------------------
#include <stdio.h>

typedef struct RECT
{
    int left, top, right, bottom;
} RECT;

void foo(RECT r) //call by Value
{
}
//크기가 큰 구조체가 이렇게 넘어가면 복사본이 만들어져서
//메모리 사용에 좋지 않다.
int main(void)
{
    RECT r;
    foo(r);
}
//2-------------------------------------------------
#include <stdio.h>

typedef struct RECT
{
    int left, top, right, bottom;
} RECT;

void foo(RECT *r) //포인터로 보냈다.
{
    r->left = 10;
    //사용자가 이렇게 사용하면 원본이 수정되는 불상사가 발생한다
}

int main(void)
{
    RECT r;
    foo(&r);
}

//3-------------------------------------------------
#include <stdio.h>

typedef struct RECT
{
    int left, top, right, bottom;
} RECT;

void foo(const RECT *r) //원본이 수정되지 않는다
{
    r->left = 10; //error 발생
}

int main(void)
{
    RECT r;
    foo(&r);
}

/*
결론
함수인자로 크그가 큰 구조체를 전달할때는 "call by value"보다는
"상수를 가리키는 포인터"를 사용하는 것이 좋다.
*/