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
        zhong=zhong*num; // @@ Error: zhong is uninitialized on first iteration; should be initialized to 1 before the loop or set to num on first read.
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
            zhong=1; // @@ Error: For addition, zhong should be set to 1 to multiply subsequent terms, but this logic fails because the next iteration multiplies zhong by num, which is incorrect for the first term after '+'.
        }
        else if(c=='-')
        {
            zhong=-1; // @@ Error: Same issue as above; zhong should be set to -1, but the multiplication logic in the next iteration will produce wrong results.
        }
        else 
        {
            printf("%d",result);
            break;
        }
    }
    return 0;
}