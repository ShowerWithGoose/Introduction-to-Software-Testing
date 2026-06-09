#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char num[1005];
    int len,mid1,mid2,result; 
    int flag=0;
    gets(num); // @@ [Use of unsafe function 'gets' which has been removed from C11 standard; may cause compilation error with modern compilers]
    len=strlen(num);
    for(int i=0;i<len;i++)
    {
        if(num[i]=='.')
        mid2=i;
        else if(num[i]!='0'&&flag==0)
        {
            mid1=i;
            flag=1;
        }
    }  
    result=mid1-mid2; // @@ [Logic error: when input starts with non-zero digit (e.g., "123.45"), mid2 (position of '.') is set correctly, but mid1 is 0, so result = 0 - mid2 = negative, leading to wrong branch and incorrect exponent calculation]
    if(result<0)
    {
        printf("%c.",num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e%d",-result-1);
    }
    else
    {
        printf("%c",num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e-%d",result); // @@ [Incorrect exponent sign: for numbers >= 1 (e.g., "123.45"), exponent should be positive, but this prints "e-..." due to flawed logic in result calculation]
    }
    return 0;
}