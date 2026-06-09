#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=') // @@ [Accessing c[-1] on first iteration (j=0), which is undefined behavior; also, loop condition checks previous character before reading current one, leading to incorrect termination logic]
    {
        scanf("%d",&a[j]);
        scanf("%c",&c[j]); // @@ [Does not skip whitespace properly; reads any character including spaces, but subsequent while loop tries to replace it without advancing input correctly]
        while(c[j]==' ') // @@ [This loop re-reads into same c[j] without consuming new input correctly; also, if c[j] is not space, it skips, but initial read may have read a space and then this overwrites it incorrectly]
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
            d=c[k-1]; // @@ [When k=0, c[-1] is accessed, which is out-of-bounds and undefined behavior]
            a[k+1]=a[k]*a[k+1];
            a[k]=0;
            c[k]=d;
        }
        if(c[k]=='/')
        {
            d=c[k-1]; // @@ [Same as above: when k=0, accesses c[-1], undefined behavior]
            a[k+1]=a[k]/a[k+1];
            a[k]=0;
            c[k]=d;
        }
    }
    for(k=0;k+1<j;k++) // @@ [Loop runs up to k = j-2, but expression may have j operators and j+1 numbers; indexing a[k+1] may miss last term or cause misalignment due to earlier flawed parsing]
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