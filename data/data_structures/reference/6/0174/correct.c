 #include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

int main()
{
    int op,n,stack[MAXSIZE]={0},p=-1,i,flag;
    char a[300];
    gets(a);
    for(i=0;i<strlen(a)-3;i++)
    {
        if(a[i]==' ') continue;
        op=a[i]-'0';
        if(op==1)
        {
            i+=2;
            flag=1;n=0;
            if(a[i]=='-')
            {
                flag=-1;i++;
            }
            for(;a[i]!=' ';i++)
            {
                n=n*10+a[i]-'0';
            }
            n*=flag;
            if(p>=MAXSIZE-1)
            {
                printf("error ");
            }
            else
            {
                p++;stack[p]=n;
            }
        }
        else if(op==0)
        {
            if(p<0)
            {
                printf("error ");i++;
            }
            else
            {
                printf("%d ",stack[p]);
                p--;i++;
            }
        }
    }
    return 0;
}

