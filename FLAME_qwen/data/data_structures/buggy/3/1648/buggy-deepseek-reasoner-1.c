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
        for(i=2;num[i]!='\0';i++) // @@ [This loop does not break after finding the first non-zero digit, so 'back' accumulates all zeros after the first non-zero, leading to incorrect exponent and base selection.]
        {
            if(num[i]=='0')
            back++;
            else
            sign2=1;
        }
    }
    
    
    if(back>0) // @@ [This condition incorrectly routes cases like "0.1" (where back==0) to the else block, which treats them as numbers with a non-zero first digit, producing wrong output. Also, for numbers with multiple non-zero digits, the handling is flawed.]
    {
        count=0-back-1; // @@ [The exponent calculation is based on a flawed 'back' count. For inputs like "0.101", back includes non-leading zeros, giving exponent -2 instead of -1.]
        if(len==back+3) // @@ [This condition incorrectly assumes the number has only one digit after the leading zeros, failing for numbers with more significant digits after the decimal.]
        printf("%c",num[back+2]);
        
        else
        {
            printf("%c.",num[back+2]); // @@ [The base digit selected is num[back+2], but if back includes non-leading zeros (e.g., "0.101" with back=1), this selects a zero digit instead of the first non-zero digit, yielding a wrong base.]
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