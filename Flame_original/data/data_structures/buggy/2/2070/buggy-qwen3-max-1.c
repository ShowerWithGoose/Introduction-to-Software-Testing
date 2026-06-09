#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]={}, fig[10000]={};
    int num[10000]={}, j=0, l=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to a compilation error.]
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
    for(int i=0;i<strlen(s);i++) // @@ [Loop bound is based on `strlen(s)`, but `fig` array length is much shorter (only operators). This causes out-of-bounds access to `fig[i]` when `i` exceeds the number of operators, leading to undefined behavior or incorrect logic. Should loop over `j` (number of operators) instead.]
    {
        if(fig[i]=='*'||fig[i]=='/')
        {
            num0=num[i]; // @@ [Incorrect: should start with `num[i]` only if processing from current position, but logic assumes `num0` represents result of a multiplicative sub-expression starting at `i`. However, `num[i]` may not be the correct operand because prior additive operations may have altered expected indexing. Also, `num0` was initialized to `num[0]` earlier, which may be overwritten incorrectly here.]
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
        if(fig[i]=='=') // @@ [Accessing `fig[i]` where `i` can be beyond the actual number of stored operators due to incorrect loop bound (`strlen(s)`), leading to reading uninitialized or garbage values. This may prevent detecting '=' correctly or cause premature/missed termination.]
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
            printf("-%d\n", rec0); // @@ [Incorrect sign handling: if the first number is negative, the program prints "-<value>", but if `rec0` itself is negative (e.g., expression evaluates to -5), this would print "--5" or similar. The initial `first` flag approach is flawed; better to parse numbers with their signs during tokenization.]
            
            break;
        }
        
    }
    return 0;
}