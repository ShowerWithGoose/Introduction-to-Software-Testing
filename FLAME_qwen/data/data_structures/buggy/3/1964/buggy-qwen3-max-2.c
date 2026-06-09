#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char num[1005];
    int len,mid1,mid2,result; 
    int flag=0;
    gets(num); // @@ [Use of unsafe function 'gets' which has been removed from modern C standards; may cause compilation error with strict compilers]
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
    result=mid1-mid2; // @@ [Logic error: when input starts with non-zero digit (e.g., "123.45"), mid2 (position of '.') is set correctly, but mid1 is 0, so result = 0 - position_of_dot, which is negative; however, the program treats this as a small number (<1) case, which is incorrect]
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
        printf("e-%d",result); // @@ [Incorrect exponent sign: for numbers >=1, exponent should be positive, but here it's printed with a minus sign due to flawed logic in computing 'result']
    }
    return 0;
}