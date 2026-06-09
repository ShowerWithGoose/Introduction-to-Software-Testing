#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
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

    for (int i=0;i<=strlen(c);i++) // @@ [Loop condition should be i < strlen(c), not i <=; accessing c[strlen(c)] is out-of-bounds (null terminator)]
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
                b[i+1]=b[i]/b[i+1]; // @@ [Division order is incorrect: should be b[i] / b[i+1], but logic assumes left-to-right; however, more critically, if b[i+1] is zero, undefined behavior. Also, integer division truncates toward zero per problem, but this may not handle negative correctly depending on compiler, though problem likely assumes positive inputs. Primary issue is operand order in context of algorithm design.]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Same out-of-bounds issue: i <= strlen(c) accesses beyond valid operator array]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [When i == strlen(c), c[i] is '\0', which is stored into op; later logic treats it as an operator]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Again, i <= strlen(op) leads to reading op[strlen(op)] which is uninitialized or null, causing undefined behavior]
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
            printf("%d ",ans[i]);    // @@ [Output format includes space and prints intermediate non-zero values; should only print final result once without extra spaces]
        }
    }
    return 0;
}