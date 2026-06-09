#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=') // @@ Accessing c[-1] causes out-of-bounds undefined behavior; loop condition should check the last successfully read character.
    {
        scanf("%d",&a[j]);
        scanf("%c",&c[j]); // @@ %c does not skip whitespace; will read spaces/newlines incorrectly. Should use " %c" to skip leading whitespace.
        while(c[j]==' ')
        {
            scanf("%c",&c[j]);
        }    
        j++;
    }
    sum=a[0]; // @@ Initializing sum with a[0] is incorrect because a[0] is set to 0 during the *// pass, losing the first operand.
    for(k=0;k<j;k++)
    {
        if(c[k]=='*')
        {
            d=c[k-1]; // @@ When k=0, c[-1] is accessed causing out-of-bounds error; logic for handling precedence is fundamentally flawed.
            a[k+1]=a[k]*a[k+1];
            a[k]=0;
            c[k]=d; // @@ Restoring the previous operator here fails to correctly collapse the expression for the addition/subtraction pass.
        }
        if(c[k]=='/')
        {
            d=c[k-1]; // @@ Same out-of-bounds access when k=0 and incorrect precedence handling logic.
            a[k+1]=a[k]/a[k+1];
            a[k]=0;
            c[k]=d; // @@ Incorrect operator restoration; should replace with '+' or mark as processed to avoid double counting.
        }
    }
    for(k=0;k+1<j;k++)
    {
        if(c[k]=='+')
        {
            sum=sum+a[k+1];
        }
        if(c[k]=='-')
        {
            sum=sum-a[k+1];
        }
    }
    printf("%d",sum);
 }