#include<stdio.h>
#include<math.h>
int main()
 {
    char s[1000];
    gets(s);
    char *p,*q;
    p=q=s;
    int a,b=0,flag=0,sum=0;
    if(*p!='0') flag=1;
    if(*p=='0'&&strlen(s)==1)
    {
        printf("0e0");
        return 0;
    }
    while(*p!='\0')
    {
        if(*p=='.')
        {
            b=0;
            p++;
            while(*p=='0')
            {
                b++;
                p++;
            }
            break;
        }
        p++;
        sum++;
    }

    if(flag==0) {
        printf("%d",*p-'0');
        p++;
        if(*p=='\0') printf("e-%d",b+1);
        else
        {
            printf(".");
            for(;*p!='\0';p++)
            {
                printf("%d",*p-'0');
            }
            printf("e-%d",b+1);
        }
    }
    else
    {
       printf("%d.",*q-'0');
       q++;
       for(;*q!='.';q++)
       {
           printf("%d",*q-'0');
       }
       q++;
       for(;*q!='\0';q++)
       {
           printf("%d",*q-'0');
       }
       printf("e%d",sum-1);
    }

 }

