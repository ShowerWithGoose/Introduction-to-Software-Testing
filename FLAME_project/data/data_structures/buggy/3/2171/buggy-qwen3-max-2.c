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
                    num--; // @@ [This logic incorrectly decrements 'num' for zeros after the first non-zero digit, but 'num' is being reused to count leading zeros after decimal. Also, 'num' was originally the count of digits before '.', now repurposed confusingly.]
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
            printf("e%d",num); // @@ [The exponent calculation is wrong. For "0.9", it should be -1, but 'num' ends up as 0 due to flawed logic above. The number of leading zeros after decimal before first non-zero is 0, so exponent = -(0+1) = -1, but code doesn't compute this correctly.]
        }
        else
        {
            printf("%se0",str); // @@ [For numbers like "8.9", this outputs "8.9e0", but expected is "8.9e0" only if allowed; however, per problem, if base has one digit before decimal and it's non-zero, it's acceptable. BUT for "0.9", this branch isn't taken, so main issue is in the 'str[0]=='0'' branch. However, note: "8.9" should become "8.9e0", which matches spec, so this line may be okay. But for "5.0", it would output "5.0e0", but trailing zero not allowed — however problem states input has no trailing zeros, so maybe okay. Still, for "0.9", the real bug is elsewhere.]
        }
    }
    else
    {
        for(i = 0;i < strlen(str);i++)
        {
            if(i == 1)
            {
                printf(".%c",str[i]); // @@ [This assumes the second character is always part of the fractional part, but if input is "123.45", then at i=1, str[i]='2', and it prints ".2", resulting in "1.2345..." which is correct? Wait: loop prints str[0] normally (since i!=1 and i!=num), then at i=1 prints ".2", then continues. But what if num (digits before '.') is 3? Then at i=3 (the '.'), it skips. But the loop condition doesn't skip '.', so when i reaches the '.', it will print it unless i==num. But in this branch, num>=2, and the '.' is at position num. So when i==num, it skips. But the printing logic is fragile. However, for input like "10.5", num=2, so it prints: i=0: '1'; i=1: ".0"; i=2: skip ('.'); i=3: '5'. So output "1.05e1" — which is correct. So maybe this branch is okay. Main bug is in the 'num==1 && str[0]=='0'' branch.]
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