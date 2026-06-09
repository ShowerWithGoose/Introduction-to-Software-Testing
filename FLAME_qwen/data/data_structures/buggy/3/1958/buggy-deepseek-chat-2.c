#include<stdio.h>
#include<string.h>
int main()
{
    char num[101]={},changenum[101]={};
    int i,j,n=0;
    gets(num);
    if(num[0]=='0')
    {
        for(i=2;i<strlen(num);i++)
        {
            if(num[i]=='0')
            {
                n++;
            }
            else
                break;
        }
        if(n==strlen(num)-3)
        {
            changenum[0]=num[n+2];
        }
        else
        {
            for(i=0;i<strlen(num)-1-n;i++)
          {
            if(i==0)
            changenum[i]=num[2+n];
            else if(i==1)
            changenum[1]='.';
            else
            changenum[i]=num[1+n+i]; // @@ [Error: Index out of bounds. When i >= 2, the expression 1+n+i may exceed the length of num, causing undefined behavior. Also, the logic for copying digits after the decimal point is incorrect; it should skip the decimal point and leading zeros properly.]

          }
        }
        printf("%s",changenum);
        printf("e-%d",n);
    }
    else
    {
        for(i=0;i<strlen(num);i++)
        {
            if(num[i]!='.')
                n++;
            else
                break;
        }
        if(n==1)
        {
            printf("%s",num);
            printf("e0");
        }
        else
        {
            for(i=0;i<strlen(num);i++)
           {
               if(i==0)
               changenum[i]=num[i];
               else if(i==1)
               changenum[i]='.';
               else if(i>1&&i<=n)
               changenum[i]=num[i-1]; // @@ [Error: When i > n, the else branch uses num[i] which includes the decimal point, but the decimal point should be skipped. This results in an extra '.' in the output.]
               else
                changenum[i]=num[i];
           }
           printf("%s",changenum);
           printf("e%d",n-1);
        }
    }





   return 0;
}