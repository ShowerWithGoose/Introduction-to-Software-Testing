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
    else // @@ The condition `else` executes when `back` is 0. For input "0.9", `back` remains 0 because the loop calculating `back` only increments it for '0's before the first non-zero digit. However, the logic for handling numbers like "0.9" (where the first decimal digit is non-zero) falls into this `else` block incorrectly, treating it as a number >= 1 or an integer, leading to wrong output format and exponent. Specifically, for "0.9", `front` is 1, `num[0]` is '0', so the `if(front==1&&num[0]=='0')` block runs. Inside, `num[2]` is '9', which is not '0', so `sign2` becomes 1 immediately, and `back` remains 0. The code then goes to the final `else` block.
    {
        count=front-1; // @@ For "0.9", `front` is 1, so `count` becomes 0. This is incorrect; the exponent should be -1.
        if(len==1)
        printf("%c",num[0]);
        
        else
        {
            printf("%c.",num[0]); // @@ For "0.9", this prints "0.", which is incorrect. The base should be "9".
        
            for(i=1;i<len;i++)
            {
                if(num[i]!='.')
                printf("%c",num[i]); // @@ This prints the rest of the digits, resulting in "0.9". Combined with the previous line, it outputs "0.9e0".
            }
        }
    }
    printf("e%d",count);
      
    return 0;
}