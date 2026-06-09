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
            changenum[i]=num[1+n+i]; // @@ Error: The index calculation is incorrect. For input "0.9", n=0, this line becomes changenum[2]=num[1+0+2]=num[3] which is out of bounds. Should be changenum[i]=num[2+n+i-1] or similar to correctly copy the remaining digits after the decimal point.

          }
        }
        printf("%s",changenum);
        printf("e-%d",n); // @@ Error: The exponent should be n+1, not n. For input "0.9", n=0, but the exponent should be -1 (since 0.9 = 9e-1). The exponent is the number of zeros after the decimal point plus one.
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
                changenum[i]=num[i]; // @@ Error: This line does not correctly handle the case when i > n. For example, input "12.34", n=2, when i=3, this copies num[3] which is '4', but the correct character should be num[2] (the digit after the decimal point). The indexing is off by one.
           }
           printf("%s",changenum);
           printf("e%d",n-1);
        }
    }





   return 0;
}