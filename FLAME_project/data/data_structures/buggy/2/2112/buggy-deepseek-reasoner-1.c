#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char *argv[]) 
{
    int num,result=0,zhong; // @@ zhong未初始化，导致后续计算使用未定义值
    char c;
    while(1)
    {
        scanf("%d %c",&num,&c);
        zhong=zhong*num; // @@ 使用未初始化的zhong变量，应初始化为1或直接赋值num
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