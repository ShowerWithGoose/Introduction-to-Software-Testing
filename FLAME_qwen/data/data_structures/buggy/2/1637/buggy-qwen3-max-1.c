#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [Error: 'a' is an int array, but scanf with %c reads a char into an int location; also, the first character might be a space or operator, not necessarily a digit]
    a[0]=a[0]-'0'; // @@ [Error: If the first input character was not a digit (e.g., space or sign), subtracting '0' leads to incorrect value; also, if scanf failed or read '=' immediately, this breaks]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [Error: a[k-1] is an int, but comparing it directly to char literals like '+' is invalid because earlier digits were converted to int values, not stored as chars]
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
                a[k]=c; // @@ [Error: Storing char operators directly into int array without consistent representation; mixing int numbers and char operators in same int array causes type confusion]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*') // @@ [Error: a[i] is an int that may hold either a number or a char code of operator; but after digit conversion, numbers are actual ints, while operators are stored as their ASCII values, so comparison with '*' (ASCII 42) may accidentally match a number 42]
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [Error: a[i+1] might be an operator (stored as ASCII) or a number; using it directly as operand is wrong]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [Same issue: a[i+1] may not be a valid number]
            i++;
        }
        else
        {
            b[j]=a[i];
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++) // @@ [Error: Loop condition should likely be i < j-1 since b[i+1] is accessed]
    {
        if(b[i]=='+') // @@ [Error: b[i] contains mixed data: numbers and operator ASCII codes; comparing to '+' assumes operator is stored as ASCII, but logic is inconsistent]
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