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
            if(a[i] == '0' && a[i+1] != '0') // @@ This condition incorrectly requires a[i] to be '0' before the non-zero digit, but for numbers like 0.001, the first non-zero digit is after multiple zeros; the logic should find the first non-zero digit after the decimal point, not require a preceding zero.
            {
                flag = i + 1;
                break;
            }
        }
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