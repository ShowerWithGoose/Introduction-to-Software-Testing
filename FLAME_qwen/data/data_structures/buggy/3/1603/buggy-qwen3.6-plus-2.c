#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a);
    int len = strlen(a);
    if(a[0] == '0')
    {
        for(i = 1; i < len ; i++)
        {
            if(a[i] == '0' && a[i+1] != '0') // @@ Logical error: Fails to correctly find the first non-zero digit after the decimal point (e.g., skips "0.1") and does not properly handle the '.' character.
            {
                flag = i + 1;
                break;
            }
        }
        if(a[flag + 1] == '\0') // @@ Logical error: Relies on the incorrectly computed `flag` and uses an off-by-one index to check for the end of the string.
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
            } // @@ Logical error: The array `b` is not explicitly null-terminated after copying characters, causing `printf("%s",b)` to print garbage.
            printf("%s",b); // @@ Logical error: Prints an unterminated string `b`, leading to undefined behavior.
            printf("e-%d",flag - 1);
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
       for(i = 0 ; i < len ; i++)
       {
           if(a[i+1] != '.') // @@ Logical error: Checks `a[i+1]` instead of `a[i]`, causing out-of-bounds access when `i=len-1` and incorrectly copying the null terminator.
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       } // @@ Logical error: String `b` is not null-terminated here, which may cause undefined behavior when printed.
       printf("%s",b); // @@ Logical error: Prints the unterminated string `b`, resulting in undefined behavior.
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}