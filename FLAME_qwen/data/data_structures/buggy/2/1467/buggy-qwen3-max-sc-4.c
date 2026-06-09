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

    for (int i=0;i<=strlen(c);i++) // @@ [Loop condition should be i < strlen(c), not i <= strlen(c); accessing c[strlen(c)] is out-of-bounds (null terminator)]
    {
        if (c[i]=='*' || c[i]=='/')
        {
            if (c[i]=='*')
            {
                b[i+1]=b[i]*b[i+1]; // @@ [Incorrect operand order: should be b[i] = b[i] * b[i+1], then skip next number; current logic corrupts values]
                b[i]=0;
            }
            if (c[i]=='/')
            
            {
                b[i+1]=b[i]/b[i+1]; // @@ [Incorrect operand order: should be b[i] = b[i] / b[i+1]; also, division by zero not handled but problem states valid input]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Same issue: i <= strlen(c) causes out-of-bounds access; also, b array has more elements than c]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [When i == strlen(c), c[i] is '\0', which is stored into op; later used as operator causing undefined behavior]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Again, i <= strlen(op) leads to reading past op array; also, loop prints intermediate results instead of final answer]
    {
        if (op[i]=='+' || op[i]=='-')
        {
            if (op[i]=='+')
            {
                ans[i+1]=ans[i]+ans[i+1]; // @@ [Same operand order issue; should update ans[i+1] based on previous accumulated value, not pairwise]
                ans[i]=0;
            }
            if (op[i]=='-')
            
            {
                ans[i+1]=ans[i]-ans[i+1]; // @@ [Operand order wrong: should be ans[i+1] = ans[i] - ans[i+1] only if left-to-right with correct accumulation]
                ans[i]=0;
            }                
        }
        if (ans[i]!=0)
        {
            printf("%d ",ans[i]);    // @@ [Prints multiple values during evaluation instead of single final result after '='; also includes space]
        }
    }
    return 0;
}