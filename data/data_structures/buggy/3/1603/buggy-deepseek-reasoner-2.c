#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); // @@ Unsafe function; may cause buffer overflow, but not a compilation error. The main errors are logical.
    int len = strlen(a);
    if(a[0] == '0')
    {
        for(i = 1; i < len ; i++) // @@ The loop fails to set flag when the first non-zero digit is immediately after the decimal point (e.g., "0.123"). Should also handle case where a[i] != '0'.
        {
            if(a[i] == '0' && a[i+1] != '0') // @@ Condition is too restrictive; it only sets flag when there is a leading zero before the first non-zero digit. Does not handle "0.123" correctly.
            {
                flag = i + 1;
                break;
            }
        }
        if(a[flag + 1] == '\0') // @@ If no non-zero digit found (flag remains 0), a[1] is '.' not '\0', so this branch may incorrectly execute or else branch uses flag=0.
        {
            printf("%ce-%d",a[flag],flag - 1); // @@ When flag is 0, a[0]='0' and exponent -1, which is wrong.
            return 0;
        }
        else
        {
            b[0] = a[flag]; // @@ If flag is 0, this copies '0' as the base digit, which is invalid.
            b[1] = '.';
            for(k = 0 ;  k < len - flag - 1 ; k++)
            {
                b[k+2] = a[flag + k + 1];
            }
            printf("%s",b); // @@ b is not null-terminated; undefined behavior.
            printf("e-%d",flag - 1);
            return 0;
        }


    }
    else
    {
       while(a[i] != '.') // @@ Assumes a decimal point exists; fine per problem.
       {
           i++;
           num++;
       }
       b[0] = a[0];
       b[1] = '.';
       for(i = 0 ; i < len ; i++) // @@ Reusing i; after the while loop i is the index of '.'; here i is reset to 0, but the loop condition is fine.
       {
           if(a[i+1] != '.') // @@ When i = len-1, a[i+1] accesses the null terminator, which is copied into b.
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       printf("%s",b); // @@ b is not null-terminated; undefined behavior.
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}