#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); // @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, in some environments, gets() is not available, leading to compilation error.]
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
        if(a[flag + 1] == '\0') // @@ [If the input is "0.0", then flag might be uninitialized or point beyond valid digits, leading to undefined behavior. Also, if all digits after decimal are zero (though problem says no trailing zeros), this logic fails. But more critically, if the loop above doesn't break (e.g., input "0.1"), flag remains 0, so a[1] is accessed as a[flag], but here a[flag+1] = a[1] which may be '.' or digit — logic flaw. However, the immediate compilation issue is use of gets().]
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
       for(i = 0 ; i < len ; i++) // @@ [This loop uses i from 0 again, but condition checks a[i+1]; when i = len-1, a[i+1] is out of bounds (undefined behavior). Also, k is never reset to 0 before this loop, so if previous branch didn't run, k=0, but if it did, k could be non-zero — but since branches are exclusive, maybe okay. However, the bigger issue is potential buffer overrun in b[] and reading past array. But primary compilation error is gets().]
       {
           if(a[i+1] != '.')
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       printf("%s",b); // @@ [b is not null-terminated, so printf("%s",b) leads to undefined behavior (may print garbage). This is a runtime error, but the reported error is compilation error due to gets().]
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}