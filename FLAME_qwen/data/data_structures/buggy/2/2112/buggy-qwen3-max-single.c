#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char *argv[]) 
{
    int num,result=0,zhong; // @@ [zhong is used uninitialized; its initial value is indeterminate, leading to undefined behavior when used in zhong*num]
    char c;
    while(1)
    {
        scanf("%d %c",&num,&c);
        zhong=zhong*num; // @@ [zhong is uninitialized here; this causes undefined behavior. It should be initialized based on the first number and operator context]
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
            zhong=1;
        }
        else if(c=='-')
        {
            zhong=-1;
        }
        else 
        {
            printf("%d",result);
            break;
        }
    }
    return 0;
}