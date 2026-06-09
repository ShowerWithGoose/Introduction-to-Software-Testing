#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char num[1005];
    int len,mid1,mid2,result; 
    int flag=0;
    gets(num); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
    result=mid1-mid2; // @@ [If input starts with non-zero digit (e.g., "123.45"), mid2 ('.' position) is set, but if input is like "0.001", mid2 is set correctly. However, if the number has no decimal point (though problem states it does), mid2 remains uninitialized, leading to undefined behavior. But more critically, logic for exponent calculation is flawed.]
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
        printf("e-%d",result); // @@ [Exponent sign is inverted: when result >= 0 (i.e., first non-zero digit is before or at decimal point), exponent should be positive, but code prints negative exponent. Also, in this branch, it assumes the number is less than 1, which is incorrect.]
    }
    return 0;
}