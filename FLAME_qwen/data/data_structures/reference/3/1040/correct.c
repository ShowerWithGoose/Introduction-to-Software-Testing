#include<stdio.h>     
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h> 
#include<limits.h>
int main()
{
    char a[1000],b[1000],c[1000];
    char* p=b;
    char* q=c;
    gets(a);
    int i;
    for(i=0;a[i]!='.';i++)
    {
        *p=a[i];
        p++;
    }
    b[i]='\0';
    int j;
    for(j=i+1;a[j]!='\0';j++)
    {
        *q=a[j];
        q++;
    }
    c[j-i-1]='\0';

    int num=0;
    for(j=0;b[j]!='\0';j++)
    {
        num=num*10+b[j]-'0';
    }

    char d[1000],e[1000];
    char* m=d;
    char* n=e;
    int k=0,sum=0;
    if(num==0)
    {
        while(c[k]=='0')
            k++;
        sum=k+i;
        if(k==strlen(c)-1)
            printf("%de-%d",c[k]-'0',sum);
        else
        {
            for(j=k+1;c[j]!='\0';j++)
            {
                *m=c[j];
                m++;
            }
            d[j-k-1]='\0';
            printf("%d.",c[k]-'0');
            for(j=0;d[j]!='\0';j++)
                printf("%d",d[j]-'0');
            printf("e-%d",sum);
        }
    }
    else
    {
        sum=i-1;
        printf("%d.",b[0]-'0');
        for(j=1;b[j]!='\0';j++)
            printf("%d",b[j]-'0');
        for(j=0;c[j]!='\0';j++)
            printf("%d",c[j]-'0');
        printf("e%d",sum);
    }
    //printf("%d",sum);
    return 0;
}


