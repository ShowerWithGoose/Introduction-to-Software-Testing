#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str);
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

    for (int i=0;i<=strlen(c);i++) // @@ Error: The loop condition `i<=strlen(c)` may cause out-of-bounds access when `i` equals `strlen(c)`, as `c[strlen(c)]` is the null terminator, not a valid operator. Also, the logic for handling multiplication and division is flawed because it uses `b[i]` and `b[i+1]` assuming operators and numbers are aligned, but the arrays `b` and `c` are not synchronized in index after skipping spaces and the `=` sign.
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
                b[i+1]=b[i]/b[i+1];
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ Error: Similar out-of-bounds issue with `i<=strlen(c)`. Additionally, the logic for collecting non-zero `b[i]` and corresponding operators `c[i]` is incorrect because after the previous loop, `b[i]` may be zero for positions that originally held numbers, and the indices do not align properly.
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i];
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ Error: The loop condition `i<=strlen(op)` may cause out-of-bounds access. Also, the logic for addition and subtraction is flawed because it modifies `ans[i+1]` and sets `ans[i]` to 0, but the loop continues and may incorrectly process already-zeroed elements.
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
            printf("%d ",ans[i]); // @@ Error: This prints intermediate results with a trailing space, not the final result. The expected output is just the integer result without extra spaces.
        }
    }
    return 0;
}