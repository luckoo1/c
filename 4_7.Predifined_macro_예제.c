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

//2-------------------------------------------------
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

//이런식으로 전처리 해주었다.
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

//3-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

//어느파일에 어떤함수에 몇번째 줄에서 malloc한지 파악하고 싶다
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

#define malloc(sz) \
    debug_malloc(sz, __FILE__, __func__, __LINE__)
#define free(addr) debug_free(addr)

int main(void)
{
    int *p1 = (int *)malloc(sizeof(int) * 10);
    //(int *)debug_malloc(sz, __FILE__, __func__, __LINE__)으로 치환됨
    int *p2 = (int *)malloc(sizeof(int) * 10);
    int *p3 = (int *)malloc(sizeof(int) * 10);

    free(p1);
    free(p2);
    free(p3);
}

/*
malloc 대신 debug_malloc을 사용되도록 매크로 정의
*/

//3-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _alloc_info
{
    char file[256];
    char func[256];
    int line;
    void *addr;
    size_t size;
};
typedef struct _alloc_info ALLOC_INFO;

ALLOC_INFO info[1000]; //메모리 할당 정보 기록
int cnt;

void *debug_malloc(size_t sz, const char *file, const char *func, int line)
{
    void *p = malloc(sz);
    strcpy(info[cnt].file, file);
    strcpy(info[cnt].func, func);
    info[cnt].line = line;
    info[cnt].addr = p;
    info[cnt].size = sz;
    ++cnt;
    return p;
}

void debug_free(void *addr)
{
    free(addr);
    for (int i = 0; i < cnt; i++)
    {
        if (info[i].addr == addr)
        {
            info[i] = info[cnt - 1];
            /*
            링크드리스트면 바로 제거하면되지만
            배열이므로 제일 뒤에 있는걸 제거되는 자리에 매꿀거다
            i번째 제거
            */
            free(addr);
            --cnt;
            return;
        }
    }
    printf("debug_free error. bad address\n"); //for문을 다 돌았을때 error
}

void debug_check()
{
    if (cnt == 0)
    {
        printf("no memory leak\n");
        return;
    }

    printf("found %d memory leak\n", cnt); //몇개의 메모리 누수가 있는지

    for (int i = 0; i < cnt; i++)
    {
        printf("%s(function %s, line no. %d) : addr %p, %d byte",
               info[i].file, info[i].func, info[i].line,
               info[i].addr, info[i].size);
    }
}

#define malloc(sz) \
    debug_malloc(sz, __FILE__, __func__, __LINE__)
#define free(addr) debug_free(addr)

int main(void)
{
    int *p1 = (int *)malloc(sizeof(int) * 10);
    //(int *)debug_malloc(sz, __FILE__, __func__, __LINE__)으로 치환됨
    int *p2 = (int *)malloc(sizeof(int) * 10);
    int *p3 = (int *)malloc(sizeof(int) * 10);

    free(p1);
    free(p2);
    free(p3);

    debug_check();
}

/*
    free(p1);
    free(p2);
    free(p3);
로 실행해보고
    free(p1);
    free(p2);
로 실행해보고
    free(p1);
    free(p2);
    free(p3+1);
로 실행해보고
*/