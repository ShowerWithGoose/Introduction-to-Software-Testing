#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char str[100000];
int main(void){
    int i,k = 0,num = 0;
    gets(str);
    for(i = 0;i < strlen(str);i++)
    {
        if(str[i] != '.')
            num++;
        else if(str[i] == '.')
            break;
    }    
    if(num == 1)
    {
        if(str[0] == '0')
        {
            num = 0;
            for(i = 0;i < strlen(str);i++)
            {
                if(str[i] == '0'&&k>0)
                {
                    num--; // @@ [This logic incorrectly decrements 'num' for zeros after the first non-zero digit, but 'num' is being reused to count leading zeros after decimal. Also, 'num' was originally used to count digits before '.', now repurposed confusingly.]
                }
                else if(str[i] != '.')
                {
                    printf("%c",str[i]);
                    k++;
                    if(k == 1&&i!=strlen(str)-1)
                    {
                        printf("."); // @@ [This prints a decimal point after the first significant digit only if it's not the last character, but in scientific notation, if there's only one significant digit (like '9'), no decimal point should be printed. For input "0.9", this prints "9." instead of just "9".]
                    }
                } 
            }
            printf("e%d",num); // @@ [The exponent calculation is wrong. For "0.9", it should be -1, but 'num' ends up as 0 because initial 'num=0', then no decrement happens (since k=0 when encountering '0' at index 0 and '.' at index 1), so it prints e0 instead of e-1. Also, the sign of the exponent is missing for negative exponents.]
        }
        else
        {
            printf("%se0",str); // @@ [For numbers like "8.9", this outputs "8.9e0", but expected is "8.9e0" only if allowed; however, per problem, if base has one digit before decimal and it's non-zero, it's acceptable. BUT for "0.9", this branch isn't taken, so main issue is above. However, note that "8.9e0" is actually correct per problem? But reference expects single digit base: so "8.9" is okay. However, the real bug is in the '0.x' case.]
        }
    }
    else
    {
        for(i = 0;i < strlen(str);i++)
        {
            if(i == 1)
            {
                printf(".%c",str[i]); // @@ [This assumes the second character is always part of the fractional part, but if input is "123.45", it prints "1.2" then continues, which is wrong. It should take first digit, then decimal, then rest except the decimal point. Also, it skips the decimal point handling correctly.]
            }
            else if(i != num)
            {
                printf("%c",str[i]);
            } 
        } 
        printf("e%d",num-1);
    }
    return 0;
}