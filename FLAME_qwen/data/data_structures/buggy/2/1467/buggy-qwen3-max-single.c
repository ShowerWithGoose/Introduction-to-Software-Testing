#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
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

    for (int i=0;i<=strlen(c);i++) // @@ [Loop condition should be i < strlen(c), not i <= strlen(c); accessing c[strlen(c)] is out-of-bounds (null terminator)]
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
                b[i+1]=b[i]/b[i+1]; // @@ [Incorrect operand order: should be b[i] / b[i+1], but logic assumes left-to-right; however, more critically, division by zero possible and integer division is required but operands may be zeroed incorrectly]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Same issue: i <= strlen(c) leads to out-of-bounds access]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [When i == strlen(c), c[i] is '\0', which is stored in op; later used as operator causing undefined behavior]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Again, i <= strlen(op) causes out-of-bounds access; op[strlen(op)] is invalid]
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
            printf("%d ",ans[i]);    // @@ [Output format incorrect: problem requires only the final result as integer, not intermediate values with space; also prints multiple numbers instead of single result]
        }
    }
    return 0;
}