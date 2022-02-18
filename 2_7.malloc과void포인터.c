// 3_1.배열을가리키는포인터.c 참고 
// 3_7.배열을가리키는포인터활용.c 참고

#include <stdio.h>
#include <stdlib.h>

    int
    main(void)
{
    malloc(40); //40바이트 할당

    malloc(sizeof(char) * 40);
    malloc(sizeof(int) * 10);
    malloc(sizeof(double) * 5);
    malloc(sizeof(short) * 10);
    /*
    위에 type를 적어줬지만 의미없다
    malloc(sizeof(int) * 10);
    여기서 인자로 int정보가 넘어가는건 아니다

    즉 위에 4줄은 그냥 다 같은의미다
    그냥 40바이트 크기만 할당한다.
    */
}

/*
1.
malloc함수는 데이터 타입에 대한 정보를 전달받지 않는다
malloc함수는 인자로 메모리 크기만을 전달 받는다

2.
malloc함수는 주소만 반환한다
malloc함수의 반환 타입은 void*이다(data type에 대한 정보가 없으니깐)
*/

//1-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void *p1 = malloc(40); //이런 형식으로 받는게 정확한 거다.
}

/*
malloc 함수가 할당한 메모리는 어떻게 사용할 것인가?
malloc함수가 반환한 주소는 사용자가 원하는 타입으로 캐스팅해서 사용한다.
*/
//2-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void *p1 = malloc(40); //이런 형식으로 받아야한다.

    char *p2 = (char *)malloc(sizeof(char) * 40);
    /*
    이렇게하면 char가 40개 있는거처럼 보이게 된다.
    (char *)malloc(sizeof(char) * 40);에서 (char *)빼도 되지만
    명시적으로 적어주는게 좋다고 계속 배워왔다.
    "char *p2 ="에서 char적는건 필수
    */
    int *p3 = (int *)malloc(sizeof(int) * 10);
    int *p4 = (int *)malloc(sizeof(double) * 5);
    /*
    위와같이 써도 무방하다
    40바이트 할당했는데 int 10개처럼 사용한다.
    하지만 가독성이 떨어지게 된다.
    */
}

//3-------------------------------------------------
//2차원 배열 할당

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //40바이트를 short의 2차원 배열 10*5
    short(*p5)[5] = (short(*)[5])malloc(sizeof(short) * 10);

    /*"short(*p5)[5]" 포인터 타입을 short의 2차원 배열로 적었다.
    "(short(*)[5])" 캐스팅을 위해 적었다.
    short[5] 배열을 가리키는 포인터다.

    short(*p5)[5]
    포인터연산을 먼저 적용할 수 있게 괄호를 사용했다
    "너는 포인터변수구나 그런데 short를 5개짜리 가리키는구나" 판단한다

    위의 경우는 "malloc(sizeof(short) * 10)"로 10byte공간을 할당했는데,
    그걸 "short(*)[5]"로 캐스팅했다.
    "short[5] 배열"을 가리키는 포인터
    그래서 총 10byte를 5개 공간에 넣은격이다.
    */
}