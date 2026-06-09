#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char a[200];
int main()
{
    int i=0,n,m=0,num=0,f=0;
    gets(a);
    n=strlen(a);
    while(i<n)
    {
        if(a[i]=='.')
            break;
        i++;
    }
    if(i==1)
    {
        if(a[0]!='0')
            printf("%se0\n",a);
        else
        {
            for(int j=2;j<n;j++)
        {
            if(a[j]=='0')
                m++;
            else
                break;
        }
        printf("%c",a[m+2]);
            if(m+3<n)
            printf(".");
        for(int j=m+3;j<n;j++)
            printf("%c",a[j]);
        printf("e-%d\n",m+1);
        }
    }
    else
    {
         printf("%c",a[0]);
         for(int j=1;j<n;j++)
             if(a[j]!='0')
             {
              f=1;
             break;
             }
             if(f)
            printf(".");
        for(int j=1;j<n;j++)
       {
           if(j!=i&&f==1)
               printf("%c",a[j]);
           if(j<i)
               num++;
       }
       printf("e%d\n",num);
    }
return 0;
}

