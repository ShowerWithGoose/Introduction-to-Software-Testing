#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [a is an int array, but %c reads a char into an int variable's address; also, the first character might be a space or operator, not necessarily a digit]
    a[0]=a[0]-'0'; // @@ [if the first character read was not a digit (e.g., space or sign), subtracting '0' leads to incorrect value; also, if input starts with '-', this breaks]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [a[k-1] is an int that may hold a multi-digit number, so comparing it directly to char literals like '+' is invalid; e.g., if a[k-1] is 12, it's not equal to '+', but the logic assumes it's a number]
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
                a[k]=c; // @@ [storing char operator directly into int array without conversion; later comparisons like a[i]=='*' will work by coincidence due to ASCII, but mixing numbers and chars in same int array causes logical errors]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [a[i+1] may be a char code if it's an operator, or a number; but after parsing, a[] contains mixed types: numbers as ints and operators as char codes, leading to incorrect arithmetic]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [same issue: a[i+1] might not be a valid operand if parsing failed earlier]
            i++;
        }
        else
        {
            b[j]=a[i];
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++) // @@ [loop condition should likely be i < j-1 since we access b[i+1]; also, b[] now contains mixed numbers and operator char codes, so checking b[i]=='+' compares int to char literal, which may work numerically but logic is broken due to prior errors]
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