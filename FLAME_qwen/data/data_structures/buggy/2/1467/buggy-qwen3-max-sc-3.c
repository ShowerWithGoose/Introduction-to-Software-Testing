#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    for (int i=0,j=0,k=0;i<strlen(str);i++)
    {
        if (str[i]>='0' && str[i]<='9')
        {
            num=num*10+(str[i]-'0');
            if (str[i+1]<'0' || str[i+1]>'9')
            {
                b[j]=num;
                 j++;
                num=0;             
            }
        }
        if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            c[k]=str[i];
            k++;
        }
        if (str[i]=='=')
        {
            break;
        }
    }

    for (int i=0;i<=strlen(c);i++) // @@ [Loop condition should be `i < strlen(c)`; using `<=` accesses out-of-bounds element `c[strlen(c)]` which is '\0', leading to incorrect logic and possible undefined behavior]
    {
        if (c[i]=='*' || c[i]=='/')
        {
            if (c[i]=='*')
            {
                b[i+1]=b[i]*b[i+1]; // @@ [Incorrect operand order: should be `b[i] = b[i] * b[i+1]`; current code overwrites `b[i+1]` and sets `b[i]=0` later, breaking expression evaluation]
                b[i]=0;
            }
            if (c[i]=='/')
            
            {
                b[i+1]=b[i]/b[i+1]; // @@ [Incorrect operand order: should be `b[i] = b[i] / b[i+1]`; also, integer division is required but logic fails due to wrong indexing and zeroing]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Same issue: loop condition `i <= strlen(c)` causes out-of-bounds access; also, `b[i]` might be zeroed incorrectly from prior step, skipping valid numbers]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [Accesses `c[i]` when `i == strlen(c)`, which is beyond valid operator range; `c` has operators only up to index `k-1` from earlier loop]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Loop condition `i <= strlen(op)` again causes out-of-bounds access; `op` length is not properly tracked and may include garbage]
    {
        if (op[i]=='+' || op[i]=='-')
        {
            if (op[i]=='+')
            {
                ans[i+1]=ans[i]+ans[i+1]; // @@ [Same operand order issue: should update `ans[i]`, not `ans[i+1]`; also, zeroing `ans[i]` breaks subsequent operations]
                ans[i]=0;
            }
            if (op[i]=='-')
            
            {
                ans[i+1]=ans[i]-ans[i+1]; // @@ [Operand order reversed; should be `ans[i] - ans[i+1]` stored in `ans[i]`]
                ans[i]=0;
            }                
        }
        if (ans[i]!=0)
        {
            printf("%d ",ans[i]);    // @@ [Prints intermediate values with space; problem requires only final result as integer without extra spaces or values]
        }
    }
    return 0;
}