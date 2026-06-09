#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
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

    for (int i=0;i<=strlen(c);i++) // @@ [Loop condition should be `i < strlen(c)`; using `<=` accesses out-of-bounds element `c[strlen(c)]` which is '\0', leading to incorrect logic and potential undefined behavior]
    {
        if (c[i]=='*' || c[i]=='/')
        {
            if (c[i]=='*')
            {
                b[i+1]=b[i]*b[i+1];
                b[i]=0;
            }
            if (c[i]=='/')
            
            {
                b[i+1]=b[i]/b[i+1]; // @@ [Incorrect operand order: should be `b[i+1] = b[i] / b[i+1]` but this still fails because previous operations may have zeroed `b[i]`; also integer division truncates toward zero, but logic assumes left-to-right without considering operator precedence correctly across full expression]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Same issue: loop condition `i <= strlen(c)` causes out-of-bounds access; also, `b` array has `strlen(c)+1` numbers, so this loop should run up to `strlen(c)` inclusive for numbers, but indexing is inconsistent]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [When `i == strlen(c)`, `c[i]` is '\0', which is stored into `op[k]`; later logic checks for '+'/'-' on this null char, causing incorrect behavior]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Loop condition again uses `<=`, accessing `op[strlen(op)]` which is uninitialized or '\0'; also, final result printing logic is flawed—it prints intermediate non-zero values instead of only the final result]
    {
        if (op[i]=='+' || op[i]=='-')
        {
            if (op[i]=='+')
            {
                ans[i+1]=ans[i]+ans[i+1];
                ans[i]=0;
            }
            if (op[i]=='-')
            
            {
                ans[i+1]=ans[i]-ans[i+1];
                ans[i]=0;
            }                
        }
        if (ans[i]!=0)
        {
            printf("%d ",ans[i]);    // @@ [Prints all non-zero intermediate results with space, not just the final answer; expected output is a single integer without extra spaces or values]
        }
    }
    return 0;
}