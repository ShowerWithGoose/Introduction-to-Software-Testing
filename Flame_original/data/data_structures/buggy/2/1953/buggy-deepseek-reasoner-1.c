#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=') // @@ Accessing c[-1] when j=0 is undefined behavior; may cause crash or wrong behavior.
    {
        scanf("%d",&a[j]);
        scanf("%c",&c[j]);
        while(c[j]==' ') // @@ This loop overwrites c[j] repeatedly without incrementing j; logic for skipping spaces is flawed.
        {
            scanf("%c",&c[j]); // @@ Overwrites the same c[j] index, does not advance j; may cause infinite loop or missing characters.
        }    
        j++;
    }
    sum=a[0];
    for(k=0;k<j;k++)
    {
        if(c[k]=='*')
        {
            d=c[k-1]; // @@ When k=0, c[-1] is out-of-bounds (undefined behavior). Also, for expressions starting with '*' or '/', this is invalid.
            a[k+1]=a[k]*a[k+1];
            a[k]=0;
            c[k]=d;
        }
        if(c[k]=='/')
        {
            d=c[k-1]; // @@ Same out-of-bounds issue for k=0.
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
    printf("%d",sum);
 }