#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [a is an int array, but %c reads a char into an int variable without proper handling; also, the first character might be a space or operator, not necessarily a digit]
    a[0]=a[0]-'0'; // @@ [if the first input character is not a digit (e.g., space or sign), subtracting '0' leads to incorrect value; also, if input starts with space, this logic fails]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [a[k-1] is an int that may hold a number, but comparing it directly to char literals like '+' is invalid because numbers and operators are stored in the same int array without type distinction]
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
                a[k]=c; // @@ [storing a char operator directly into an int array without distinguishing between numbers and operators causes ambiguity during evaluation]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [a[i+1] may be an operator or number, but since a[] mixes both types as ints, accessing a[i+1] as a number is unsafe; also, no bounds check]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [same issue: a[i+1] might not be a valid operand; also integer division is required but logic assumes correct parsing]
            i++;
        }
        else
        {
            b[j]=a[i];
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++) // @@ [loop condition should likely be i < j-1 since b[i+1] is accessed; current loop may access out-of-bounds when i == j-1]
    {
        if(b[i]=='+')
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