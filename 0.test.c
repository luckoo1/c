#include <stdio.h>
#define TOSTR2(x) #x
#define TOSTR(x) TOSTR2(x)

#define VAR(TYPE, NAME) TYPE NAME TOSTR(__LINE__)
int main(void)
{
    VAR(int, n) = 6; 
    printf("%d",n11);

}
