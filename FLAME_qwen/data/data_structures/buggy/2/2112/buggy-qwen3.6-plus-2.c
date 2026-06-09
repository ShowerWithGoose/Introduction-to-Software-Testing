#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char *argv[]) 
{
    int num,result=0,zhong=1; // @@ [zhong is used uninitialized in 'zhong=zhong*num;', causing undefined behavior. It must be initialized to 1 to correctly compute the first term.]
    char c;
    while(1)
    {
        scanf("%d %c",&num,&c);
        zhong=zhong*num;
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