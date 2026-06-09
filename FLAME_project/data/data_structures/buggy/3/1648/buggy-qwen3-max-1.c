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
        count=0-back-1; // @@ [The exponent calculation is incorrect. For input "0.9", back=0 (since '9' is not zero), so this block isn't even entered. But even if it were, the formula should be -(back+1), but more fundamentally, the logic fails to handle non-zero digits after leading zeros correctly.]
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
        count=front-1; // @@ [This assumes the number has no leading zero before the decimal point, but for "0.9", front=1 and num[0]=='0', yet the program incorrectly goes into this else block because back==0, leading to output "0.9e0" instead of "9e-1". The condition to enter the 'back>0' block is wrong: it only triggers if there are trailing zeros before the first non-zero digit, but "0.9" has no such zeros, so back remains 0.]
        if(len==1)
        printf("%c",num[0]);
        
        else
        {
            printf("%c.",num[0]); // @@ [For "0.9", this prints "0." which violates scientific notation rules since the base must have a non-zero digit before the decimal point. The program fails to normalize the number by shifting past the leading zero and decimal point to find the first significant digit.]
        
            for(i=1;i<len;i++)
            {
                if(num[i]!='.')
                printf("%c",num[i]);
            }
        }
    }
    printf("e%d",count); // @@ [The exponent is computed incorrectly in both branches. For "0.9", it outputs e0 instead of e-1 because the logic doesn't account for the position of the first significant digit relative to the decimal point when the integer part is zero.]
      
    return 0;
}