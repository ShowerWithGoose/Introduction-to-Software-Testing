#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=') // @@ [Accessing c[-1] on first iteration (j=0), which is undefined behavior; also logic fails to stop at '=' correctly]
    {
        scanf("%d",&a[j]);
        scanf("%c",&c[j]);
        while(c[j]==' ')
        {
            scanf("%c",&c[j]);
        }    
        j++;
    }
    sum=a[0];
    for(k=0;k<j;k++)
    {
        if(c[k]=='*')
        {
            d=c[k-1]; // @@ [When k=0, c[-1] is accessed, which is invalid; also overwrites current operator with previous one incorrectly]
            a[k+1]=a[k]*a[k+1];
            a[k]=0;
            c[k]=d;
        }
        if(c[k]=='/')
        {
            d=c[k-1]; // @@ [Same issue: accessing c[-1] when k=0; incorrect handling of operator precedence and expression structure]
            a[k+1]=a[k]/a[k+1];
            a[k]=0;
            c[k]=d;
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
    printf("%d",sum); // @@ [Final result is wrong due to multiple logical errors in parsing and operator precedence handling]
 }