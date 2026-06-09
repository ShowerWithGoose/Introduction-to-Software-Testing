#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=') // @@ [Accessing c[-1] on first iteration (j=0), which is undefined behavior and may cause crash or incorrect loop entry]
    {
        scanf("%d",&a[j]);
        scanf("%c",&c[j]);
        while(c[j]==' ') // @@ [This loop does not skip multiple spaces correctly; it only re-reads one char if it's a space, but doesn't consume all leading/trailing spaces properly]
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
    printf("%d",sum); // @@ [Missing newline in output; though not always required, some test environments expect it. However, primary errors are logic and memory safety issues above. Also, program lacks return statement in main(), which is allowed in C99+ but may cause warnings or issues in strict environments.]
 }