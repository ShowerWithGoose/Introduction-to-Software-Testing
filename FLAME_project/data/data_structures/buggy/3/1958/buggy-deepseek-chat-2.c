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
            changenum[i]=num[1+n+i]; // @@ The index calculation is incorrect. For i>=2, it should be num[2+n+i-1] or num[1+n+i] is off by one, causing missing or wrong digits. The correct index should be num[2+n+i-1] to skip the decimal point and leading zeros.

          }
        }
        printf("%s",changenum);
        printf("e-%d",n); // @@ The exponent should be n+1, not n. For input "0.9", n=0 (no zeros after decimal point), but the exponent should be -1, not -0. The exponent is the number of places the decimal point moved, which is n+1.
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
               changenum[i]=num[i-1];
               else
                changenum[i]=num[i]; // @@ For i > n, this copies the original digits including the decimal point, but the decimal point should be removed. The correct approach is to shift digits after the decimal point left by one position, or handle the copying differently to exclude the decimal point.
           }
           printf("%s",changenum);
           printf("e%d",n-1);
        }
    }





   return 0;
}