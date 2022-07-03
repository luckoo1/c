//1-------------------------------------------------
#include <stdio.h>

#define PRESS_ENTER_KEY()      \
    printf("press enter key"); \
    getchar();

int main(void)
{
    PRESS_ENTER_KEY();
    printf("end main\n");
}
/*
여러 문장을 하나의 매크로로 치환하려면
문장의 끝에 "Backslash(\)"를 표기한다
마지막문장에는 Backslash를 표기하지 않는다
Backslash 뒤에 공백등의 문자가 있는 경우 에러가 발생하는 경우가 있다.
*/

// 2-------------------------------------------------
//if문에서 사용시 버그 발생할수 있다.
#include <stdio.h>

#define PRESS_ENTER_KEY()      \
    printf("press enter key"); \
    getchar();

int main(void)
{
    if (0)
        PRESS_ENTER_KEY()
    printf("end main\n");
}
//위의 코드에서 바로 end main이 바로 나오지 않고 엔터 눌러야지 나온다.
//즉 if(0)이 작동을 안하는 거다.


/*
전처리를 해보면
============================
if (0)
    printf("press enter key"); getchar();
printf("end main\n");
============================
중괄호가 없으니깐 한문장(printf("press enter key");만 if문에 들어가는 것이 된다.

결국에는
============================
if (0)
    printf("press enter key");

getchar();
printf("end main\n");
============================
이런모양이 된다.
*/

//3-------------------------------------------------
//매크로를 if문에서 사용하려면 전체문장을 {}로 묶어라
#include <stdio.h>

#define PRESS_ENTER_KEY()          \
    {                              \
        printf("press enter key"); \
        getchar();                 \
    }

int main(void)
{
    if (0)
        PRESS_ENTER_KEY();
    printf("end main\n");
}

//3-------------------------------------------------
//그런데 if~else문에서 사용시 에러가 발생
#include <stdio.h>

#define PRESS_ENTER_KEY()          \
    {                              \
        printf("press enter key"); \
        getchar();                 \
    }

int main(void)
{
    if (0)
        PRESS_ENTER_KEY();
    else
    {
    }

    printf("end main\n");
}
/*
전처리를 해보면
============================
if (0)
{
    printf("press enter key");
    getchar();
};
else
{

}
============================
와 같이 }위에 ;가 있다.
*/

//4-------------------------------------------------
#include <stdio.h>

#define PRESS_ENTER_KEY()          \
    do                             \
    {                              \
        printf("press enter key"); \
        getchar();                 \
    } while (0)

int main(void)
{
    if (0)
        PRESS_ENTER_KEY();
    else
    {
    }

    printf("end main\n");
}

/*
============================
if (0)
    do
    {
        printf("press enter key");
        getchar();
    } while (0);
else
{

}
============================
while(0)뒤에 ;가 붙게했다.
*/

/*
do~ while(0)매크로
if~else 구문에서도 문제없이 사용할 수 있다.
오픈소스에서 많이 사용되는 대표적인 기술
*/