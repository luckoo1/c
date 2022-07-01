// 1-------------------------------------------------
// 3_7.배열을가리키는포인터활용.c 참고
/*
배열을 가리키는 포인터를 직접 사용하면 코드가 복잡해진다
typedef를 사용하면 코드의 가독성을 높일 수 있다
*/
#include <stdio.h>

int (*add_matrix(int (*p1)[2], int (*p2)[2]))[2]
{
    static int temp[2][2];
    temp[0][0] = p1[0][0] + p2[0][0];
    temp[1][0] = p1[1][0] + p2[1][0];
    temp[0][1] = p1[0][1] + p2[0][1];
    temp[1][1] = p1[1][1] + p2[1][1];

    return temp;
}

int main(void)
{
    int x[2][2] = {1, 2, 3, 4};
    int y[2][2] = {5, 6, 7, 8};

    int(*ret)[2] = add_matrix(x, y);
}

//2-------------------------------------------------

int n;  //변수 n
double d;//변수 d
int ar[2];//배열변수 ar
int (*p)[2];//배열을 가리키는 포인터 변수

//변수자리에 있는게 type로 바뀐다
typedef int n;
typedef double d;
typedef int ar[2];   //배열 타입
typedef int (*p)[2]; //배열을 가리키는 포인터 타입

int main(void)
{
    ar x = {1, 2}; //int x[2]={1,2}
    int x[3][2] = {1, 2, 3, 4, 5, 6};
}

/*
다양한 타입의 변수를 선언한다
변수 선언문 앞에 typedef를 붙이면 변수자리에 있던 심볼이 타입이 된다.
*/

//3-------------------------------------------------

typedef int AR[2];     //int[2]배열 타입
typedef int (*PAR)[2]; //int[2]배열을 가리키는 포인터 타입

int main(void)
{
    int x[3][2] = {1, 2, 3, 4, 5, 6};
    //아래 세줄은 동일하다.
    int(*p)[2] = x;
    AR *p2 = x; // AR* p2 = x; 모양으로 생각하자 VS자동들여쓰기 때문에 "AR *p2"가 된다.
    PAR p3 = x;
}

//4-------------------------------------------------
#include <stdio.h>

typedef int AR[2];     //배열 타입
typedef int (*PAR)[2]; //배열을 가리키는 포인터 타입

AR* add_matrix(AR* p1, AR* p2) // AR* add_matrix(AR* p1, AR* p2)
{
    static int temp[2][2];
    temp[0][0] = p1[0][0] + p2[0][0];
    temp[1][0] = p1[1][0] + p2[1][0];
    temp[0][1] = p1[0][1] + p2[0][1];
    temp[1][1] = p1[1][1] + p2[1][1];

    return temp;
}

int main(void)
{
    int x[2][2] = {1, 2, 3, 4};
    int y[2][2] = {5, 6, 7, 8};

    AR* ret = add_matrix(x, y); //수정
}

//5-------------------------------------------------

#include <stdio.h>

typedef int AR[2];     //배열 타입
typedef int (*PAR)[2]; //배열을 가리키는 포인터 타입

PAR add_matrix(PAR p1, PAR p2)
{
    static int temp[2][2];
    temp[0][0] = p1[0][0] + p2[0][0];
    temp[1][0] = p1[1][0] + p2[1][0];
    temp[0][1] = p1[0][1] + p2[0][1];
    temp[1][1] = p1[1][1] + p2[1][1];

    return temp;
}

int main(void)
{
    int x[2][2] = {1, 2, 3, 4};
    int y[2][2] = {5, 6, 7, 8};

    PAR ret = add_matrix(x, y); //수정
}