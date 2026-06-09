#define MAXN 110
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <string.h>
int st[MAXN]={},len=0;
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
                scanf("%d",st[len++]); // @@ The second argument to scanf should be the address of the variable (pointer), but `st[len++]` evaluates to an int value, not a pointer. It should be `&st[len]` and then increment len, or `st + len` then increment. Passing an integer value as a pointer causes a segmentation fault (Runtime Error).
                break ;
            }
        }
    }
    return 0;
}