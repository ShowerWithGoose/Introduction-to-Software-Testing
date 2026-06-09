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
     
    if(front==1&&num[0]=='0')
    {
        if(sign2==0)
        for(i=2;num[i]!='\0';i++)
        {
            if(num[i]=='0')
            back++;
            else
            sign2=1;
        }
    }
    
    
    if(back>0) // @@ The condition should be num[0]=='0' to correctly handle cases like 0.1 where back is 0 but the number is less than 1 and requires a negative exponent.
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
        count=front-1;
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