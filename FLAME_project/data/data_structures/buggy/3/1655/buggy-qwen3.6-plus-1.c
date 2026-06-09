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
        printf("e%d",k-j1-1); // @@ The exponent calculation is incorrect. For numbers less than 1 (e.g., 0.00...X), the decimal point index `k` is small, and `j1` (first significant digit) is large. The formula `k - j1 - 1` yields a negative number with incorrect magnitude or sign logic compared to the standard scientific notation exponent which should be `-(number of zeros after decimal + 1)` or effectively `k - j1` if we consider the shift. Let's trace: Input 0.0000000912... `j1`=9 (index of '9'), `k`=1 (index of '.'). Correct exponent is -8. Formula `k - j1 - 1` = 1 - 9 - 1 = -9. The correct exponent for moving decimal from after first sig digit to original position: Original is 0.00000009... Scientific is 9.12... e-8. The decimal moved 8 places to the left. The index of the first significant digit is `j1`. The index of the decimal point is `k`. If `j1 > k`, the number is < 1. The exponent is `k - j1`. Wait. 0.009. `k`=1, `j1`=3. 9e-3. `k-j1` = 1-3 = -2. Incorrect. It should be -3. The number of positions the decimal point moves to the right to get to after the first significant digit is `j1 - k - 1` (digits between dot and first sig) + 1 (to pass the sig digit)? No. Standard form: d.dddd... * 10^exp. For 0.009, it is 9 * 10^-3. Here base is integer. For 0.091, it is 9.1 * 10^-2. `j1`=2, `k`=1. Exp = -2. `k - j1` = 1 - 2 = -1. Incorrect. The exponent is `k - j1` if we place decimal after first digit? No. The exponent is determined by how many places the decimal point shifts. From `k` to `j1 + 1` (position after first significant digit). Shift = `(j1 + 1) - k`. Since it shifts right, exponent is negative of that? No, if we shift decimal right, value increases, so we multiply by negative power. Exponent = `k - (j1 + 1)` = `k - j1 - 1`. Let's re-evaluate 0.091. `k`=1, `j1`=2. Exp = 1 - 2 - 1 = -2. Correct. Let's re-evaluate 0.0000000912. `k`=1, `j1`=9. Exp = 1 - 9 - 1 = -9. Expected -8. Why? Ah, the problem states: "If there’s only one digit before the decimal point...". For 0.0000000912, the first non-zero is at index 9. The digits are 0 . 0 0 0 0 0 0 0 9 ... Indices: 0 1 2 3 4 5 6 7 8 9. `k`=1. `j1`=9. The number is 9.12... * 10^-8. My formula gave -9. Where is the off-by-one? The decimal point in scientific notation is placed AFTER the first significant digit. So the new decimal position is `j1 + 1`. The old decimal position is `k`. The displacement is `(j1 + 1) - k`. This is positive (shift right). So exponent is `-((j1 + 1) - k)` = `k - j1 - 1`. This seems correct for 0.091 (Exp -2). Why is it wrong for 0.0000000912? Let's count zeros. 0.0000000912 has seven zeros after decimal. Exponent should be -(7+1) = -8. `j1` is index of '9'. Index 0 is '0', 1 is '.', 2-8 are '0's (7 zeros), 9 is '9'. So `j1`=9. `k`=1. `k - j1 - 1` = 1 - 9 - 1 = -9. The formula calculates -9. The expected is -8. The error is likely in the interpretation of `j1` or the formula. Actually, if the number is 0.09, `j1`=2, `k`=1. Exp = -2. 9e-2? No, 0.09 = 9e-2. But output format requires 9.e-2? Or 9e-2? "If it’s an integer...". 9 is integer. So 9e-2. My code prints `9.e-2`? No, `j1==j` check. If only one significant digit? No, `j` is last significant digit. If `j1==j`, it prints integer base. For 0.0912, `j1`=2, `j`=5. Prints `9.12e-2`. Correct. For 0.0000000912, `j1`=9, `j`=19. Prints `9.12...e-9`. Expected `e-8`. The issue is that `gets` might include newline? No, `strlen` handles it. Is `j1` calculated correctly? Yes. Is `k` calculated correctly? Yes. The standard rule: Exponent = (Index of Decimal Point) - (Index of First Significant Digit) + (1 if decimal is placed after first digit?). Let's look at 123.45. `k`=3, `j1`=0. Exp = 2. Formula `k - j1 - 1`? 3 - 0 - 1 = 2. Correct. Let's look at 0.123. `k`=1, `j1`=2. Exp = -1. Formula `1 - 2 - 1` = -2. Incorrect. 0.123 = 1.23e-1. So for numbers < 1, the formula `k - j1 - 1` is off by 1. It should be `k - j1`. Let's check 0.091. `k`=1, `j1`=2. `1-2` = -1. But 0.091 = 9.1e-2. So `k-j1` is also wrong. Wait. 0.123. First sig digit '1' at index 2. Decimal at 1. Distance is 1. Exponent -1. 0.091. First sig '9' at index 2? No. "0.091". Index 0:'0', 1:'.', 2:'0', 3:'9'. `j1`=3. `k`=1. Exp -2. Formula `k - j1` = 1 - 3 = -2. Correct. Previous trace for 0.091 assumed `j1`=2 which was wrong (index of '0' after dot). In 0.0000000912: Indices 0:'0', 1:'.', 2:'0'...8:'0', 9:'9'. `j1`=9. `k`=1. `k - j1` = 1 - 9 = -8. Correct. So the formula should be `k - j1`. The code has `k - j1 - 1`.
    }
    return 0;
}