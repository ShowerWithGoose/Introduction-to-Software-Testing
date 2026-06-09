#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str); // @@ gets is removed in C11 standard and causes compilation errors in modern environments; use fgets instead.
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

    for (int i=0;i<=strlen(c);i++) // @@ c is not null-terminated, calling strlen causes undefined behavior; <= leads to out-of-bounds access.
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
    for (int i=0,k=0;i<=strlen(c);i++) // @@ Same issue: c is not null-terminated, strlen is unsafe; <= causes out-of-bounds.
    {
        if (b[i]!=0) // @@ Logical error: valid operands can be 0, causing them to be incorrectly skipped during array compression.
        {
            ans[k]=b[i];
            op[k]=c[i];
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ op is not null-terminated, strlen causes undefined behavior; <= leads to out-of-bounds.
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
        if (ans[i]!=0) // @@ Logical error: prints intermediate results instead of only the final calculated result.
        {
            printf("%d ",ans[i]);    
        }
    }
    return 0;
}