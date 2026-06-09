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

     w=strlen(aa); // @@ Error: After removing spaces, the length of aa is not updated correctly because the loop above may not have null-terminated aa properly, and using strlen on aa may read garbage or incorrect length. Also, the original w from a is overwritten.
    for(int i=0,n=0;i<w;n++,i+=2) // @@ Error: The loop logic is flawed. It assumes numbers and operators alternate with single-digit numbers, but numbers can have multiple digits. The increment i+=2 and n++ do not correctly parse the expression.
    {
        sscanf(aa,"%d%c",&b[n],&c[n]); // @@ Error: sscanf always reads from the beginning of aa, not from the current position. This will repeatedly parse the same first number and operator, leading to incorrect results.
        int u;
        for(u=0;;u++)
        {
            if(pow(10,u)>b[n]) // @@ Error: Using pow(10,u) with floating point may cause precision issues for large numbers. Also, the loop condition is inefficient and may not correctly determine the number of digits.
            break;
        }
        for(int k=0;k<w-2*n;k++) // @@ Error: This loop attempts to shift the aa array but uses incorrect bounds and logic. It does not properly remove the parsed number and operator from the string.
        {
            aa[k]=aa[k+1+u];
        }
    }
    w=strlen(c); // @@ Error: c is not null-terminated properly, so strlen may read garbage. Also, the length of c should correspond to the number of operators, which is not correctly computed.
    for(int i=0;i<w;i++)
    {
        if(c[i]=='*')
        {
            b[i+1]=b[i]*b[i+1];
            b[i]=0;
            if(i==0||c[i-1]=='+') // @@ Error: This logic for updating operators after multiplication/division is incorrect. It does not handle cases where there are multiple consecutive * or / operators, and the condition for updating c[i] is flawed.
            c[i]='+';
            if(c[i-1]=='-')
            c[i]='-';
        }
        if(c[i]=='/')
        {
            b[i+1]=b[i]/b[i+1];
            b[i]=0;
            if(c[i-1]=='+'||i==0) // @@ Error: Same issue as above for division. The logic for updating operators is incorrect.
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