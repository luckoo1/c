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

ALLOC_INFO info[1000]; // 1000개의 메모리 할당 정보 기록할 수 있다.

int cnt = 0;

void *debug_malloc(size_t sz, const char *file, const char *func, int line)
{
    //메모리할당에 대한 정보들을 배열에 기록하자.
    void *p = malloc(sz);
    //아래같이 하면 0번째꺼는 info[0]위치에 들어간다.
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
    for (int i = 0; i < cnt; i++) // 0부터 시작하면서 cnt만큼 loop를 돌며 해당주소를 찾는다.
    {
        if (info[i].addr == addr)
        {
            info[i] = info[cnt - 1];
            /*
            링크드리스트면 바로 제거하면되지만
            배열이므로 제일 뒤에 있는 요소를
            제거되는 자리에 매꿀거다
            i번째 제거
            만약 크기가 10짜리 배열인데 5번째가 제거되었다.
            그럼 5번째자리를 비우고 10번째자리에 있는 요소를 5번째 자리에 넣는거다.
            그리고 10번째 배열의 기록을 삭제

            "i번째"를 자리에 "cnt-1번째"자리의 요소를 넣는것
            */

            // free하고 cnt를 줄인다.
            free(addr);
            --cnt;
            return;
        }
    }
    printf("debug_free error. bad address\n"); // for문을 다 돌았을때 error
}

void debug_check()
{
    if (cnt == 0)
    {
        printf("no memory leak\n");
        return;
    }

    printf("found %d memory leak\n", cnt); //몇개의 메모리 누수가 있는지 출력

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
로 실행해보면
no memory leak
*/

/*
free(p1);
free(p2);
로 실행해보면
found 1 memory leak
4_9.Predifined_macro_예제실습.c(function main, line no. 90) : addr 00B51548, 40 byte
C:\Users\beobs\OneDrive\Desktop\Github\c_intermediate>gcc 4_9.Predifined_macro_예제실습.c
*/

/*
free(p1);
free(p2);
free(p3 + 1);
로 실행해보면
debug_free error. bad address
found 1 memory leak
4_9.Predifined_macro_예제실습.c(function main, line no. 91) : addr 006B1578, 40 byte
*/