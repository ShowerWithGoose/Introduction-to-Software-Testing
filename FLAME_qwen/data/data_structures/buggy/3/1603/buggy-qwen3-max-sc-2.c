#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
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
        if(a[flag + 1] == '\0') @@ [If 'flag' was never set (e.g., input like "0.0"), this leads to undefined behavior due to uninitialized 'flag'. Also, accessing a[flag+1] may go out of bounds.]
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
       while(a[i] != '.') @@ [If the input has no decimal point (e.g., "123"), this loop runs past the end of the string, causing undefined behavior.]
       {
           i++;
           num++;
       }
       b[0] = a[0];
       b[1] = '.';
       for(i = 0 ; i < len ; i++) @@ [Loop condition uses 'i < len', but inside accesses 'a[i+1]', which reads beyond array bounds when i == len-1.]
       {
           if(a[i+1] != '.') @@ [Same as above: a[i+1] is out-of-bounds when i == len-1. Also, logic fails to skip the '.' correctly.]
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       printf("%s",b); @@ [The string 'b' is not null-terminated, leading to undefined behavior when printed with %s.]
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}