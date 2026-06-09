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
            c[k]=str[i]; // @@ No null terminator added; subsequent strlen(c) will read past the array.
            k++;
        }
        if (str[i]=='=')
        {
            break;
        }
    }

    for (int i=0;i<=strlen(c);i++) // @@ Uses strlen(c) on a non-null-terminated array; also loop should be i<strlen(c) to avoid out-of-bounds access.
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
    for (int i=0,k=0;i<=strlen(c);i++) // @@ Same issue: strlen(c) on non-null-terminated array; off-by-one loop may access invalid indices.
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ Operator mapping is incorrect; should not simply copy c[i] because indices shift after multiplication/division.
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ strlen(op) on non-null-terminated array; undefined behavior.
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
            printf("%d ",ans[i]); // @@ Prints intermediate results instead of final result; should output final value after loop.
        }
    }
    return 0;
}