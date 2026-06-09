#define MAXN 110
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <string.h>
int st[MAXN]={},len=0; // @@ [Invalid empty initializer in C; use `{0}` instead.]
int opt;
int main()
{
    while(scanf("%d",&opt))
    {
        switch(opt)
        {
            case -1 : 
            {
                return 0;
            }
            case 0 :
            {
                if(!len)
                {
                    printf("error ");
                    break ;
                }
                printf("%d ",st[--len]);
                break ;
            }
            case 1 :
            {
                scanf("%d",st[len++]); // @@ [Incorrect argument: `scanf` expects an `int*`, but `st[len++]` is an `int` value. Should be `&st[len]` or `st+len` with separate increment.]
                break ;
            }
        }
    }
    return 0;
}