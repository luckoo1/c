//1-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p1 = (int *)malloc(sizeof(int) * 10);
    int *p2 = (int *)malloc(sizeof(int) * 10);
    int *p3 = (int *)malloc(sizeof(int) * 10);

    free(p1);
    free(p2);
    free(p3);
}
//free를 재대로 활용하지 못하면 메모리 누수현상이 생긴다.
//메모리 해지를 자동으로 해주는 프로그램을 만들어보자.

//2-------------------------------------------------
//아래와 같은 방식으로 해결하려 했다.
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

void *debug_malloc(size_t sz)
{
    void *p = malloc(sz);
    ++cnt; //메모리 할당하고 cnt++해줌
    printf("debug_malloc\n");
    return p;
}

void debug_free(void *addr)
{
    free(addr);
    printf("debug_free\n");
    --cnt;
}

int main(void)
{
    int *p1 = (int *)debug_malloc(sizeof(int) * 10);
    int *p2 = (int *)debug_malloc(sizeof(int) * 10);
    int *p3 = (int *)debug_malloc(sizeof(int) * 10);

    debug_free(p1);
    debug_free(p2);
    debug_free(p3);
}
//cnt를 통해 관리하려고 했음

//3-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

void *debug_malloc(size_t sz)
{
    void *p = malloc(sz);
    ++cnt;
    printf("debug_malloc\n");
    return p;
}

void debug_free(void *addr)
{
    free(addr);
    printf("debug_free\n");
    --cnt;
}
//이런식으로 전처리 해주었다.
//malloc 대신 debug_malloc을 사용되도록 매크로 정의
#define malloc(sz) debug_malloc(sz)
#define free(addr) debug_free(addr)

int main(void)
{
    int *p1 = (int *)malloc(sizeof(int) * 10);
    int *p2 = (int *)malloc(sizeof(int) * 10);
    int *p3 = (int *)malloc(sizeof(int) * 10);

    free(p1);
    free(p2);
    free(p3);
}
//cnt로 메모리 관리가 용이해짐

// 4-------------------------------------------------
//1.어느파일에 어떤함수에 몇번째 줄에서 malloc했는지에 대한 구체적 정보를 얻고 싶었다.
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
//2.여기에 어느파일,어느함수,몇번째 라인인지 정보도 같이 받기로 했다.
void *debug_malloc(size_t sz, const char *file, const char *func, int line)
{
    void *p = malloc(sz);
    ++cnt;
    printf("debug_malloc\n");
    printf("%d\n", line);
    printf("%s\n", file);
    printf("%s\n", func);
    return p;
}

void debug_free(void *addr)
{
    free(addr);
    printf("debug_free\n");
    --cnt;
}
// 3.debug_malloc을 할때 자동으로 " __FILE__, __func__, __LINE__"를 넘겨주자
#define malloc(sz) \
    debug_malloc(sz, __FILE__, __func__, __LINE__)
#define free(addr) debug_free(addr)

int main(void)
{
    int *p1 = (int *)malloc(sizeof(int) * 10);
    //4.
    //위의 코드는 "(int *)debug_malloc(sz, __FILE__, __func__, __LINE__)"으로 macro 치환됨
    int *p2 = (int *)malloc(sizeof(int) * 10);
    int *p3 = (int *)malloc(sizeof(int) * 10);

    free(p1);
    free(p2);
    free(p3);
}