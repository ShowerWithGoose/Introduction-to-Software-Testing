#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it's deprecated. However, the main logic errors are elsewhere.]
    int len = strlen(a);
    if(a[0] == '0')
    {
        for(i = 1; i < len ; i++)
        {
            if(a[i] == '0' && a[i+1] != '0')
            {
                flag = i + 1;
                break;
            }
        }
        if(a[flag + 1] == '\0') // @@ [If the input is "0.9", then after the loop, flag remains 0 (since condition a[i]=='0' && a[i+1]!='0' never holds), so a[flag+1] is a[1] which is '.', leading to incorrect logic. Also, flag is uninitialized in cases like "0.9" where there are no zeros after decimal before first non-zero.]
        {
            printf("%ce-%d",a[flag],flag - 1);
            return 0;
        }
        else
        {
            b[0] = a[flag];
            b[1] = '.';
            for(k = 0 ;  k < len - flag - 1 ; k++)
            {
                b[k+2] = a[flag + k + 1];
            }
            printf("%s",b);
            printf("e-%d",flag - 1); // @@ [When input is "0.9", flag remains 0 (loop doesn't set it), so flag-1 = -1, but also a[flag] = a[0] = '0', leading to output starting with '0', which violates scientific notation rules. The logic to find first non-zero digit after decimal is flawed.]
            return 0;
        }


    }
    else
    {
       while(a[i] != '.')
       {
           i++;
           num++;
       }
       b[0] = a[0];
       b[1] = '.';
       for(i = 0 ; i < len ; i++) // @@ [This loop iterates over entire string, but uses a[i+1] which goes out of bounds when i = len-1. Also, it copies digits including the part before decimal again, causing duplication (e.g., for "12.34", it would copy '2' twice). Moreover, it doesn't skip the decimal point correctly, leading to extra '.' or wrong digits.]
       {
           if(a[i+1] != '.') // @@ [Accessing a[i+1] when i can be len-1 leads to undefined behavior (reading past end of string). Also, this condition fails to properly collect digits after the decimal point without including the decimal itself or duplicating digits.]
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       printf("%s",b);
       printf("e%d",num - 1); // @@ [For input like "5.0", num becomes 1 (since one digit before '.'), so exponent is 0, which is correct, but the base becomes "5." followed by garbage because b is not null-terminated. Also, for single-digit integer part like "9.0", it should output "9e0", but current code outputs "9.e0" or similar due to improper handling.]
       return 0;
    }

    return 0;
}