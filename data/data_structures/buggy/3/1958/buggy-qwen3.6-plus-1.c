#include<stdio.h>
#include<string.h>
int main()
{
    char num[101]={},changenum[101]={}; // @@ [Compilation Error: Empty initializer list {} is not valid in standard C (it is a C++ feature). Use {0} to zero-initialize arrays in C.]
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
        printf("e-%d",n); // @@ [Logical Error: For numbers less than 1, the exponent should be -(number of leading zeros after the decimal point + 1). Since n counts the zeros, the correct exponent is -(n+1).]
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