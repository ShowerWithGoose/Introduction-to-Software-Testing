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

    for (int i=0;i<=strlen(c);i++) // @@ [Loop condition should be i < strlen(c), not i <= strlen(c); accessing c[strlen(c)] is out-of-bounds (null terminator), and b[i+1] may access beyond valid numbers]
    {
        if (c[i]=='*' || c[i]=='/')
        {
            if (c[i]=='*')
            {
                b[i+1]=b[i]*b[i+1]; // @@ [Incorrect indexing: assumes operators and operands align by index, but after removing spaces and parsing, operator count is one less than operand count; also modifies b in place without adjusting subsequent indices]
                b[i]=0;
            }
            if (c[i]=='/')
            
            {
                b[i+1]=b[i]/b[i+1]; // @@ [Same indexing issue as above; also fails when b[i+1] is zero (though problem says expression is valid, still logic flawed)]
                b[i]=0;
            }                
        }
    }
    for (int i=0,k=0;i<=strlen(c);i++) // @@ [Again, i <= strlen(c) causes out-of-bounds access; also, b has (number of operands) = (number of operators + 1), so loop should go up to number of operands]
    {
        if (b[i]!=0)
        {
            ans[k]=b[i];
            op[k]=c[i]; // @@ [c[i] may be out-of-bounds when i equals number of operators; op array stores operator corresponding to each non-zero b[i], but alignment is broken after zeroing b[i]]
            k++;
        }
    }
    for (int i=0;i<=strlen(op);i++) // @@ [Loop condition i <= strlen(op) leads to out-of-bounds; also, op was filled only for non-zero b entries, so its effective length is not strlen(op)]
    {
        if (op[i]=='+' || op[i]=='-')
        {
            if (op[i]=='+')
            {
                ans[i+1]=ans[i]+ans[i+1]; // @@ [Same flawed left-to-right evaluation without respecting operator precedence already handled; also indexing assumes contiguous valid ans entries, which isn't guaranteed due to prior zero-skipping]
                ans[i]=0;
            }
            if (op[i]=='-')
            
            {
                ans[i+1]=ans[i]-ans[i+1]; // @@ [Incorrect subtraction order: should be ans[i] - ans[i+1], but if ans[i] was zeroed earlier, result is wrong; also doesn't handle initial negative correctly]
                ans[i]=0;
            }                
        }
        if (ans[i]!=0)
        {
            printf("%d ",ans[i]);    // @@ [Prints intermediate non-zero values instead of final result; for input "0 =", nothing is printed because ans[0] might be 0 and skipped, leading to no output]
        }
    }
    return 0;
}