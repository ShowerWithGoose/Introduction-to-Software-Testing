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

    for (int i=0;i<=strlen(c);i++) // @@ [Loop goes out of bounds; should be i < strlen(c). Also, this pass doesn't correctly handle operator precedence because it modifies b[i] and b[i+1] but doesn't shift remaining elements or update operator list accordingly.]
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
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Loop condition should be i <= strlen(c) only if b has strlen(c)+1 elements, but logic is flawed: assumes b[i]!=0 means valid number, which fails when original number is zero (e.g., input "0=").]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i];
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Loop condition incorrect; should be i < k or similar. Also, final output prints intermediate non-zero values instead of just the final result.]
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
            printf("%d ",ans[i]);    // @@ [Prints all non-zero intermediate results with space, not just final answer. Should print only final result as integer without space. Also fails for input "0=" because b[0] becomes 0 and is skipped in ans[] population.]
        }
    }
    return 0;
}