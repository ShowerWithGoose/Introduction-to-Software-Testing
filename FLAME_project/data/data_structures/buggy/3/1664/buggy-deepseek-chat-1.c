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
         printf("%d", l - p); // @@ The exponent calculation is wrong. For input "0.00000009123456789012", l=20, p=9, so l-p=11, but the correct exponent is -8. The exponent should be the number of zeros after the decimal point before the first non-zero digit, which is p - k - 1 = 9 - 1 - 1 = 7, so the exponent should be -7, but the expected output shows e-8, indicating the exponent should be -(p - k - 1) = -(9-1-1) = -7, but the expected is -8, so the correct formula is -(p - k) = -(9-1) = -8.
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