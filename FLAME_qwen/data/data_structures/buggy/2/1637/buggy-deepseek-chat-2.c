#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ Error: a[0] is declared as int array, but scanf reads a character. This stores ASCII value, not the digit. Also, the first character may be a space or operator, causing incorrect initialization.
    a[0]=a[0]-'0'; // @@ Error: If the first character is not a digit (e.g., space or operator), subtracting '0' produces a meaningless value.
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ Error: a[k-1] is an integer, but it is compared with character constants. This comparison is incorrect because a[k-1] stores numeric values (e.g., 5) not character codes (e.g., '5'). It will never match the operators.
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
                a[k]=c; // @@ Error: a[k] is an int array, but storing a character (e.g., '+') as an integer. This mixes numeric values and character codes, causing issues in later comparisons.
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*') // @@ Error: a[i] stores either a numeric digit or a character code. Comparing with '*' may work if the operator was stored as character, but the logic is inconsistent.
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ Error: a[i+1] is a numeric digit (0-9), not the actual number. This only multiplies by a single digit, not the full number.
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ Error: Same issue as multiplication - uses single digit instead of full number.
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ Error: b[j] stores the numeric value of a digit (0-9) or a character code of an operator. This mixes types incorrectly.
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+') // @@ Error: b[i] may contain character codes for operators, but also numeric values. The comparison may work for operators but the logic is flawed due to mixed storage.
        {
            r+=b[i+1]; // @@ Error: b[i+1] is a single digit value, not the full number. This leads to incorrect arithmetic.
        }
        else if(b[i]=='-')
        {
            r-=b[i+1]; // @@ Error: Same issue as addition.
        }
        else
        {
            continue;
        }
    }
    printf("%d\n",r);
    return 0;
}