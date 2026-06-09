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
                printf("%d ",st[--len]); // @@ Error: The pop operation should output the top element before decrementing the index. Here, `--len` decrements first, so it outputs the element below the top, which is incorrect. It should be `st[--len]` changed to `st[len-1]` with `len--` after, or `st[--len]` is wrong because it accesses the wrong element.
                break ;
            }
            case 1 :
            {
                scanf("%d",st[len++]); // @@ Error: Missing address-of operator `&`. `scanf` requires the address of the variable to store input. It should be `&st[len++]` or `st[len++] = ...` with a separate scanf. Also, no check for stack overflow (len >= MAXN) is performed, which could cause a buffer overflow.
                break ;
            }
        }
    }
    return 0;
}