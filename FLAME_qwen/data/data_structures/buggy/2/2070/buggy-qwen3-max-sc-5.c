#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]={}, fig[10000]={};
    int num[10000]={}, j=0, l=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow and is removed in C11. However, the immediate error causing test failure is logical, not compilation. But note: some compilers may not support `gets`, leading to compilation error.]
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
    for(int i=0;i<strlen(s);i++) // @@ [Loop bound is wrong: iterating over `strlen(s)` but using `fig[i]` which has length much less than `s`. Should iterate up to `j` (number of operators) or until '=' is encountered. This causes out-of-bound access to `fig` and incorrect logic.]
    {
        if(fig[i]=='*'||fig[i]=='/')
        {
            num0=num[i]; // @@ [Should start with `num[i]` only if we are at the beginning of a multiplication/division chain, but `i` here is operator index, so operand should be `num[i]`? Actually, operands are stored in `num[0..l-1]`, operators in `fig[0..j-1]`. The relation is: expression = num[0] fig[0] num[1] fig[1] ... fig[j-1]. So when processing operator at index `i`, the left operand is `num[i]`, right is `num[i+1]`. But this code sets `num0 = num[i]` then uses `num[k+1]` — this part may be okay, but the bigger issue is loop bound and state management.]
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
        if(fig[i]=='+'||fig[i]=='-') // @@ [This condition is checked even after handling * / and updating `i` to `k`, but if `fig[i]` is now beyond valid range (e.g., `fig[i]` is '\0' or garbage), this leads to undefined behavior. Also, `str` is never updated correctly in all paths.]
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
        if(fig[i]=='=') // @@ [Same out-of-bound risk. Also, `rec0` starts at 0, and initial term handling is flawed. For example, if expression starts with positive number, `first='+'`, but `rec0` is 0 and `num0` is first number, but it's only added when encountering next '+' or '-' or '='. However, if expression is just "5=", then loop runs with i=0, fig[0]='=', so it adds num0 (which is num[0]=5) to rec0 (0) → correct. But if expression is "2*3=", then in first iteration i=0, fig[0]='*', so it computes num0=2*3=6, sets i=k=1. Then next iteration i=1 (but strlen(s) might be 4, so continues), now fig[1] is '=' (if j=2: ['*','=']), so it hits '=' case and adds num0=6 to rec0=0 → prints 6. That seems okay. However, the main flaw is that `rec0` is initialized to 0 and the first term is not accounted for unless an operator follows. But the real critical error is the loop bound: `i` goes up to `strlen(s)-1`, but `fig` only has `j` elements (<= strlen(s)), and often much fewer. So when `i >= j`, `fig[i]` is uninitialized (0), leading to skipping all conditions and never printing result. In particular, if the expression ends with '=', and `j` is small, the loop may never reach the `fig[i]=='='` check because `i` increments beyond `j` but still < strlen(s).]
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
            printf("-%d\n", rec0); // @@ [Incorrect sign handling: if first number is negative, the entire result may be negative, but intermediate operations could make it positive. Example: "-5 + 10" should output 5, not -5. The program stores first='-', then prints "-%d", which would print "-5" for rec0=5 → wrong. The initial negative should be applied to the first number, not the final result.]
            
            break;
        }
        
    }
    return 0;
}