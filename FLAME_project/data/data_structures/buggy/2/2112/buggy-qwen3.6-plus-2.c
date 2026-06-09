#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char *argv[]) 
{
    int num,result=0,zhong; // @@ [Variable 'zhong' is used uninitialized. It should be initialized to 1 before the loop starts to correctly handle the first number.]
    char c;
    while(1)
    {
        scanf("%d %c",&num,&c);
        zhong=zhong*num; // @@ [Since 'zhong' was uninitialized, this calculation is undefined behavior. Even if initialized, logic for handling the first term needs care.]
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
            zhong=1; // @@ [Logic error: When encountering '+', the next term should start with a positive sign. Setting zhong=1 is correct for multiplication accumulation start, but see below for '-'.]
        }
        else if(c=='-')
        {
            zhong=-1; // @@ [Logic error: When encountering '-', the next term should be subtracted. Setting zhong=-1 allows the subsequent `zhong=zhong*num` to make the term negative. This part is logically okay IF zhong is reset properly.]
        }
        else 
        {
            printf("%d",result);
            break;
        }
    }
    return 0;
}