#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100000];
char aa[100000];
char c[100000];
int b[100000];
int main()
{
    gets(a);
    int w=strlen(a);
    for(int i=0,n=0;i<w;i++)
    {
        if(a[i]!=' ')
        {
            aa[n]=a[i];n++;
        }
        
    }

     w=strlen(aa); // @@ Error: After removing spaces, aa may not be null-terminated if the original string had no spaces, but more critically, the logic for parsing numbers and operators is flawed. The sscanf approach and the subsequent loop to shift the array are incorrect and will not correctly extract numbers and operators from the expression.
    for(int i=0,n=0;i<w;n++,i+=2) // @@ Error: The loop condition and increment are incorrect. It assumes each number is a single digit and each operator is one character, which is not true for multi-digit numbers. Also, i+=2 skips characters incorrectly.
    {
        sscanf(aa,"%d%c",&b[n],&c[n]);int u; // @@ Error: sscanf reads from the beginning of aa each time, not from the current position. This will repeatedly read the first number and operator.
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ Error: Using pow(10,u) to determine the number of digits is inefficient and may have floating-point precision issues. Also, the loop condition is flawed; it should be pow(10,u) <= b[n] to count digits.
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ Error: This loop attempts to shift the array but uses incorrect indices and does not properly remove the parsed number and operator from aa.
        {
            aa[k]=aa[k+1+u]; // @@ Error: The shift logic is wrong; it should remove u digits and the operator, but the indexing is off.
        }
    }
    w=strlen(c); // @@ Error: c is not properly null-terminated, and its length may not reflect the actual number of operators.
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1];
            b[i]=0;
            if(i==0||c[i-1]=='+') // @@ Error: This logic for updating operators after multiplication/division is incorrect. It does not handle operator precedence correctly and may produce wrong results.
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
            b[i]=0;
            if(c[i-1]=='+'||i==0) // @@ Error: Same issue as above; operator update logic is flawed.
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
    }
    int m=b[0];
    for(int i=0;i<w;i++)
    {
        if(c[i]=='+')
        m=m+b[i+1];
        if(c[i]=='-')
        m=m-b[i+1];
    }
    printf("%d",m);
    return 0;
}