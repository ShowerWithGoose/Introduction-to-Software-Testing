#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]={}, fig[10000]={};
    int num[10000]={}, j=0, l=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like those with strict compilation flags or newer C standards), `gets` is removed entirely, leading to a compilation error: "implicit declaration of function ‘gets’" or "‘gets’ was not declared in this scope".]
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
    for(int i=0;i<strlen(s);i++) // @@ [This loop iterates based on `strlen(s)`, but the relevant operators are stored in `fig`, whose length is `j`. This causes the loop to run too many times, accessing uninitialized elements in `fig` and `num`, leading to undefined behavior. It should iterate up to `j` (number of operators) instead.]
    {
        if(fig[i]=='*'||fig[i]=='/')
        {
            num0=num[i]; // @@ [This uses `num[i]`, but after parsing, the numbers are stored sequentially in `num[0..l-1]`, and operators in `fig[0..j-1]`. The index `i` here corresponds to operator position, so the associated number should be `num[i+1]` or similar. Using `num[i]` mismatches operands and operators, causing incorrect calculations.]
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
        if(fig[i]=='=') // @@ [When `fig[i]` is '=', the code prints the result, but due to the earlier loop bound error (`i` going up to `strlen(s)`), this condition may never be reached correctly, or may access garbage data. Also, the logic does not properly handle the final term before '=' because `num0` might not represent the last computed value correctly due to indexing errors.]
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
            printf("-%d\n", rec0); // @@ [This prints "-%d" if the first character was '-', but if the overall result is negative (e.g., expression starts with '-' and evaluates to -5), this would print "--5" or similar incorrect format. The sign handling is flawed; the initial number should be negated during parsing, not handled separately at output.]
            
            break;
        }
        
    }
    return 0;
}