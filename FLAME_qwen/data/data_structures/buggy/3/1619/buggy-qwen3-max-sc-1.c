#include <stdio.h>
#include <string.h>
char arr[105];
int main()
{
    scanf("%s",arr);
    int i=0;
    
    if(arr[0]>'0')
    {
        for(i=1;i<strlen(arr);i++)
        {
            if(arr[i]=='.')
            {
                break;
            }
        }
        printf("%d.",arr[0]-'0'); // @@ [Using %d prints an integer followed by '.', but if the number has only one digit before decimal and no fractional part beyond, it may incorrectly format; however, main issue is in exponent calculation and handling of cases like "0.0..."]
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1); // @@ [Exponent is calculated as i-1 where i is index of '.', which is correct for numbers >=1, but loop starts at 1 so if input is e.g., "1.23", i becomes 1 (index of '.'), then exponent = 0, which is correct. However, this branch assumes first char > '0', so excludes '0' but includes digits '1'-'9'. This is okay per problem, but logic fails when input is like "10.0" — but problem states all digits are significant and no trailing zeros, so maybe acceptable. Real error is elsewhere.]
        
    }
    else
        {
            for(i=1;i<strlen(arr);i++)
            {
                if(arr[i]!='0'&&arr[i]!='.') // @@ [This skips over '.' and '0's, but if string starts with "0.", then i increments past '.' and zeros until first non-zero. However, condition breaks at first non-zero OR non-dot, but '.' is already passed? Actually, after "0.", next chars are digits. But if input is "0.001", then i will stop at index 3 ('1'). That seems okay.]
                {
                    break;
                }
            }
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ [This condition is always false because a character cannot be both '0' and '.' simultaneously. Likely intended to check if the last significant digit is immediately after decimal with no extra digits, e.g., "0.5" vs "0.50" (but problem says no trailing zeros). Also, arr[strlen(arr)-2] being '.' would mean the string ends with ".X", so length at least 3, and second last is '.', e.g., "0.5" → len=3, index1='.', so arr[1]='.', arr[len-2]=arr[1]='.' — but comparing to '0' makes condition false. This logic is broken and causes incorrect base formatting.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0');
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1); // @@ [Exponent should be -(i - position_after_decimal). Since input starts with "0.", the first non-zero digit is at index i, and the decimal point is at index 1. So exponent should be -(i - 2) or more precisely: if decimal is at index 1, and first non-zero is at i, then number of places moved is (i - 2 + 1) = i-1? Wait: 0.001 → '1' at index 4 (0-based: ['0','.', '0','0','1']), so i=4. Decimal at index1. To get 1e-3, exponent is -3. i - 2 = 2 → not enough. Correct exponent is -(i - 2) -1 = -(i-1)? Actually: from 0.001 to 1e-3: move decimal 3 places right → exponent -3. Index of '1' is 4, decimal at 1, so offset = 4 - 1 - 1 = 2? No: positions after decimal: index2→1st, index3→2nd, index4→3rd. So exponent = -3 = -(4 - 1). So should be e-(i - 1). But current code prints e-(i-1). For i=4, prints e-3 → correct. So exponent is actually correct. The real bug is in the condition above that decides whether to print decimal point in mantissa.]
            
        }
    
    
    
    return 0;
}