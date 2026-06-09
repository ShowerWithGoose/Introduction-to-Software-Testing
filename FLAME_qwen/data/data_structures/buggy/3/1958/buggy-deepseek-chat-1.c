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
            changenum[i]=num[1+n+i]; // @@ [Error: Index out of bounds when copying digits after decimal point. For input like "0.00123", n=2, num[1+n+i] becomes num[3+i], but the loop goes up to strlen(num)-1-n, which may exceed the valid range of num, causing undefined behavior or incorrect output.]
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
               changenum[i]=num[i-1]; // @@ [Error: For numbers like "12.34", n=2, when i=2, num[i-1]=num[1]='2', but the correct digit should be '3' (the first digit after decimal). The indexing logic is incorrect, leading to wrong base output.]
               else
                changenum[i]=num[i]; // @@ [Error: This copies the decimal point and remaining digits incorrectly. For "12.34", when i=3, num[3]='4', but changenum[3] should be '4' (after the inserted decimal point), but the overall array structure is wrong because the decimal point was inserted at index 1, shifting positions.]
           }
           printf("%s",changenum);
           printf("e%d",n-1);
        }
    }





   return 0;
}