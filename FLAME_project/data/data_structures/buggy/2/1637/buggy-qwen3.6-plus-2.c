#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ The variable 'a' is an integer array, but scanf with %c reads a character into the first byte. More critically, if the input starts with a space or newline, this logic fails to handle multi-digit numbers or initial spaces correctly compared to the robust tokenization needed. However, the immediate crash/wrong answer for "0 =" comes from later logic.
    a[0]=a[0]-'0'; // @@ This assumes the first character read was a digit. If input is " 0 =", scanf reads ' ', a[0] becomes ' ' (32), then 32-'0' is -16. This corrupts the first number.
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ This check is flawed because a[k-1] holds integer values of numbers, not just characters representing operators. If a[k-1] is a number like 10, it doesn't equal '+', so it tries to multiply: a[k-1] = 10 * 10 + new_digit. This works for building numbers ONLY IF the previous slot wasn't an operator. But since operators are stored as their ASCII values (e.g., '+' is 43) in the same int array, checking against char literals '+' works by coincidence of ASCII values, BUT the logic for distinguishing "previous was number" vs "previous was operator" is fragile and broken by the initialization and space handling.
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
                a[k]=c; // @@ Stores operator as ASCII value in integer array.
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*') // @@ Checks if current element is multiplication operator.
        {
            j--; // @@ Decrements j to overwrite the last number added to b.
            b[j]=b[j]*a[i+1]; // @@ Multiplies the last number in b by the next number in a.
            i++; // @@ Skips the number after '*' because it's consumed.
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1];
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ If it's not * or /, it copies the value to b. This includes numbers AND operators (+, -). This mixes numbers and operators in array b.
        }
        j++; // @@ Increments j regardless. This logic is fundamentally broken for separating numbers and operators for the final summation step because '+' and '-' are stored in b alongside numbers.
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+') // @@ Checks if element in b is '+'. Since b contains mixed numbers and operators, this attempts to find operators.
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