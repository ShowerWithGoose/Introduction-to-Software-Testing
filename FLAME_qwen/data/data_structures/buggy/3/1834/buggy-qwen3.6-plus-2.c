#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL) @@ `gets` is removed in the C11 standard and causes compilation errors in strict environments; use `fgets` or `scanf` instead.
    {
        int num=0,isok=0;
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
            isok=1;
            }
        }
        if(isok)
        {
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++);
        
            b=num;
            if(s[num-1]=='0') @@ Logic error: incorrectly triggers for numbers like "10.5" where the digit before the decimal is '0' but it's not a leading zero. Should be `if(num==1 && s[0]=='0')`.
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); @@ Indexing error: `a+2` assumes `num==1`. Should be `s[num+1+a]` to correctly access the first significant digit after the decimal point.
                if(a+2!=strlen(s)) @@ Indexing error: should check `num+1+a != strlen(s)` to correctly determine if there are more digits to print.
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) @@ Indexing error: loop start index should be `num+2+a` to correctly print the remaining significant digits.
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1);
            }
            else
            {
                printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1);

            }
        }
        else 
        {
            printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}