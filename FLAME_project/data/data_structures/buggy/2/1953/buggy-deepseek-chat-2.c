#include<stdio.h>
#include<string.h>
int a[100];
char b[100]={'\0'};
char c[100]={'\0'};
char d;
int main()
{
    int i=0,j=0,k,sum=0;
    while(c[j-1]!='=')
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
            d=c[k-1]; // @@ Error: When k=0, c[k-1] accesses c[-1], which is out of bounds. Also, the logic of saving and restoring the operator is flawed; it should not overwrite c[k] with the previous operator.
            a[k+1]=a[k]*a[k+1];
            a[k]=0;
            c[k]=d;
        }
        if(c[k]=='/')
        {
            d=c[k-1]; // @@ Error: Same issue as above; when k=0, c[k-1] is out of bounds. Additionally, the approach of setting a[k]=0 and modifying c[k] disrupts the subsequent addition/subtraction loop because it changes the operator sequence and zeroes out numbers that may be needed.
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