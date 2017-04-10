#include <stdio.h>

typedef struct mystruct_ {
    int sa;
    int sb;
} mystruct_t ;

mystruct_t func(int a, int b)
{
    struct mystruct_ tmp_onstack;
    tmp_onstack.sa = a+10;
    tmp_onstack.sb = b+20;
    return tmp_onstack;
}

main()
{
 int x,y;
    struct mystruct_ actualstruct;
    x=2;
    y=3;
    actualstruct.sa = 1111;
    actualstruct.sb = 2222;
    printf("actualstruct.sa = %d\n", actualstruct.sa);
    printf("actualstruct.sb = %d\n", actualstruct.sb);
    actualstruct=func(x,y);
    printf("after\n");
    printf("actualstruct.sa = %d\n", actualstruct.sa);
    printf("actualstruct.sb = %d\n", actualstruct.sb);
}
