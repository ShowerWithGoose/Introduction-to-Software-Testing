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
         printf("%d", l - p); // @@ Error: The exponent should be p - k - 1 (the number of zeros after the decimal point before the first non-zero digit), not l - p. For input "0.00000009123456789012", p is 9 (index of '9'), k is 1 (index of '.'), so exponent should be 9 - 1 - 1 = 7, but l - p = 22 - 9 = 13, causing the wrong exponent.
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