#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [a is an int array, but %c reads a char into an int variable without proper type handling; also, the first character might be a space or operator, not necessarily a digit]
    a[0]=a[0]-'0'; // @@ [if the first input character is not a digit (e.g., space or minus sign), subtracting '0' leads to incorrect integer value and logic error]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [a[k-1] is an int that may hold a multi-digit number, so comparing it directly to char literals like '+' is invalid; this condition will always be true for numbers > 9 or negative values, causing incorrect concatenation]
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
                a[k]=c; // @@ [storing a char operator directly into an int array without distinguishing between numbers and operators leads to ambiguous data representation]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [a[i+1] may not be a valid operand if the parsing was incorrect; also, b[j] might not have been properly initialized as a number]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [same issue as above; additionally, integer division by zero could occur if parsing fails]
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ [operators are stored as their ASCII values in a[], so copying them directly into b[] mixes numbers and operator codes, breaking later addition/subtraction logic]
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