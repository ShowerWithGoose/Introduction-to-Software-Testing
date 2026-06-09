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

    for (int i=0;i<=strlen(c);i++) // @@ [Loop runs one past the last operator; `c[strlen(c)]` is '\0', leading to out-of-bounds access in `b[i+1]` when i == strlen(c)]
    {
        if (c[i]=='*' || c[i]=='/')
        {
            if (c[i]=='*')
            {
                b[i+1]=b[i]*b[i+1]; // @@ [When i equals strlen(c), b[i+1] accesses beyond valid data]
                b[i]=0;
            }
            if (c[i]=='/')
            
            {
                b[i+1]=b[i]/b[i+1]; // @@ [Same out-of-bounds issue; also division order is wrong: should be b[i] / b[i+1], but logic assumes left-to-right which is correct, however indexing is flawed]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Again loops to strlen(c) inclusive, causing potential out-of-bounds read of b[i] and c[i]]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [When i == strlen(c), c[i] is '\0', which is stored as an operator, corrupting op array]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Loop includes strlen(op), accessing op[strlen(op)] which is '\0'; also ans[i+1] may be out of bounds]
    {
        if (op[i]=='+' || op[i]=='-')
        {
            if (op[i]=='+')
            {
                ans[i+1]=ans[i]+ans[i+1]; // @@ [If i is last valid index, ans[i+1] is uninitialized or out of meaningful range]
                ans[i]=0;
            }
            if (op[i]=='-')
            
            {
                ans[i+1]=ans[i]-ans[i+1]; // @@ [Same issue: incorrect indexing and potential use of uninitialized values]
                ans[i]=0;
            }                
        }
        if (ans[i]!=0)
        {
            printf("%d ",ans[i]);    // @@ [Prints intermediate results with space, not just final answer; also prints multiple values instead of single result]
        }
    }
    return 0;
}