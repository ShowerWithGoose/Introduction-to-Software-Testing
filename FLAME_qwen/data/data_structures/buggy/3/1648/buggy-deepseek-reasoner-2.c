#include<stdio.h>
#include<string.h>
int main()
{
    char num[10000]={};
    int i,j=0,sign=0,sign2=0;
    int front=0,back=0,count=0;
    scanf("%s",num);
    int len=strlen(num);
    
    for(i=0;num[i]!='\0';i++)
    {
        if(sign==0)
        {
            if(num[i]!='.')        
            front++;

        
            else
            sign=1;
        }        
     }
     
    if(front==1&&num[0]=='0') // @@ 条件正确，但内部处理不完整：当back==0（即小数部分第一位非零，如0.123）时，会错误地进入后面的else分支，导致输出"0.123e0"而非"1.23e-1"
    {
        if(sign2==0)
        for(i=2;num[i]!='\0';i++) // @@ 循环没有在遇到第一个非零数字后停止，导致后续零也被计入back，例如输入0.0101，back会错误地变成2（应为1），进而导致输出时索引错误
        {
            if(num[i]=='0')
            back++;
            else
            sign2=1;
        }
    }
    
    
    if(back>0)
    {
        count=0-back-1;
        if(len==back+3)
        printf("%c",num[back+2]);
        
        else
        {
            printf("%c.",num[back+2]);
            for(i=back+3;i<len;i++)
            printf("%c",num[i]);
        }
    }
    else
    {
        count=front-1; // @@ 当输入为0.xxx且小数部分第一位非零（back==0）时，此处错误地使用了front-1作为指数（应为负指数），并且输出时保留了整数部分的0，导致结果错误
        if(len==1)
        printf("%c",num[0]);
        
        else
        {
            printf("%c.",num[0]);
        
            for(i=1;i<len;i++)
            {
                if(num[i]!='.')
                printf("%c",num[i]);
            }
        }
    }
    printf("e%d",count);
      
    return 0;
}