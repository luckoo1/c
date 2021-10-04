//1-------------------------------------------------
#include <stdio.h>

void Swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Sort(int *arr, int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (arr[i] < arr[j])
            {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main(void)
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    Sort(x, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", x[i]);
    }
}
/*
지금 코드는 10 9 8 7 6 5 4 3 2 1되는데
if (arr[i] < arr[j])에서 부등호 방향을 바꾸면
1 2 3 4 5 6 7 8 9 10이 된다
그런데 사용자가 Sort 함수안에서 부등호를 바꾸게 하기 싫다
*/

/*
라이브러리 설계시
변하지 않은 전체 흐름(알고리즘)안에 있는 
변해야 하는 부분(정책)은 분리한다.
*/

/*
C언어 함수에서 변하는 것을 분리하는 방법
변해야 하는 정책을 담는 함수를 인자로 전달한다.
*/
//2-------------------------------------------------
#include <stdio.h>

void Swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Sort(int *arr, int sz, int (*cmp)(int, int)) //변경
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (cmp(arr[i], arr[j]) > 0) //정책설정(이 정책을 만족해야 swap한다)
            {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}

int cmp1(int a, int b) { return a - b; }
int cmp2(int a, int b) { return b - a; }

int main(void)
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    Sort(x, 10, &cmp1);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", x[i]);
    }
}
/*
이 코드의 단점은 함수를 호출해야해서 성능의 저하가 생긴다.
유연성을 획득할수 있다.

inline int cmp
함수포인터에 담으면 inline치환도 안된다.

int x[10]에서 double도 사용하면 저 코드는 안돌아간다.
모든 타입에서 돌아가도록 수정해보자.
*/