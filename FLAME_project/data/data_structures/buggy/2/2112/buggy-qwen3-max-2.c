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
        zhong=zhong*num; // @@ [zhong is uninitialized, leading to undefined behavior; also, this multiplication is incorrect for the first number in a term]
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
            zhong=1; // @@ [should initialize zhong to the next term's first number, not 1; current logic fails when next term starts with subtraction or standalone number]
        }
        else if(c=='-')
        {
            zhong=-1; // @@ [same issue: should set zhong to negative of next number, but next number hasn't been read yet]
        }
        else 
        {
            printf("%d",result);
            break;
        }
    }
    return 0;
}