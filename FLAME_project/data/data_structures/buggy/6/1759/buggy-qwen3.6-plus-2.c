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
                scanf("%d",st[len++]); // @@ [The second argument to scanf should be a pointer (address) to the variable where the input will be stored. `st[len++]` evaluates to an integer value, not an address. It should be `&st[len]` followed by `len++`, or `st + len` with appropriate index management. Passing an integer value as a pointer causes a segmentation fault (Runtime Error).]
                break ;
            }
        }
    }
    return 0;
}