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
        printf("%d.",arr[0]-'0'); // @@ [Using %d prints an integer followed by '.', but if the number has only one digit before decimal and no fractional part originally, this may incorrectly add a decimal point. Also, for numbers like "5.0", it should output "5e0", not "5.e0".]
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1); // @@ [The exponent calculation is incorrect when the input has more than one digit before the decimal. For example, "123.45" should give exponent 2, but i stops at '.' which is at index 3, so i-1=2 — this part is actually correct. However, the logic fails to handle cases where there's no decimal point at all, though problem states input always has digits before and after decimal. Still, the bigger issue is in the else branch.]
        
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ [This condition is logically flawed: arr[strlen(arr)-2]=='.', then comparing it to '0' will never be true. Also, the intent seems to check if the last non-decimal digit is zero, but the condition is self-contradictory and doesn't correctly identify when to omit the decimal point. Moreover, the problem states there are no trailing zeros after decimal, so this check is unnecessary and wrong.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); // @@ [This always prints a decimal point even when the significant part is a single digit and there are no following digits (though per problem, there are digits after decimal, but after skipping leading zeros, there might be only one significant digit). However, scientific notation requires: if base is integer (only one digit), no decimal point. But here, it prints "X." even when no fractional digits follow, violating output spec.]
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1); // @@ [Exponent should be -(i - k) where k is position of decimal (which is 1, since arr[0]=='0' and arr[1]=='.'). So exponent = -(i - 1). But i starts from 1, and breaks at first non-zero after decimal. For "0.00123", i=4 (index of '1'), so exponent should be -3, but i-1=3 → prints e-3 which is correct. However, if the loop breaks at i=2 for "0.1", then i-1=1 → e-1, which is correct. So exponent logic is okay. The real issue is in the condition above and decimal point handling.]
            
        }
    
    
    
    return 0;
}