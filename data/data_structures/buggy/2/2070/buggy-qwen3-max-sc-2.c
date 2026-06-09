#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]={}, fig[10000]={};
    int num[10000]={}, j=0, l=0;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to a compilation error.]
    char first='+';
    if(s[0]=='-')
    {
        first='-';
        for(int p=0;p<strlen(s);p++)
        {
            s[p]=s[p+1];
        }
    }
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                int k=i;
                while(s[k]>='0'&&s[k]<='9')
                {
                    num[l]=num[l]*10+(s[k]-'0');
                    k++;
                }
                l++;
                i=k;
            }else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
            {
                fig[j]=s[i];
                j++;
            }else
            continue;
        }
    
    
    int num0=num[0], rec0=0, k=0;
    char str='+';
    for(int i=0;i<strlen(s);i++) // @@ [This loop uses 'strlen(s)' as the bound, but 'fig' and 'num' arrays are shorter; it should iterate based on the number of operators or tokens, not the original string length, causing out-of-bounds access and undefined behavior.]
    {
        if(fig[i]=='*'||fig[i]=='/')
        {
            num0=num[i]; // @@ [Incorrect indexing: when processing multiplication/division starting at operator i, the left operand should be num[i], but due to earlier parsing logic, the alignment between fig[] and num[] may be off, especially after handling unary minus.]
            k=i;
            while(fig[k]=='*'||fig[k]=='/')
            {
                if(fig[k]=='*')
                {
                    num0=num0*num[k+1];
                    k++;
                }
                else if(fig[k]=='/')
                {
                    num0=num0/num[k+1];
                    k++;
                }
            }
            i=k;
        }
        if(fig[i]=='+'||fig[i]=='-')
        {
            if(str=='+')
            {
                rec0+=num0;
                str=fig[i];
            }else if(str=='-')
            {
                rec0-=num0;
                str=fig[i];
            }
        }
        if(fig[i]=='=')
        {
            if(str=='+')
            {
                rec0+=num0;
            }else if(str=='-')
            {
                rec0-=num0;
            }
            
            if(first=='+')
            printf("%d\n", rec0);
            else if(first=='-')
            printf("-%d\n", rec0); // @@ [Incorrect sign handling: if the first number is negative, the program prints "-<positive_result>", which is wrong if rec0 already includes the negative value. The initial negative sign was stripped but not properly integrated into the calculation.]
            
            break;
        }
        
    }
    return 0;
}