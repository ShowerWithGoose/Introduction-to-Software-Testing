#include<stdio.h>
#include<string.h>
int main ()
{
    int i= 0, k = 0, flag = 0, num = 0;
    char a[105];
    char b[105];
    gets(a); // @@ Compilation Error: 'gets' is removed in the C11 standard and causes compilation failure in modern environments; use 'fgets' or 'scanf' instead.
    int len = strlen(a);
    if(a[0] == '0')
    {
        for(i = 1; i < len ; i++)
        {
            if(a[i] == '0' && a[i+1] != '0') // @@ Logical Error: fails for inputs like "0.1" where no '0' follows the decimal point before the first significant digit, leaving 'flag' at 0.
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
            printf("%s",b); // @@ Semantic Error: character array 'b' is not null-terminated, leading to undefined behavior and garbage output when printed with "%s".
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
       printf("%s",b); // @@ Semantic Error: 'b' is not explicitly null-terminated; relying on accidental copying of '\0' from 'a' is unsafe and may cause buffer overread.
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}