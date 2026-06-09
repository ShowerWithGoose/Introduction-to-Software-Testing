#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
char s[105];
int main()
{
    scanf("%s",s);
    int i=0,len=strlen(s),j,k=0,i1;
    if(s[0]=='0')
    {
        i++;
        while(s[i+1]=='0')
            i++;
        printf("%c.",s[i+1]); // @@ Error: When the input is "0.0", s[i+1] may be the null terminator, causing undefined behavior. Also, the logic for handling numbers like "0.001" is incorrect because it skips the first zero after decimal but then prints from the wrong position.
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i); // @@ Error: The exponent calculation is incorrect. For input "0.001", i becomes 2 after the loop, but the correct exponent should be -3. The logic does not properly count the number of zeros after the decimal point.
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1)
            i++;
        if(i==len-1)
        {
        while(s[len-1-k]=='0')
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++) // @@ Error: For integer inputs like "100", this loop incorrectly handles trailing zeros. The condition j<i+1-k may produce incorrect output, and the exponent calculation is wrong.
            printf("%c",s[j]);
        }
        printf("e%d",i); // @@ Error: The exponent i is the position of the decimal point, but for integer inputs without a decimal point, i equals len-1, which is not the correct exponent.
        }
        else
        {
            printf("%c.",s[0]);
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i); // @@ Error: For inputs like "12.34", i is the position of the decimal point (1), but the exponent should be 1 (since 12.34 = 1.234e1). This is correct in this case, but the logic fails for inputs with leading zeros or other edge cases.
        }
    }
    return 0; 
}