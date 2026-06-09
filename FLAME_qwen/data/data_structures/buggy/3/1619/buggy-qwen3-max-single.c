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
        printf("%d.",arr[0]-'0'); @@ [Using %d prints an integer followed by a dot, but if the number has only one digit before the decimal and no fractional part beyond what's needed, this may incorrectly force a decimal point even when the normalized form should be an integer (e.g., "5" should output "5", not "5."). Also, the problem states that if it's an integer base, it should have no decimal point.]
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1); @@ [This assumes the decimal point was found in the loop, but if the input has no decimal point (which contradicts problem statement but still), i would be strlen(arr), leading to wrong exponent. However, per problem, input always has digits before and after '.', so this may not be the main issue. The real issue is that trailing zeros are not allowed, but the code prints all non-dot digits, possibly including trailing zeros if input had them—but problem says input has no trailing zeros, so maybe acceptable. Main error is in base formatting.]
        
    }
    else
        {
            for(i=1;i<strlen(arr);i++)
            {
                if(arr[i]!='0'&&arr[i]!='.')
                {
                    break;
                }
            }
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') @@ [This condition is logically flawed: arr[strlen(arr)-2]=='.', then comparing it to '0' will always be false. So this condition never triggers. It seems intended to check if the significant digit is the last character (so no fractional part after), but the logic is broken. Also, strlen(arr)-2 may be out of bounds for short inputs like "0.1".]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); @@ [Same issue as above: forces a decimal point even when the normalized mantissa should be an integer (e.g., if input is "0.5", output should be "5e-1", not "5.e-1" or "5." which is invalid). But more critically, if there are no digits after the first significant digit, we shouldn't print a decimal point. However, per problem, input has digits after decimal and all are significant, so after skipping leading zeros, there should be at least one digit after? Not necessarily—if input is "0.5", then after '5' there's nothing, so base should be "5", not "5.". This line incorrectly adds a dot even when no following digits exist.]
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1); @@ [Exponent calculation is wrong. For "0.005", the first non-zero is at index 3 (0-based: '0','.','0','0','5'), so i=4. The exponent should be -(i - 2) = -3, but this prints e-3 if i=4 → e-3, which is correct? Wait: positions: index0='0',1='.',2='0',3='0',4='5'. Loop breaks at i=4. Exponent should be -(4 - 1) = -3? Actually, from '.' at index1, the first non-zero is at index4, so number of places moved is 3 → exponent -3. But code uses i-1 = 3 → e-3, which is correct. However, note that i starts from 1, and in "0.1", i=2 (since arr[1]=='.', arr[2]=='1'), so i=2, exponent = -1, which is correct. So exponent might be okay. The real issue is in the base formatting and the flawed condition above.]
            
        }
    
    
    
    return 0;
}