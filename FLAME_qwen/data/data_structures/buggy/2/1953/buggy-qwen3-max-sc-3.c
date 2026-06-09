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
        while(c[j]==' ') // @@ [This loop does not skip all spaces correctly; it only re-reads one character if it's a space, but doesn't consume subsequent spaces or handle operator reading properly]
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
            d=c[k-1]; // @@ [Same as above: when k=0, accessing c[-1] is invalid]
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
    printf("%d",sum); // @@ [Missing newline in output; though not causing compilation error, it may affect output format. However, primary issue is logic and undefined behavior above. Also, function missing return statement, which in C90 leads to undefined behavior (though many compilers allow it).]
 }