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
                scanf("%d",st[len++]); // @@ Missing '&' operator before st[len++], scanf expects a pointer to int. Additionally, the code lacks a check for stack overflow (len >= 100) as required by the problem.
                break ;
            }
        }
    }
    return 0;
}