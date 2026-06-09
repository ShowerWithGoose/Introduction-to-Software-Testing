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
        count=0-back-1; @@ // The exponent calculation is incorrect. For "0.9", back=0 (since '9' is not zero), so this block isn't even entered. But even if it were, count = -back -1 is wrong. For "0.009", back=2, exponent should be -3, but this gives -3, which seems right, but the logic to enter this block fails when there are no leading zeros after decimal.
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
        count=front-1; @@ // This assumes the number has more than one digit before decimal or is a non-zero single digit. But for "0.9", front=1 and num[0]=='0', yet sign2 remains 0 because the loop starting at i=2 never runs (since '9' != '0'), so back=0, and this else block is executed, treating "0.9" as if it were "9" with exponent 0, leading to "0.9e0" instead of "9e-1".
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