#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [Type mismatch: 'a' is an int array, but reading a char into it via %c causes undefined behavior. Also, treating operators and numbers in same int array leads to logic errors.]
    a[0]=a[0]-'0'; // @@ [If first character is not a digit (e.g., negative number not handled, but more critically, if input starts with space or operator, this breaks. Also, after scanf %c, if it's '=', program fails.]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [Comparing int array element (which may hold a multi-digit number) to char literals like '+' is invalid. a[k-1] is an integer value, not a character code.]
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
                a[k]=c; // @@ [Storing char operator directly into int array without conversion; later comparisons treat it as int, which may work numerically but logic is flawed due to mixed types.]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [Incorrect indexing: b[j] was just decremented, but b[j] may not have been initialized properly. Also, a[i+1] might be an operator, not a number.]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [Same issue as above: a[i+1] may not be a valid operand; also integer division by zero not handled, but more critically logic assumes operands are adjacent in a[], which they aren't due to mixed storage.]
            i++;
        }
        else
        {
            b[j]=a[i];
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