#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [a[0] is of type int, but %c expects a char*; also, storing char in int array without proper handling leads to logic errors]
    a[0]=a[0]-'0'; // @@ [If the first character is not a digit (e.g., '-', '+'), subtracting '0' gives incorrect value; also assumes first token is a digit]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [a[k-1] is an int that may hold a multi-digit number, not a char; comparing it to char literals like '+' is invalid]
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
                a[k]=c; // @@ [Storing operator char directly into int array without distinguishing between numbers and operators causes type confusion later]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [a[i+1] might be an operator or uninitialized; also, b[j] may not have been properly initialized as a number]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [Same issue: a[i+1] may not be a valid operand; integer division assumed but operands may be corrupted]
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ [Operators are stored as their ASCII values in b[], which breaks later addition/subtraction logic]
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
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