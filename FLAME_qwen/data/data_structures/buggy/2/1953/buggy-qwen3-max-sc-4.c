#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=') // @@ [Accessing c[-1] on first iteration (j=0), which is undefined behavior and may cause runtime crash or incorrect loop condition]
    {
        scanf("%d",&a[j]);
        scanf("%c",&c[j]);
        while(c[j]==' ') // @@ [This inner while loop does not consume additional characters; it re-reads the same character repeatedly if it's a space, causing an infinite loop]
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
            d=c[k-1]; // @@ [When k=0, c[-1] is accessed, leading to undefined behavior]
            a[k+1]=a[k]*a[k+1];
            a[k]=0;
            c[k]=d;
        }
        if(c[k]=='/')
        {
            d=c[k-1]; // @@ [When k=0, c[-1] is accessed, leading to undefined behavior]
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
    printf("%d",sum); // @@ [Missing newline in output; though not always required, some test environments expect it. However, main issue is logic errors above. Also missing return 0; but that's not compilation error. The primary compilation-related issue isn't present—this code compiles—but the reported error was "gcc: not found", which is environmental. However, per instructions, we annotate logical/semantic errors causing wrong output.]
}