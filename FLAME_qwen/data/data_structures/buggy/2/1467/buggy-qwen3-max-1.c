#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000],c[1000],op[1000];
    int b[1000]={0},ans[1000],num=0;
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
                b[i+1]=b[i]/b[i+1]; // @@ [Incorrect operand order: should be b[i] = b[i] / b[i+1], not b[i+1] = b[i] / b[i+1]]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Same issue: loop goes one past valid index of c[] and b[]]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [When i == strlen(c), c[i] is '\0', which is stored into op[], causing later logic errors]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Again, loop condition should be i < strlen(op); also, op[] may contain '\0' as operator]
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
                ans[i+1]=ans[i]-ans[i+1]; // @@ [Incorrect associativity: should accumulate result left-to-right, but this overwrites ans[i+1] incorrectly]
                ans[i]=0;
            }                
        }
        if (ans[i]!=0)
        {
            printf("%d ",ans[i]);    // @@ [Prints intermediate values with space; should only print final result once without space]
        }
    }
    return 0;
}