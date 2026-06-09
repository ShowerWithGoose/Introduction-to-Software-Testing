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
        for(i = 1; i < len ; i++) // @@ The loop assumes at least one '0' after the decimal point, but for input "0.9" there is no leading zero after the decimal, so flag remains 0, causing incorrect processing.
        {
            if(a[i] == '0' && a[i+1] != '0') // @@ The condition only detects a non-zero digit that follows a zero, missing the case where the first digit after the decimal is already non-zero (e.g., "0.9").
            {
                flag = i + 1;
                break;
            }
        }
        if(a[flag + 1] == '\0')
        {
            printf("%ce-%d",a[flag],flag - 1); // @@ Since flag is 0, a[0] is '0' and exponent is -1, but the base should be the first non-zero digit '9'.
            return 0;
        }
        else
        {
            b[0] = a[flag]; // @@ flag is 0, so b[0] gets '0' instead of '9'.
            b[1] = '.';
            for(k = 0 ;  k < len - flag - 1 ; k++)
            {
                b[k+2] = a[flag + k + 1]; // @@ flag=0, so this copies from a[1] (the decimal point) onward, resulting in an extra '.' in the output.
            }
            printf("%s",b); // @@ b is not null-terminated; it may contain garbage.
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
           if(a[i+1] != '.')
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       printf("%s",b);
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}