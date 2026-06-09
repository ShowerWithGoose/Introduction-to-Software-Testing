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
        printf("%d.",arr[0]-'0'); @@ [Using %d prints an integer followed by a dot, but the problem requires the base to be either a single digit (without decimal point) or a decimal with one digit before and after. For numbers like "5.67", this prints "5." which is correct, but for single-digit integers like "5" (no decimal), it incorrectly forces a decimal point. However, more critically, if input has no decimal point at all (e.g., "123"), the loop may not find '.' and i becomes strlen(arr), leading to wrong exponent. Also, the condition arr[0]>'0' excludes '0' but also excludes valid inputs starting with '0' followed by decimal like "0.123", which is handled in else, but the logic for non-zero-leading numbers assumes there's always a decimal point.]
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1); @@ [If the input has no decimal point (e.g., "123"), the for-loop doesn't break early, so i ends up as strlen(arr). Then exponent becomes strlen(arr)-1, which is correct (e.g., "123" -> 1.23e2). But if input is just "5", then i=1 (since loop runs j=1, condition fails, exits normally), so i=1, exponent=0 → "5.e0", which violates output spec: if base is integer (only one digit), it should not have a decimal point. So printing "5." is wrong; should be "5e0".]
        
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') @@ [This condition is logically flawed: it checks if the second last character is both '0' AND '.', which is impossible. It should probably check if the significant digit found is the last character (i.e., no digits after it), to decide whether to print decimal point or not. As written, this condition is always false, so it always goes to the else branch, printing a decimal point even when unnecessary (e.g., input "0.5" should output "5e-1", not "5.e-1").]
            {
                printf("%d",arr[i]-'0');
            }
            else
            {
                printf("%d.",arr[i]-'0'); @@ [Same issue as above: if the significant part has only one digit (e.g., "0.5"), it should output "5e-1", not "5.e-1". The decimal point should only appear if there are digits after the first significant digit.]
            }
            for(int j=i+1;j<strlen(arr);j++)
            {
                if(arr[j]!='.')
                {
                    putchar(arr[j]);
                }
            }
            printf("e-%d",i-1); @@ [The exponent calculation is incorrect. For input "0.00123", the first non-zero is at index 4 ('1'), k (decimal position) is 1, so exponent should be -(4-1-1) = -3? Actually, standard: 0.00123 = 1.23e-3. The number of places moved is (position of first non-zero after decimal) - 1. Here, i is index of '1' (which is 4), decimal is at 1, so zeros between are i - 2 (since index 2 and 3 are zeros). Exponent should be -(i - 1 - 1) = -(i-2)? Actually, from 0.00123 to 1.23, move decimal 3 places right → exponent -3. i=4, so exponent = -(i - 2) → -2? No. Correct: exponent = -( (i - decimal_index) - 1 ) = -( (4-1) -1 ) = -2? Still wrong. Better: count leading zeros after decimal. If decimal at pos d, first non-zero at pos i, then exponent = -(i - d - 1 + 1) = -(i - d). Example: "0.00123": d=1, i=4 → exponent = -(4-1) = -3 → correct. So exponent should be -(i - k) where k is decimal index. But in this code, k is not stored; instead, it uses i-1. In "0.00123", i=4, so i-1=3 → prints e-3, which is correct. Wait: i starts from 1, and breaks at first non-zero non-dot. For "0.00123", arr[0]='0', arr[1]='.', arr[2]='0', arr[3]='0', arr[4]='1' → i=4. Then exponent = i-1 = 3 → e-3 → correct. So exponent calculation is actually correct. The real error is in the base formatting (extra decimal point) and the flawed condition above.]
            
        }
    
    
    
    return 0;
}