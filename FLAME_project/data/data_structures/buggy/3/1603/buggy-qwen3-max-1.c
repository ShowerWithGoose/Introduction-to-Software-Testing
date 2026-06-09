#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it includes the newline in some environments, but the real issue here is logic errors below. However, the immediate bug is not due to gets().]
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
        } @@ [This loop fails when there are no zeros after the decimal point (e.g., "0.9"). In that case, flag remains 0, leading to incorrect indexing.]
        if(a[flag + 1] == '\0')
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
       } @@ [num counts the number of digits before the decimal point, but for scientific notation, exponent should be num - 1. This part is correct in intent, but the following loop has an off-by-one error.]
       b[0] = a[0];
       b[1] = '.';
       for(i = 0 ; i < len ; i++)
       {
           if(a[i+1] != '.') @@ [When i = len - 1, a[i+1] is out of bounds (undefined behavior). Also, this condition skips the '.' but incorrectly processes digits. For input like "123.45", it will include '2','3','4','5' correctly? But note: i starts at 0, so a[1] is checked first. However, if the number has only one digit before '.', e.g., "5.6", then a[0]='5', a[1]='.', so a[i+1] when i=0 is '.', which is skipped — then i=1: a[2] is processed. But the loop runs i from 0 to len-1, so a[i+1] goes up to a[len], which is '\0'. The bigger issue: it copies all non-dot characters after the first digit, including possibly extra characters. However, the main bug is in the '0.x' branch.]
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