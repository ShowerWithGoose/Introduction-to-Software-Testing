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
        zhong=zhong*num; // @@ [Error: 'zhong' is uninitialized, leading to undefined behavior. It should be initialized to 1 before use.]
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
        result=result+zhong; // @@ [Error: This adds 'zhong' to result even when the operator is '+' or '-', but 'zhong' has not been properly set for the first term. The logic for handling '+' and '-' is flawed.]
        if(c=='+')
        {
            zhong=1; // @@ [Error: Setting zhong to 1 here is incorrect; it should reset zhong to 0 or handle the next term properly. The algorithm does not correctly accumulate terms with addition/subtraction.]
        }
        else if(c=='-')
        {
            zhong=-1; // @@ [Error: Similar issue; setting zhong to -1 does not correctly handle subtraction. The algorithm should store the next term's value, not a multiplier.]
        }
        else 
        {
            printf("%d",result);
            break;
        }
    }
    return 0;
}