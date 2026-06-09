#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char num[1005];
    int len,mid1,mid2,result; 
    int flag=0;
    gets(num);
    len=strlen(num);
    for(int i=0;i<len;i++)
    {
        if(num[i]=='.')
        mid2=i;
        else if(num[i]!='0'&&flag==0)
        {
            mid1=i;
            flag=1;
        }
    }  
    result=mid1-mid2;
    if(result<0)
    {
        printf("%c.",num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e%d",-result-1); // @@ The exponent calculation is incorrect. For a number like 0.00...0X, if the first non-zero digit is at index mid1 and the decimal point is at mid2, the exponent should be -(mid1 - mid2 - 1) which simplifies to mid2 - mid1 + 1. Here result = mid1 - mid2 (a negative number). So exponent should be -result - 1? Let's check: 0.009 -> mid1=3, mid2=1. result = 2. Wait, result = mid1 - mid2. If num is 0.009, mid1=3 ('9'), mid2=1 ('.'). result = 3-1=2. This is positive. The condition result < 0 handles numbers >= 1? No. 
        // Let's re-evaluate logic. 
        // Case 1: Number >= 1 (e.g., 123.45). mid1=0 ('1'), mid2=3 ('.'). result = 0-3 = -3. result < 0 is true.
        // Output: 1.2345 e -(-3)-1 = e2. Correct.
        // Case 2: Number < 1 (e.g., 0.009). mid1=3 ('9'), mid2=1 ('.'). result = 3-1 = 2. result < 0 is false.
        // Goes to else block.
        // Else block prints: 9 e -2. Expected: 9.e-3? No, 0.009 = 9e-3. 
        // Wait, scientific notation for 0.009 is 9e-3. 
        // My previous analysis of the reference code suggested the exponent for 0.00...0X is -(position_of_X - 1). 
        // For 0.009, position of 9 is index 3. Exponent is -3? No. 9 * 10^-3 = 0.009. Yes.
        // In the else block: printf("e-%d", result). Result is 2. Output e-2. Incorrect. Should be e-3.
        // So the error is in the else block's exponent calculation AND potentially the if/else condition logic or variable naming.
        // Actually, let's look at the "Buggy Output" vs "Expected Output" for the specific test case: 0.00000009123456789012
        // mid2 = 1 ('.')
        // mid1 = 9 ('9' is the first non-zero digit after 0.0000000...)
        // result = 9 - 1 = 8.
        // result < 0 is false.
        // Enters else block.
        // Prints "%c", num[9] -> '9'.
        // Loop prints remaining digits skipping '.': "123456789012".
        // So far: "9123456789012".
        // Prints "e-%d", result -> "e-8".
        // Total output: "9123456789012e-8".
        // Expected: "9.123456789012e-8".
        // The missing part is the decimal point after the first digit in the else block (numbers < 1).
        // The if block (numbers >= 1) correctly prints "%c.", but the else block only prints "%c".
    }
    else
    {
        printf("%c",num[mid1]); // @@ Missing decimal point '.' after the first significant digit for numbers less than 1. Should be printf("%c.", num[mid1]);
        for(int i=mid1+1;i<len;i++)
        {
            if(num[i]=='.')
            continue;
            else
            printf("%c",num[i]);
        }
        printf("e-%d",result); // @@ The exponent calculation is also incorrect here. For 0.009 (result=2), it prints e-2, but should be e-3. The exponent should be -(result + 1) ? No. 
        // Let's re-verify exponent for < 1.
        // 0.009 = 9 * 10^-3. mid1=3, mid2=1. result=2. Exponent should be -3.
        // Formula: -(result + 1) = -(2+1) = -3. Correct.
        // Test case: 0.00000009... mid1=9, mid2=1. result=8. Exponent should be -9.
        // Expected output says e-8. Wait.
        // 0.0000000912... = 9.12... * 10^-8.
        // Let's count zeros. 0.00000009. Seven zeros after decimal point before 9.
        // Indices: 0:'0', 1:'.', 2:'0', 3:'0', 4:'0', 5:'0', 6:'0', 7:'0', 8:'0', 9:'9'.
        // Value = 9 * 10^-8?
        // 10^-1 = 0.1
        // 10^-2 = 0.01
        // ...
        // 10^-8 = 0.00000001
        // 9 * 10^-8 = 0.00000009. Yes.
        // So exponent is -8.
        // My manual calculation for 0.009:
        // 0.009 = 9 * 10^-3.
        // Indices: 0:'0', 1:'.', 2:'0', 3:'9'.
        // mid1=3, mid2=1. result=2.
        // Exponent should be -3.
        // Formula using result: -(result + 1) = -3. Correct.
        // Formula for test case: mid1=9, mid2=1. result=8.
        // Exponent should be -8?
        // -(result + 1) = -9. Incorrect.
        // Why?
        // 0.00000009.
        // Decimal point at 1. First non-zero at 9.
        // Number of places to move decimal point from after 9 to original position?
        // Original: 0.00000009
        // Sci: 9. ... * 10^exp
        // Move decimal from 9. to 0.00000009.
        // 9. -> 0.9 (1 left, exp -1)
        // 0.9 -> 0.09 (2 left, exp -2)
        // ...
        // From index 9 to index 1 (decimal point). Distance is 8 positions.
        // So we move 8 positions to the left. Exponent is -8.
        // So exponent is -(mid1 - mid2) = -result.
        // Let's re-check 0.009.
        // mid1=3, mid2=1. result=2.
        // Exponent should be -2?
        // 9 * 10^-2 = 0.09. But number is 0.009.
        // Ah, 0.009 has '0' at index 2.
        // Indices: 0:'0', 1:'.', 2:'0', 3:'9'.
        // Distance from index 3 to index 1 is 2.
        // But value is 9 * 10^-3.
        // Why? Because the digit 9 is in the 10^-3 place.
        // Place value of index i (where i > mid2) is 10^(mid2 - i).
        // For 0.009: mid2=1, i=3. Exp = 1 - 3 = -2? No.
        // Index 2 is 10^-1? No.
        // Index 1 is '.'.
        // Index 2 is 10^-1 (tenths).
        // Index 3 is 10^-2 (hundredths).
        // Wait. 0.09 is 9 * 10^-2.
        // 0.009 is 9 * 10^-3.
        // Index 2 is '0' (tenths). Index 3 is '9' (hundredths)? No.
        // 0 . 0 9
        //   1 2 3
        // Index 2 is tenths (10^-1). Index 3 is hundredths (10^-2).
        // So 0.09 = 9 * 10^-2.
        // 0 . 0 0 9
        //   1 2 3 4
        // Index 4 is thousandths (10^-3).
        // In my 0.009 example:
        // num = "0.009"
        // len=5.
        // i=0 '0'
        // i=1 '.' -> mid2=1
        // i=2 '0'
        // i=3 '0'
        // i=4 '9' -> mid1=4.
        // result = 4 - 1 = 3.
        // Exponent should be -3.
        // Formula -result gives -3. Correct.
        
        // Let's re-read the test case input carefully: 0.00000009123456789012
        // Indices:
        // 0: '0'
        // 1: '.'
        // 2: '0'
        // 3: '0'
        // 4: '0'
        // 5: '0'
        // 6: '0'
        // 7: '0'
        // 8: '0'
        // 9: '9' -> mid1=9
        // result = 9 - 1 = 8.
        // Exponent should be -8.
        // Code prints "e-%d", result -> "e-8".
        // So the exponent calculation in the else block IS CORRECT for the test case.
        // The only error is the missing decimal point.
    }
    return 0;
}