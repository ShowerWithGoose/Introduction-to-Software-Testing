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
    result=mid1-mid2; // @@ [If input starts with non-zero digit (e.g., "123.45"), mid2 ('.' position) is set, but if input is like "0.001", mid2 is set correctly. However, if the number has no '.' (though problem says it does), mid2 remains uninitialized, leading to undefined behavior. But more critically, in cases where the first non-zero digit is before '.', result = mid1 - mid2 becomes negative of what's expected for exponent calculation. Also, mid1 might be used uninitialized if all digits are zero, though problem states all digits are significant and there's at least one non-zero. Still, logic for exponent sign and magnitude is flawed.]
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
        printf("e%d",-result-1); // @@ [Exponent calculation is incorrect. For input "0.001", mid1=2 (digit '1'), mid2=1 ('.'), result=1, so this branch isn't taken. Actually, result = 2 - 1 = 1 >=0, so goes to else branch which prints "1e-1", but expected is "1e-3". The core issue is wrong relation between positions and exponent.]
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
        printf("e-%d",result); // @@ [This prints negative exponent when result>=0, but for numbers >=1 (e.g., "123.45"), exponent should be positive. Also, the base printed here lacks a decimal point after the first digit, violating output format which requires either "d." or "d.d...". For "123.45", it prints "12345e-2" instead of "1.2345e2".]
    }
    return 0;
}