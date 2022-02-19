// 1-------------------------------------------------
#include <stdio.h>

int cnt = 0;
int get_wait_number(void)
{

    //int cnt = 0;
    ++cnt;
    return cnt;
}

int main(void)
{
    int n = get_wait_number();

    printf("%d\n", n);

    printf("%d\n", get_wait_number());
    cnt = 0;// 누가 여기서 초기화를 해버리면 내가 cnt를 늘릴려고 했던거에 오류가 발생한다.
    printf("%d\n", get_wait_number());
    printf("%d\n", get_wait_number());
}
//전역변수의 단점이다.(누구나 접근할수 있다는 사실때문에 위험하다.)
// 2-------------------------------------------------
#include <stdio.h>

int get_wait_number(void)
{
    static int cnt = 0;
    ++cnt;
    return cnt;
}

int main(void)
{
    int n = get_wait_number();

    printf("%d\n", n);

    printf("%d\n", get_wait_number());
    printf("%d\n", get_wait_number());
    printf("%d\n", get_wait_number());
}

/*
static 지역변수
함수호출이 종료되어도 메모리에서 파괴되지 않는다.
*/
/*
▣지역변수
수명 : 함수 종료시 파괴
가시성 : 함수 안에서만
▣static 지역 뱐수
수명 : 파괴안됨
가시성 : 함수안에서만
▣전역변수
수명 : 파괴안됨
가시성 : 모든함수에서
*/

// 3-------------------------------------------------