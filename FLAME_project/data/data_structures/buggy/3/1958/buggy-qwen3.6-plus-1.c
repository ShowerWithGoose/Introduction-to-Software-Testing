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
            changenum[i]=num[1+n+i];

          }
        }
        printf("%s",changenum);
        printf("e-%d",n+1); // @@ The exponent calculation is incorrect. For input "0.9", n is 0 (no zeros after decimal point before significant digit). The position of the first significant digit '9' is at index 2. The exponent should be -(number of places the decimal point moves to the right to get to the first significant digit). For 0.9, it becomes 9 * 10^-1. The current code prints e-0. The correct exponent is -(n + 1) because we skip '0' and '.', so the first significant digit is at index 2+n. The exponent is -(2+n - 1) = -(n+1). Wait, let's re-evaluate. 0.009 -> n=2 (zeros at index 2,3). First sig digit at index 4. Value is 9 * 10^-3. Exponent is -3. Formula: -(n+1) = -(2+1) = -3. Correct. For 0.9, n=0. Exponent should be -1. Formula: -(0+1) = -1. Correct. The original code had `n`, which resulted in 0.
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
                changenum[i]=num[i];
           }
           printf("%s",changenum);
           printf("e%d",n-1);
        }
    }





   return 0;
}