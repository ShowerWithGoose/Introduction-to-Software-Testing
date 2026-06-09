#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int stack[101];
    int *top;
    int op,elem,isEnd=0;;
    top=&stack[1];
    while(isEnd!=1)
    {
        scanf("%d",&op);
        switch(op)
        {
            case -1:
                isEnd=1;
                break;

            case 1:
                scanf("%d",&elem);
                if(top<=stack+100)
                {
                    *top=elem;
                    top++;
                }
                else
                {
                    printf("error ");
                }
                break;
            
            case 0:
                if(top>stack+1)
                {
                    top--;
                    printf("%d ",*top);
                }
                else
                printf("error ");
                break;
        }
    }
    return 0;
}
