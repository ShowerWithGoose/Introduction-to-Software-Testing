#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int a[100]={0};
    char b[100],c[100],d[100];
    int i,k,j,n=0,num;
    gets(d);

    for(i=0,j=0;i<strlen(d);i++)
    {
        if(d[i]!=' ')
        {
            c[j]=d[i];
            c[j+1]='\0';
            j++;
        }
    }
//    printf("%s\n",c);
    for(i=0,j=0,k=0;i<strlen(c);i++)
    {
        if(c[i]>='0'&&c[i]<='9')
        {
            n=n*10+c[i]-'0';
            if(c[i+1]<'0'||c[i+1]>'9')//¼ÆÊý½áÊø 
            {
                a[j]=n;
                j++;
                n=0;
            }
        }
        else
        {
            b[k]=c[i];
            b[k+1]='\0';
            k++;
         } 
    }
    num=k;
//    printf("%s\n",b);
    for(i=0;i<j;i++)
//    printf("%d ",a[i]);
    for(i=0,j=0;i<num-1;)
    {
        if(b[i]=='-')
        {
            a[j+1]=-a[j+1];
        //    printf("%d %d\n",a[j],a[j+1]);
            i++;j++;
            continue;
        }
        else if(b[i]=='+')
        {
            i++;j++;
            continue;
        }
        else if(b[i]=='*')
        {
        //    printf("%d %d\n",a[j],a[j+1]);
            a[j+1]=a[j]*a[j+1];
            a[j]=0;
        //    printf("%d %d\n",a[j],a[j+1]);
            i++;j++;
            continue;
        }
        else if(b[i]=='/'); // @@ [Error: Semicolon after else if condition causes the block to always execute, making division happen for all operators including '+', '-', '*', and also causes the division logic to run even when the operator is '/', but the semicolon terminates the condition, so the following block runs unconditionally, corrupting the calculation.]
        {
            a[j+1]=a[j]/a[j+1];
            a[j]=0;
        ///    printf("%d %d\n",a[j],a[j+1]);
            i++;j++;
            continue;
        }
        
    }
    for(j=0;j<num;j++)
//    printf("%d ",a[j]);
    for(j=0,n=0;j<num;j++)
    {
        n=n+a[j];
    }
    printf("%d",n);
    return 0;
}