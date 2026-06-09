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
            if(a[i] == '0' && a[i+1] != '0') // @@ The condition fails to identify the first non-zero digit correctly for input like "0.9". It looks for a '0' followed by a non-'0', skipping the decimal point logic or misinterpreting indices. For "0.9", a[1] is '.', which is not '0', so the loop continues or breaks incorrectly depending on subsequent chars. Actually, for "0.9", a[1]='.', a[2]='9'. The condition a[i]=='0' is false for i=1 ('.'). So flag remains 0.
            {
                flag = i + 1;
                break;
            }
        }
        if(flag == 0) flag = 2; // @@ If no '0' followed by non-'0' is found (e.g., 0.9), flag is still 0. We need to find the first non-zero digit after the decimal point. For 0.9, it's at index 2.
        
        // Correct logic for finding first significant digit for numbers < 1:
        // Find the first digit that is not '0' and not '.' after the initial "0."
        // The current logic is fundamentally flawed for finding the exponent and mantissa start.
        
        if(a[flag + 1] == '\0') // @@ Using the incorrect flag value leads to wrong index access.
        {
            printf("%ce-%d",a[flag],flag - 1); // @@ Prints wrong character and exponent due to incorrect flag calculation.
            return 0;
        }
        else
        {
            b[0] = a[flag]; // @@ Uses wrong starting digit.
            b[1] = '.';
            for(k = 0 ;  k < len - flag - 1 ; k++)
            {
                b[k+2] = a[flag + k + 1];
            }
            printf("%s",b);
            printf("e-%d",flag - 1); // @@ Wrong exponent.
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
           if(a[i+1] != '.') // @@ This condition checks the next character, but copies a[i+1]. It skips the decimal point in source but might include garbage or miss bounds. Also, it doesn't null-terminate b.
           {
               b[2 + k] = a[i + 1];
               k++;
           }
       }
       b[2+k] = '\0'; // @@ Missing null terminator for string b.
       printf("%s",b);
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}