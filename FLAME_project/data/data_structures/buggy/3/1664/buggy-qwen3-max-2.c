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
         printf("%d", l - p); // @@ [The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at index 9 (0-based). The correct exponent should be -(9 - 1) = -8, but the code computes l - p = 22 - 9 = 13, leading to e-13 instead of e-8. The exponent should be (p - k - 1) with a negative sign, i.e., -(p - k - 1) = k + 1 - p = 1 + 1 - 9 = -7? Wait: actually, in "0.00000009...", the decimal point is at index 1, and the first non-zero is at index 9. The number of zeros after the decimal before the first non-zero is (p - k - 1) = 9 - 1 - 1 = 7, so exponent is - (7 + 1) = -8. So exponent = -(p - k - 1 + 1) = -(p - k) = k - p. Since k=1, p=9, exponent = 1 - 9 = -8. So it should be printf("%d", p - k); but with negative sign already printed, so just (p - k) is wrong — actually, we need to print (p - k - 1 + 1)? Let's clarify: 0.00000009 = 9e-8. The '9' is the 8th digit after the decimal. So exponent is -8. The position of '9' is index 9 (s[0]='0', s[1]='.', s[2]='0', ..., s[9]='9'). So number of places to move decimal to right to get 9.xxxx is 8. So exponent is -8. The distance from decimal point (at k=1) to '9' (at p=9) is (p - k - 1) zeros, then the digit, so total shift is (p - k) positions? From after decimal: positions 2,3,...,9 → that's 8 positions (2→1st, 3→2nd, ..., 9→8th). So exponent = - (p - k). Because p - k = 9 - 1 = 8. So we should print (p - k), not (l - p). Hence, error here.]
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