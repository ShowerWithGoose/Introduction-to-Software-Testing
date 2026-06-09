#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char *argv[]) 
{
    int num,result=0,zhong;
    char c;
    while(1)
    {
        scanf("%d %c",&num,&c);
        zhong=zhong*num; // @@ Error: zhong is uninitialized; it should be initialized to 1 before the loop or set correctly for the first term. Also, this logic incorrectly multiplies zhong by num for the first number, but zhong should start as num for the first term.
        while(c=='*'||c=='/')
        {
            scanf("%d",&num);
            if(c=='*')
            {
                zhong=zhong*num;
            }
            else 
            {
                zhong=zhong/num;
            }
            scanf(" %c",&c);
        }
        result=result+zhong;
        if(c=='+')
        {
            zhong=1; // @@ Error: For addition, zhong should be set to 0 (or the next number) to start a new term, not 1. Setting to 1 causes incorrect multiplication in the next iteration.
        }
        else if(c=='-')
        {
            zhong=-1; // @@ Error: For subtraction, zhong should be set to 0 (or the negative of the next number) to start a new term, not -1. Setting to -1 causes incorrect multiplication in the next iteration.
        }
        else 
        {
            printf("%d",result);
            break;
        }
    }
    return 0;
}