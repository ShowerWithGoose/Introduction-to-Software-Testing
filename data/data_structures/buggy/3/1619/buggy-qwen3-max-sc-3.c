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
        printf("%d.",arr[0]-'0'); @@ [Using %d prints an integer followed by a dot, but if the number has only one digit before the decimal and no fractional part beyond, it may incorrectly output e.g., "5.e1" instead of "5e1". Also, per problem, if base is integer (only one digit), it should not have a decimal point.]
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1);
        
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') @@ [This condition is logically flawed: it checks if the second last character is both '0' AND '.', which is impossible. It likely intended to check if the number ends with ".0", but even then, the problem states there are no trailing zeros after the decimal point, so this case shouldn't occur. This leads to incorrect base formatting.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); @@ [Same issue as above: always prints a decimal point even when the mantissa should be an integer (e.g., if input is "0.5", output should be "5e-1", not "5.e-1").]
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1); @@ [Exponent calculation is incorrect. For "0.005", i would be 3 (index of '5'), so exponent should be -(i - 1 - 1) = -(3 - 2) = -2, but this prints e-2 as e-(3-1)=e-2 — wait, actually i starts from 1, skips '.', so for "0.005", arr = "0.005", i=3 (arr[3]=='0', arr[4]=='5' → i=4). Then exponent = -(4-1) = -3, but correct exponent is -3? Let's see: 0.005 = 5e-3 → yes. However, the loop breaks at first non-zero, so i=4, exponent = -(4 - 1) = -3 → correct. BUT: the index calculation is off because the '.' is at position 1, so number of leading zeros after decimal is (i - 2), so exponent = -(i - 1). Actually, for "0.5", i=2, exponent = -1 → correct. So exponent may be correct. However, the main errors are in base formatting and the flawed condition above.]
            
        }
    
    
    
    return 0;
}