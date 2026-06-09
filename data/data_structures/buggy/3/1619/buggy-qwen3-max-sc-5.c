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
        printf("%d.",arr[0]-'0'); // @@ [Using %d prints an integer followed by '.', but if the number has only one digit before decimal and no fractional part beyond, it may incorrectly force a decimal point. However, more critically, this logic fails when input is like "5.0" (though problem says no trailing zeros), but main issue is in exponent calculation and handling of cases where '.' is not found. Also, if '.' is not present in input (which shouldn't happen per problem), loop exits with i = strlen(arr), leading to wrong exponent.]
        for(int j=1;j<strlen(arr);j++)
        {
            if(arr[j]!='.')
            {
                putchar(arr[j]);
            }
        }
        printf("e%d",i-1); // @@ [If the input has no decimal point (violates problem constraints, but code doesn't ensure '.' exists), i becomes strlen(arr), so exponent becomes too large. Also, for inputs like "123.45", i stops at index of '.', which is 3, so exponent is 2 — correct. But logic assumes '.' always exists, which is okay per problem, but the bigger issue is in the else branch.]
        
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
            if(arr[strlen(arr)-2]=='0'&&arr[strlen(arr)-2]=='.') // @@ [This condition is logically flawed: arr[strlen(arr)-2]=='.', then comparing same element to '0' will never be true. It should check if the significant digit is the last character (i.e., no digits after it), but this condition is always false because '.' != '0'. Thus, it always prints with a decimal point even when unnecessary.]
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
            printf("e-%d",i-1); // @@ [Exponent should be (i - position_of_decimal - 1). Since decimal is at index 1 (because arr[0]=='0'), the first non-zero digit is at index i, so exponent is -(i - 2). But here it's printing -(i-1), which is off by one. For example, input "0.00123": decimal at index 1, first non-zero at index 4, exponent should be -3, but i=4, so e-3 would need i-1=3 → e-3, which seems correct? Wait: positions: [0]='0', [1]='.', [2]='0', [3]='0', [4]='1'. So i=4. Exponent = -(4 - 1 - 1) = -2? No: scientific notation: 1.23e-3. Decimal moved from after first non-zero (at pos4) back to after '1', which is 3 places left → exponent -3. The number of places = (i - 2) because from index 1 ('.') to index 4 is 3 digits: .001 → move 3 places. So exponent = -(i - 2). But code uses i-1 → e-3 when i=4 → 4-1=3 → e-3, which is correct. So maybe exponent is okay. But the real error is in the condition above that never triggers, causing unnecessary decimal point. Also, if the significant part has only one digit (e.g., "0.005"), output should be "5e-3", not "5." or "5.0". Problem says: if base is integer (only one digit), no decimal point. So when there are no digits after the first non-zero, should omit decimal. But current condition fails to detect that.]
            
        }
    
    
    
    return 0;
}