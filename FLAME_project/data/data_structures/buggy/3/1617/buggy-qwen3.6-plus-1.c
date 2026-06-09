#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    gets(s);
    int n = strlen(s);
    
    if(s[0] == '0'){
        int flag; // @@ [Variable 'flag' is used uninitialized. If the loop doesn't find a non-zero digit or logic is flawed, it holds garbage. Also, logic for finding first significant digit is incorrect for general cases.]
        for(int i=2;i<n;i++){
            if(s[i] != '0')
                flag = i; // @@ [This updates flag for EVERY non-zero digit, so flag ends up being the index of the LAST non-zero digit, not the first. It should break after finding the first one.]
        }
        
        if(flag == n-1){ // @@ [This condition checks if the last digit is the only significant one found (due to the bug above), which is logically wrong for determining if there are trailing digits.]
            printf("%c",s[flag]);
            printf("e-%d",n-2); // @@ [Exponent calculation is incorrect. For 0.00...0912..., exponent should be -(position of first sig digit - 1).]
        }
        else{
            printf("%c.",s[flag]);
            for(int i=flag+1;i<n;i++){
                printf("%c",s[i]);
            }
            printf("e-%d",flag-1); // @@ [Exponent calculation is incorrect. If flag is the index of the first significant digit, the exponent should be -(flag - 1) because the decimal point was originally at index 1. Wait, if s is "0.0009", flag=4. Value is 9 * 10^-4. Original pos 4. Shift left 4-1=3 places? No. 0.0009 = 9e-4. Index 4. Exponent is -(4-1) = -3? No. 0.0009. Decimal at 1. Digit at 4. Distance is 3. But value is 9 * 10^-4. Let's trace: 0.0009. s[0]='0', s[1]='.', s[2]='0', s[3]='0', s[4]='9'. Flag=4. Output 9.e... Exponent should be -4. Formula: -(flag - 1) gives -3. Wrong. Correct exponent for 0.digits...d_sig is -(index_of_sig_digit - 1). Wait. 0.9 -> 9e-1. Index 2. -(2-1)=-1. Correct. 0.09 -> 9e-2. Index 3. -(3-1)=-2. Correct. 0.0009 -> 9e-4. Index 5? No. "0.0009". Indices: 0:'0', 1:'.', 2:'0', 3:'0', 4:'0', 5:'9'. Flag=5. -(5-1) = -4. Correct. So formula flag-1 is correct for magnitude, but sign is negative. So e-%d with flag-1 is correct IF flag is the first significant digit. The main error is flag being the LAST significant digit.]
        }
    }
    
    else{
        int flag; // @@ [Variable 'flag' is used uninitialized. It is only assigned inside the loop if '.' is found. If input has no '.', it remains uninitialized.]
        for(int i=0;i<n;i++){
            if(s[i] == '.')
            flag = i-1; // @@ [This assigns flag repeatedly. It will end up as the position of the digit before the LAST dot. Usually there is only one dot. So flag becomes index of integer part last digit. For "123.45", flag becomes 2 (index of '3'). This represents the number of digits before decimal minus 1? No, index 2 means 3 digits. Exponent should be 2. So flag is correct for exponent if it's the index of the last digit before decimal. However, if there is no decimal point, flag is uninitialized.]
        }
        printf("%c.",s[0]);
        for(int i=1;i<n;i++){
            if(s[i] != '.')
                printf("%c",s[i]);
        }
        printf("e%d",flag); // @@ [If the number is an integer (no decimal point), flag is uninitialized. Also, if the number is like "100", scientific notation is 1.e2. Flag would be uninitialized if no dot. If input is "123.45", flag=2. Output 1.2345e2. Correct. But what if input is "100"? No dot. Flag uninitialized. Crash or wrong answer.]
    }
    return 0;
}