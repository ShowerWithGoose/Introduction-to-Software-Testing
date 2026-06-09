#include<stdio.h>
#include<string.h>
int main()
{
    long long b,  c=1,f,g[100],h=0;
    char d[200],e,a[200];
    gets(a);
    for(int i=0; a[i]!='.'; i++)
    {
        b=i;
    }
    f=strlen(a);
    if(a[0]>'0')
    {
        for(int i=1; i<=f; i++)
            {
                if(i==b+2)
                    continue;
                printf("%c",a[i-1]);
                if(i==1)
                    printf(".");
            }
        printf("e%lld",b);
    }
    else if(a[0]=='0')
    {
        if(a[2]!='0')
            {
                h=1;
            }
        else
        for(int i=2; a[i]=='0'; i++)
        {
            h=i;
        }
        for(int i=h+1; a[i]!='\0'; i++)
            {
                printf("%c",a[i]);
                if(i==h+1&&a[i+1]!='\0')
                    printf(".");
            }
            printf("e%lld",-h);
    }
    else if(a[0]=='-'&&a[1]=='0')
    {
        for(int i=3; a[i]=='0'; i++)
        {
            h=i;
        }
        printf("-");
        for(int i=h+1; a[i]!='\0'; i++)
            {
                printf("%c",a[i]);
                if(i==h+1&&a[i+1]!='\0')
                    printf(".");
            }
            printf("e%lld",-h+1);
    }
     else if(a[1]>'0'&&a[0]=='-')
    {
        printf("-");
        for(int i=1; i<=f; i++)
            {
                if(i==b+1)
                    continue;
                printf("%c",a[i]);
                if(i==1)
                    printf(".");
            }
        printf("e%lld",b-1);
    }
    return 0;
}



