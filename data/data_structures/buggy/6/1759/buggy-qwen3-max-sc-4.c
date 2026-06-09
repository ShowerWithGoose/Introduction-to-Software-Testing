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
                scanf("%d",st[len++]); // @@ [The scanf function expects the address of the variable to store the input, but 'st[len++]' is passed as a value (integer), not a pointer. This causes undefined behavior and likely a runtime crash or incorrect behavior. It should be '&st[len++]'.]
                break ;
            }
        }
    }
    return 0;
}