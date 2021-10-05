//include guards 기술

//1-------------------------------------------------
//Point1.h ***********************
struct _Point
{
    int x;
    int y;
};
typedef struct _Point POINT;

//include_guard.c ***********************
#include "Point1.h"
#include "Point1.h"
/*
두번포함하면 error뜬다
어떤 헤더가 다른 헤더 포함하고 또 다른헤더가 이 헤더 포함하다가
즉, 헤더끼리 여러번 포함하다보면 두번 포함할수도 있다.

똑같은 이름의 구조체를 2번 만든격이 되었기 때문이다.
*/
int main(void)
{
    POINT pt;
}

//2-------------------------------------------------

//Point1.h ***********************
#ifndef POINT1_H
#define POINT1_H
struct _Point
{
    int x;
    int y;
};
typedef struct _Point POINT;
#endif

//include_guard.c ***********************

#include "Point1.h"
#include "Point1.h"

int main(void)
{
    POINT pt;
}

/*
다양한 이유로 헤더 파일이 2번 포함될 경우 문제를 해결하기 위한 조건부
#ifndef 파일이름
#define 파일이름
..................
#endif
충돌 방지를 위해 파일이름 쓰는게 좋다
*/

//3-------------------------------------------------

//Point2.h ***********************
#pragma once //이 헤더파일은 한번만 포함되어야함을 알려주는 것
//표준이 아니다(사용은 회사 내부정책에 따라라)
struct _Point
{
    int x;
    int y;
};
typedef struct _Point POINT;

//include_guard.c ***********************

#include "Point2.h"
#include "Point2.h"

int main(void)
{
    POINT pt;
}
