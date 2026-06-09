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
        printf("%d.",arr[0]-'0'); @@ [Using %d prints an integer followed by a dot, but the problem requires the base to be either a single digit (without decimal point) or a decimal with one digit before and after. For numbers like "5.67", this prints "5." then "67" → "5.67e1", which is correct format-wise, but logic fails when input has more than one digit before decimal like "12.34": it prints "1.234e1" which is correct, however the loop to find '.' starts at i=1 and breaks at '.', so i becomes index of '.', then exponent is i-1 which is correct. So this part may be okay. However, the real issue is in the else branch.]
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') @@ [This condition is always false because it checks if the same character equals both '0' and '.', which is impossible. It should check if the significant digit found is the last character (i.e., no digits after it), to decide whether to print decimal point or not. Also, arr[strlen(arr)-2] assumes the string ends with a digit after '.', but input format says no trailing zeros, so last char is non-zero digit. This condition is logically broken.]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); @@ [For inputs like "0.001", this prints "1." then remaining digits → "1.e-3", but expected is "1e-3" (no decimal point if only one digit). The problem states: if base is integer (only one significant digit), no decimal point. So decimal point should only appear if there are digits after the first significant digit.]
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1); @@ [Exponent calculation is wrong. For "0.001", the first non-zero is at index 3 ('1'), k (position of '.') is 1, so exponent should be -(3 - 1 - 1) = -2? Wait: 0.001 = 1e-3. Position of '1' is i=3 (0-based: ['0','.','0','0','1']), so distance from decimal is i - 2 (since '.' is at 1, first digit after is index 2). Number of leading zeros after decimal is (i - 2), so exponent is -(i - 1). Actually, 0.001: '.' at index 1, '1' at index 4? Let's index: arr = "0.001" → indices: 0:'0',1:'.',2:'0',3:'0',4:'1'. So i=4. Exponent should be -3. Correct formula: exponent = -(i - 2) - 1 = -(i - 1 - 1) = -(i - 2)? Wait: standard: 0.001 = 1 × 10^-3. The '1' is 3 places right of decimal, so exponent -3. Index of '1' is 4, '.' is at 1, so offset = 4 - 1 - 1 = 2? No: positions after decimal: index 2 → 1st, 3→2nd, 4→3rd. So exponent = -(4 - 1) = -3? 4 - 1 = 3 → yes. So exponent = -(i - 1). But in code: i is index of first non-zero (4), so i-1 = 3, so "e-3" is correct. So exponent part is actually correct. The main errors are: (1) faulty condition for printing decimal point, (2) the impossible condition checking same char for '0' and '.', (3) in the if(arr[0]>'0') branch, using %d. for single-digit base when there are no fractional digits after removal of decimal — but input always has digits before and after decimal, so maybe okay. However, problem says: "If it’s an integer, it contains only one significant digit without a decimal point." But in the >'0' branch, it always prints a decimal point (e.g., "5." for "5.0" — but input has no trailing zeros, so "5.0" won't occur; input like "5.6" → "5.6e0"? Wait, no: "5.6" → base should be "5.6", exponent 0? But scientific notation usually normalizes to one digit before decimal: 5.6 = 5.6 × 10^0, but standard scientific notation requires one non-zero digit before decimal, so 5.6 is already normalized? Actually, yes: for numbers >=1 and <10, exponent is 0. But the problem says: "If it’s a decimal, it must have one significant digit before and after the decimal point" — wait, that seems to imply always two digits? But example: "5" would be "5e0", but input has digits before and after decimal, so input is like "5.6", which should become "5.6e0". However, the reference program for non-zero first digit prints s[0]. then all other digits (excluding '.'). So "12.34" → "1.234e1", which is correct. But for "5.6", it prints "5.6e0", which matches the requirement (one digit before, and after decimal point — but "5.6" has one after, okay). However, the buggy code uses printf("%d.",arr[0]-'0') — this prints "5." which is correct as a string, but if the number was "10.0" (but input has no trailing zeros, so "10.0" invalid; valid input "10.2" → becomes "1.02e1"). So the %d. is okay because arr[0] is a digit char, subtracting '0' gives int, %d prints digit, then '.'. So that's fine.

Main bugs are in else branch:
- The condition `if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.')` is always false.
- The logic to decide whether to print a decimal point is flawed: it should print a decimal point only if there are additional significant digits after the first non-zero digit.
- Also, the loop variable `i` in the else branch: after the for-loop, `i` is the index of the first non-zero digit after decimal. Then, when printing digits after, it starts from `j=i+1`, which is correct. But the condition to omit decimal point should be: if `i == strlen(arr)-1` (i.e., the first non-zero is the last character), then print without decimal point. Otherwise, print with decimal point.

So the key errors are on the lines with the impossible condition and the incorrect decimal point decision.]
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1);
            
        }
    
    
    
    return 0;
}