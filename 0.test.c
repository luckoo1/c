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