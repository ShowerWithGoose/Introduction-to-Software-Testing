#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); @@ The variable `a` is an integer array, but `scanf` with `%c` reads a character. While this stores the ASCII value, the subsequent logic `a[0]=a[0]-'0'` assumes it's a digit character. However, if the input starts with a space or if the number has multiple digits, the logic for parsing numbers into `a` is flawed because `a` is used to store both operators (as their ASCII values) and operands (as integer values). This mixing of types in one array causes ambiguity. Specifically, `a[0]` is read as a char, then converted to int. If input is "0 =", `a[0]` becomes 0.
    a[0]=a[0]-'0';
    while((c=getchar())!='=')
    {
        if(c==' ')
        {
            continue;
        }
        else
        {
            if(c>='0'&&c<='9')
            {
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') @@ This condition checks if the previous element in `a` is an operator by comparing its integer value to the ASCII values of '+', '-', etc. If the previous element was a digit part of a multi-digit number, this fails to identify it correctly as a non-operator context for accumulation if the previous value happened to match an operator's ASCII code (unlikely for digits but logically messy). More critically, if `a[k-1]` holds a number like 10, it doesn't equal '+', so it enters the block. But `a[k-1]` is an `int`. If the previous token was a number, we should accumulate. If it was an operator, we start a new number. The logic `a[k-1]=a[k-1]*10+c-'0'` attempts to build the number in place.
                {
                    a[k-1]=a[k-1]*10+c-'0';
                }
                else
                {
                    a[k]=c-'0';
                    k++;
                }
            }
            else
            {
                a[k]=c; @@ Here, operators are stored as their ASCII character codes (e.g., '+' is 43). Numbers are stored as their integer values (e.g., 5 is 5). This mix makes subsequent processing difficult because `b` array logic relies on distinguishing them.
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*') @@ Checks if current element is multiplication operator (ASCII 42).
        {
            j--; @@ Decrements `j` to overwrite the last number added to `b`.
            b[j]=b[j]*a[i+1]; @@ Multiplies the last number in `b` by the next number in `a`.
            i++; @@ Skips the operand in `a`.
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1];
            i++;
        }
        else
        {
            b[j]=a[i]; @@ Copies numbers and operators from `a` to `b`. Note that operators are still ASCII codes here.
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+') @@ Checks if element in `b` is '+' (ASCII 43).
        {
            r+=b[i+1];
        }
        else if(b[i]=='-')
        {
            r-=b[i+1];
        }
        else
        {
            continue;
        }
    }
    printf("%d\n",r);
    return 0;
}