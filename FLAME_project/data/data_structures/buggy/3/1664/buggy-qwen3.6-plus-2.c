#include<stdio.h>
#include<string.h>

char s[105];

int main()
{
    scanf("%s", &s);
    
    int i, l = strlen(s), k = 106, p;
    
    for(i = 0; i < l; i++)
    {
        if(s[i] == '.')
        {
            k = i;
        }
        if(i > k && s[i] != '0')
        {
            p = i;
            break;
        }
    }
    
    if(k == 1 && s[0] == '0')
    {
         printf("%c", s[p]);
         if(p < l - 1)
         {
             printf(".");
        }
         for(i = p + 1; i < l; i++)
         {
             printf("%c", s[i]);
         }
         printf("e-");
         printf("%d", l - p); // @@ The exponent calculation is incorrect. For a number like 0.00...0X..., the exponent should be -(position of first non-zero digit after decimal). Here, `p` is the index of the first non-zero digit. The number of zeros between the decimal point and this digit is `p - k - 1`. The exponent is `-(p - k)`. Since `k=1` (decimal at index 1), exponent is `-(p-1)`. The current code prints `l-p`, which depends on the total length and trailing digits, not the position of the first significant digit relative to the decimal point. For input "0.00000009123456789012", k=1, p=9. Correct exponent is -(9-1) = -8. Code calculates l-p = 22-9 = 13, printing e-13.
    }
    else
    {
        printf("%c", s[0]);
         printf(".");
        for(i = 1; i < l; i++)
        {
            if(s[i] != '.')
            {
                printf("%c", s[i]);
            }
        }
        printf("e");
        printf("%d", k - 1);
    }
    return 0;
}