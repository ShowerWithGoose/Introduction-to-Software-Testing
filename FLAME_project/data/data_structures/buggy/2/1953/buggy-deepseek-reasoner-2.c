#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=')@@ // Error: out-of-bounds access c[-1] when j=0; undefined behavior and incorrect loop logic
    {
        scanf("%d",&a[j]);
        scanf("%c",&c[j]);
        while(c[j]==' ')
        {
            scanf("%c",&c[j]);
        }    
        j++;
    }
    sum=a[0];@@ // Error: a[0] may later be set to 0 during multiplication/division, losing the first operand's value
    for(k=0;k<j;k++)
    {
        if(c[k]=='*')
        {
            d=c[k-1];@@ // Error: out-of-bounds access c[-1] when k=0; incorrect logic using previous operator
            a[k+1]=a[k]*a[k+1];@@ // Error: incorrect handling of left-associative multiplication; does not preserve order for multiple same-precedence operators
            a[k]=0;
            c[k]=d;@@ // Error: corrupts operator array with irrelevant or garbage value, affecting subsequent addition/subtraction
        }
        if(c[k]=='/')
        {
            d=c[k-1];@@ // Error: same as line 25; out-of-bounds and incorrect logic
            a[k+1]=a[k]/a[k+1];@@ // Error: same as line 26; incorrect left-associative division handling
            a[k]=0;
            c[k]=d;@@ // Error: same as line 28; corrupts operator array
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