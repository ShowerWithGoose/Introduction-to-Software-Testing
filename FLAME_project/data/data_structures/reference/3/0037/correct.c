#include<stdio.h>
#include<string.h>
int main()
{
    char num[1000];
    scanf("%s",num);
    int len=strlen(num);
    if(num[0]=='0')
    {
        int n=2;
        while(num[n]=='0')
        {
            n++;
        }
      //  printf("%d\n",n);
        printf("%c",num[n]);
        if(num[n+1]!='\0')
            printf(".");
        for(int i=n+1;i<len;i++)
        {
            printf("%c",num[i]);
        }
        printf("e-%d",n-1);
    }
    else if(num[0]!='0')
    {
        int n=1;
        printf("%c.",num[0]);
        while(num[n]!='.')
        {
            printf("%c",num[n]);
            n++;
        }
        int m=n-1;
        n++;
        while(num[n]!='\0')
        {
            printf("%c",num[n]);
            n++;
        }
        printf("e%d",m);
    }
}

