#include<stdio.h>
#include<string.h>
int main(){
    int i,j=0,j1=-1,k=0,len,a,b;
    char str[105];
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]>'0'&&str[i]<='9'){
            j=i;
            if(j1<0)
            j1=j;    
        }
        if(str[i]=='.')
            k=i;
    }
    if(k==0){
        k=len-1;
    }
    if(j1==j){
        printf("%ce%d",str[j1],k-j1);
    }
    else{
        printf("%c.",str[j1]);
        for(i=j1+1;i<=j;i++){
            if(str[i]!='.')
                printf("%c",str[i]);
        }
        printf("e%d",k-j1-1); // @@ The exponent calculation is incorrect. For numbers less than 1 (e.g., 0.00...X), the decimal point index `k` is small, and `j1` (first significant digit) is large. The formula `k - j1 - 1` yields a negative number with incorrect magnitude or sign logic compared to the standard scientific notation exponent which should be `-(number of zeros after decimal + 1)` or effectively `k - j1` if we consider the shift. Let's trace: Input 0.0000000912... `j1`=9 (index of '9'), `k`=1 (index of '.'). Correct exponent is -8. Formula `k - j1 - 1` = 1 - 9 - 1 = -9. The correct exponent for moving decimal from after first sig digit to original position: Original is 0.00000009... Scientific is 9.12... e-8. The decimal moved 8 places to the left. The index of the first significant digit is `j1`. The index of the decimal point is `k`. If `j1 > k`, the number is < 1. The exponent is `k - j1`. Wait. 0.009. `k`=1, `j1`=3. 9e-3. `k-j1` = 1-3 = -2. Incorrect. It should be -3. The number of positions the decimal point moves to the right to get to the position after the first significant digit is `j1 - k`. Since we are converting TO scientific notation, we move the decimal point to the LEFT. From 0.009 to 9., we move right 2 spots? No. 0.009 -> 9.0. Move decimal right 3 spots. Exponent is -3. `j1` is index of 9. `k` is index of dot. `j1 - k` is 2. We need 3. So it is `-(j1 - k)`? No. 0.009. Indices: 0:'0', 1:'.', 2:'0', 3:'9'. `j1`=3, `k`=1. `j1-k`=2. Exponent -3. Formula `k - j1` is -2. Formula `k - j1 - 1` is -3. This matches. 
Let's re-trace the failing case: 0.0000000912...
Indices: 0:'0', 1:'.', 2:'0', ..., 8:'0', 9:'9'.
`k`=1. `j1`=9.
Correct exponent: -8.
Current code output: `k - j1 - 1` = 1 - 9 - 1 = -9.
Why is it -8?
0.0000000912 = 9.12 * 10^-8.
Decimal moves 8 places to the right to get after 9? No.
To get from 9.12... to 0.0000000912..., we move decimal 8 places to the LEFT. So exponent is -8.
In the string "0.0000000912...", the decimal point is at index 1. The first significant digit '9' is at index 9.
The number of digits between the decimal point and the first significant digit (exclusive of dot, inclusive of zeros) is `j1 - k - 1`. Here 9 - 1 - 1 = 7 zeros.
The exponent is -(number of zeros + 1) = -(7+1) = -8.
So the formula should be `-(j1 - k - 1 + 1)` = `k - j1`.
Let's check 0.009 again. `k`=1, `j1`=3. Zeros = 3-1-1 = 1. Exponent = -(1+1) = -2? No, 0.009 is 9e-3.
Wait. 0.009. Digits: '0', '.', '0', '0', '9'.
Indices: 0, 1, 2, 3, 4.
`k`=1. `j1`=4.
Zeros between dot and 9: indices 2,3. Two zeros.
Exponent should be -3.
Formula `-(zeros + 1)` = -(2+1) = -3.
Zeros count = `j1 - k - 1`.
Exponent = `-(j1 - k - 1 + 1)` = `k - j1`.
Let's check `k - j1` for 0.009: 1 - 4 = -3. Correct.
Let's check `k - j1` for 0.0000000912: 1 - 9 = -8. Correct.
The current code has `k - j1 - 1`. This is off by 1.
    }
    return 0;
}