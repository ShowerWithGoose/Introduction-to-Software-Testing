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
            if(a[i] != '0' && a[i] != '.') // @@ The condition `a[i] == '0' && a[i+1] != '0'` is incorrect. We need to find the first non-zero digit after the decimal point. Also, accessing a[i+1] might go out of bounds or skip the correct digit if it's the last one. The loop should look for the first digit that is not '0' and not '.'.
            {
                flag = i; // @@ flag should store the index of the first significant digit.
                break;
            }
        }
        // The logic below assumes flag is the index of the first significant digit.
        // If the input is 0.9, flag should be 2 (index of '9').
        // Exponent should be -(flag - 1). For 0.9, exponent is -(2-1) = -1. Correct.
        
        // Check if there are any digits after the significant digit
        if(a[flag + 1] == '\0') // @@ This checks if the significant digit is the last character.
        {
            printf("%ce-%d",a[flag],flag - 1); // @@ Output format for integer base.
            return 0;
        }
        else
        {
            b[0] = a[flag];
            b[1] = '.';
            // Copy remaining digits
            int j = 0;
            for(k = flag + 1; k < len ; k++) // @@ Iterate through the rest of the string to copy digits.
            {
                if(a[k] != '.') // @@ Skip the decimal point if it appears (though it shouldn't after the first sig digit in this specific input format, but good practice).
                {
                    b[j+2] = a[k];
                    j++;
                }
            }
            b[j+2] = '\0'; // @@ Null terminate the string b.
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
       k = 0; // @@ Reset k for indexing into b.
       for(i = 1 ; i < len ; i++) // @@ Start from index 1 to skip the first digit which is already in b[0].
       {
           if(a[i] != '.') // @@ Copy all characters except the decimal point.
           {
               b[2 + k] = a[i];
               k++;
           }
       }
       b[2+k] = '\0'; // @@ Null terminate the string b.
       printf("%s",b);
       printf("e%d",num - 1);
       return 0;
    }

    return 0;
}