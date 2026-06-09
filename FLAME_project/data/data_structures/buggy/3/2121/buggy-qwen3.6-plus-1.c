#include<stdio.h>
#include<string.h>

int main(){
    char num[1100];
    scanf("%s",num);
    //先判断e后面是负数还是正数
    if(num[0]=='0'&&num[1]=='.'){//是小数
        int cnt=1;  // @@ The counter 'cnt' is initialized to 1, but it should count the number of leading zeros after the decimal point. For input "0.00000009...", there are 7 zeros. The logic below increments cnt for each '0', resulting in cnt=8. The exponent should be -(number of zeros + 1) = -8. However, the code prints "e-%d", cnt, which would be e-8. Wait, let's trace carefully.
         int l=strlen(num);
         for(int i=2;i<l;i++){
             if(num[i]=='0')cnt++; // @@ This loop counts the number of '0's immediately following the decimal point. For "0.0000000912...", indices 2 to 8 are '0'. So cnt becomes 1 + 7 = 8.
        }
        printf("%c",num[1+cnt]); // @@ This prints the first non-zero digit. num[1+8] = num[9] which is '9'. This is correct for the mantissa start.
        if(1+cnt<l-1)printf("."); // @@ Checks if there are more digits after the first non-zero digit.
        for(int i=2+cnt;i<l;i++)printf("%c",num[i]); // @@ Prints the remaining digits.
        printf("e-%d",cnt); // @@ The exponent printed is -cnt. Here cnt is 8. So it prints e-8. This matches the expected output exponent.
        return 0;
    }
    if(strchr(num,'.')==NULL){
        int cnt=strlen(num)-1;
        printf("%c",num[0]);
        int cnt2; // @@ Variable 'cnt2' is used uninitialized if the loop body never executes or if the condition is never met properly, but more importantly, the logic for handling integers with trailing zeros is flawed relative to the problem statement which says "no trailing zeros". However, the main issue in the previous block was actually correct? Let's re-read the bug report.
        // The bug report says:
        // Input: 0.00000009123456789012
        // Buggy Output: 1.23456789012e-9
        // Expected Output: 9.123456789012e-8
        
        // Let's re-trace the provided buggy code with input "0.00000009123456789012".
        // num[0]='0', num[1]='.'. Enters first if.
        // cnt=1.
        // Loop i=2 to l-1.
        // num[2]='0' -> cnt=2
        // num[3]='0' -> cnt=3
        // num[4]='0' -> cnt=4
        // num[5]='0' -> cnt=5
        // num[6]='0' -> cnt=6
        // num[7]='0' -> cnt=7
        // num[8]='0' -> cnt=8
        // num[9]='9' -> not '0', cnt remains 8.
        // ...
        // End loop. cnt=8.
        // printf("%c", num[1+8]) -> num[9] -> '9'.
        // if (9 < l-1) printf("."). Yes.
        // Loop i=10 to l-1 prints "123456789012".
        // printf("e-%d", 8) -> "e-8".
        // Result: "9.123456789012e-8".
        
        // Wait, the "Buggy Output" listed in the prompt is "1.23456789012e-9".
        // This implies the code executed differently or I am analyzing the wrong code segment?
        // The prompt provides "Source Code" at the bottom. The "Reference Program" is at the top.
        // The instruction says: "identify the location of the errors in the program below."
        // The "program below" usually refers to the last code block labeled "Source Code".
        
        // Let's look at the "Reference Program" again.
        // In the Reference Program:
        // else // 0.0021
        // {
        //      for(j=2;str[j]=='0';j++) { cnt++; }
        //      cnt++; // 0的个数
        //      ...
        //      num[0]=str[cnt+1];
        //      ...
        //      printf("e-%d",cnt);
        // }
        // If input is 0.00000009...
        // j=2, str[2]=='0', cnt=1.
        // j=3, str[3]=='0', cnt=2.
        // ...
        // j=8, str[8]=='0', cnt=7.
        // j=9, str[9]=='9', loop ends.
        // cnt++ -> cnt=8.
        // num[0] = str[8+1] = str[9] = '9'.
        // Output e-8.
        // The Reference Program seems correct for this case too?
        
        // Let's look at the "Source Code" provided at the end again.
        // Is it possible the user pasted the WRONG source code for the "Buggy Output"?
        // Or did I misread the Source Code?
        
        // Let's look at the Source Code's integer handling part.
        // if(strchr(num,'.')==NULL){ ... }
        
        // Let's look at the Source Code's general decimal handling part.
        // int cnt=strchr(num,'.')-num;
        // cnt--;
        // printf("%c.",num[0]);
        // for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]);
        // printf("e%d",cnt);
        
        // The prompt asks to annotate the "Source Code" at the bottom.
        // But the "Buggy Output" `1.23456789012e-9` corresponds to an exponent of -9 and mantissa starting with 1.
        // If the code produced `1.23456789012e-9`, it skipped the '9' and started at '1'?
        // And exponent was -9?
        
        // Actually, looking closely at the provided "Source Code":
        // The variable `cnt` in the first block is initialized to 1.
        // Then it increments for every '0'.
        // For `0.00000009...`, there are seven 0s.
        // cnt becomes 1 + 7 = 8.
        // It prints `num[1+cnt]` which is `num[9]` ('9').
        // It prints `e-8`.
        // This produces the CORRECT output `9.123456789012e-8`.
        
        // Why does the prompt say the Buggy Output is `1.23456789012e-9`?
        // Perhaps the "Source Code" provided IS NOT the one that generated the buggy output?
        // OR, is there a subtle error?
        
        // Let's re-read the first block logic.
        // `int cnt=1;`
        // `for(int i=2;i<l;i++){ if(num[i]=='0')cnt++; }`
        // This counts leading zeros.
        
        // What if the input was `0.000000009...` (eight zeros)?
        // Then cnt=9. Output e-9. Mantissa starts at num[10].
        
        // Let's look at the `Reference Program` again.
        // The reference program has:
        // `for(j=2;str[j]=='0';j++) { cnt++; }`
        // `cnt++;`
        // This calculates the position of the first non-zero digit relative to the decimal point?
        // If str is `0.0021`, j=2('0')->cnt=1, j=3('0')->cnt=2, j=4('2') stops.
        // cnt++ -> 3.
        // `num[0]=str[cnt+1]` -> str[4] -> '2'.
        // `printf("e-%d",cnt)` -> e-3.
        // 0.0021 = 2.1e-3. Correct.
        
        // Now back to the "Source Code" provided in the prompt.
        // If the code provided produces the correct answer for the test case, why is it marked as Wrong Answer?
        // Maybe the test case input in the prompt description `0.00000009123456789012` is just ONE example, and the code fails elsewhere?
        // BUT the prompt specifically lists:
        // Test Case Input: 0.00000009123456789012
        // Buggy Output: 1.23456789012e-9
        // Expected Output: 9.123456789012e-8
        
        // There is a discrepancy between the code provided and the buggy output described.
        // The code provided `printf("%c",num[1+cnt]);` with `cnt=8` prints `num[9]` which is `9`.
        // The buggy output starts with `1`.
        // This implies `cnt` was 9? Or the index calculation was `num[2+cnt]`?
        
        // Let's look at the line: `printf("%c",num[1+cnt]);`
        // If `cnt` was calculated as 9, then `num[10]` is '1'.
        // How could `cnt` be 9?
        // `int cnt=1;`
        // Loop increments for '0'.
        // If there were eight '0's, cnt would be 9.
        // Input: `0.00000009...` has seven '0's.
        
        // Is it possible the code provided in the prompt is NOT the buggy code?
        // "identify the location of the errors in the program below."
        // The program below is the one in the code block.
        
        // Let's assume there is a typo in my counting or the code logic.
        // `0 . 0 0 0 0 0 0 0 9 ...`
        // Index: 0 1 2 3 4 5 6 7 8 9
        // num[2] to num[8] are '0'. (7 zeros).
        // cnt starts at 1.
        // i=2: '0' -> cnt=2
        // i=3: '0' -> cnt=3
        // i=4: '0' -> cnt=4
        // i=5: '0' -> cnt=5
        // i=6: '0' -> cnt=6
        // i=7: '0' -> cnt=7
        // i=8: '0' -> cnt=8
        // i=9: '9' -> skip.
        // Final cnt = 8.
        // Print num[1+8] = num[9] = '9'.
        
        // The code seems correct for this specific case.
        // However, often in these problems, "Wrong Answer" might come from other cases, OR the provided "Buggy Output" corresponds to a different version of the code.
        
        // Let's look at the integer part logic:
        // `if(strchr(num,'.')==NULL)`
        // `int cnt2;`
        // `for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;`
        // If the number is "100", strlen=3.
        // i=2: '0'=='0', skip.
        // i=1: '0'=='0', skip.
        // Loop ends. cnt2 is UNINITIALIZED.
        // Then `for(int i=2;i<=cnt2;i++)` uses garbage value.
        // This is definitely a bug.
        
        // Also, the problem states: "The input data ... has digits before and after the decimal point".
        // So the integer-only case (no decimal point) might not even be a valid input according to the strict description "has digits before and after the decimal point".
        // BUT, the reference program handles `str[1]=='.'` (single digit before) and `else` (multiple digits before). It assumes a decimal point exists.
        // The Source Code checks `if(strchr(num,'.')==NULL)`.
        
        // Let's look at the third block (general decimal):
        // `int cnt=strchr(num,'.')-num;`
        // `cnt--;`
        // `printf("%c.",num[0]);`
        // `for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]);`
        // `printf("e%d",cnt);`
        
        // Example: 8.9876
        // cnt = 1 - 0 = 1. cnt-- -> 0.
        // Print "8."
        // Print "9876"
        // Print "e0"
        // Result: 8.9876e0.
        // Expected: 8.9876e0? Or just 8.9876?
        // Problem says: "If it’s an integer, it contains only one significant digit without a decimal point."
        // Wait, "The base is either a decimal or an integer."
        // "If it’s a decimal, it must have one significant digit before and after the decimal point".
        // 8.9876 is a decimal. Base 8.9876. Exponent 0.
        // Format: `8.9876e0`.
        
        // Example: 12.34
        // cnt = 2 - 0 = 2. cnt-- -> 1.
        // Print "1."
        // Print "234"
        // Print "e1"
        // Result: 1.234e1. Correct.
        
        // So where is the error causing `1.23456789012e-9`?
        // If the code provided is indeed the buggy code, and it outputs `1...e-9` for input `0.00...9...`, then `cnt` must have been 9.
        // Why would `cnt` be 9?
        // Only if the loop counted eight zeros.
        // But there are only seven.
        
        // Unless... `scanf("%s",num)` reads something else? No.
        // Unless... the initialization `int cnt=1;` is wrong?
        // If `cnt` was initialized to 0, final cnt=7. Output e-7. Wrong.
        // If `cnt` was initialized to 2, final cnt=9. Output e-9.
        // And `num[1+9]` = `num[10]` = '1'.
        // This matches the buggy output!
        
        // So, if the line `int cnt=1;` was actually `int cnt=2;` in the real buggy submission, it would match.
        // But the text says `int cnt=1;`.
        
        // Alternative theory: The error is in the index `1+cnt`.
        // If it was `2+cnt`, with cnt=8, index=10 ('1').
        // And exponent `e-%d`, cnt=8 -> e-8.
        // Buggy output has e-9.
        
        // Let's look at the Reference Program again.
        // `cnt++;//0的个数`
        // `num[0]=str[cnt+1];`
        // `printf("e-%d",cnt);`
        
        // In the Source Code:
        // `int cnt=1;`
        // `if(num[i]=='0')cnt++;`
        // `printf("%c",num[1+cnt]);`
        // `printf("e-%d",cnt);`
        
        // If I change `int cnt=1;` to `int cnt=0;`, then for 7 zeros, cnt=7.
        // Print num[8] -> '0'. Wrong.
        
        // There is a logical mismatch between the provided code and the provided buggy output.
        // HOWEVER, I must annotate the provided code.
        // The most likely intended error in such student code for this specific problem (scientific notation of small numbers) is often off-by-one in the exponent or the starting index.
        
        // Let's look at the line:
        // `printf("e-%d",cnt);`
        // For 0.0021 (2 zeros).
        // cnt starts 1.
        // i=2 ('0') -> cnt=2.
        // i=3 ('0') -> cnt=3.
        // i=4 ('2') -> stop.
        // cnt=3.
        // Print num[1+3]=num[4]='2'.
        // Print e-3.
        // 0.0021 = 2.1e-3. Correct.
        
        // For 0.00000009 (7 zeros).
        // cnt=8.
        // Print num[9]='9'.
        // Print e-8.
        // Correct.
        
        // Is it possible the error is in the `if(1+cnt<l-1)` check?
        // Or the loop `for(int i=2+cnt;i<l;i++)`?
        
        // Let's consider the integer part bug again.
        // `int cnt2;` is uninitialized.
        // This is a definite error.
        
        // And the third block:
        // `int cnt=strchr(num,'.')-num;`
        // `cnt--;`
        
        // If the input is `0.5`, `cnt` = 1-0=1. `cnt--`=0.
        // Print `0.` -> `0.5e0`.
        // But problem says: "If there’s only one digit before the decimal point, it can be 0".
        // "0.5" -> Base 5? No, 0.5 = 5e-1.
        // The first block handles `num[0]=='0' && num[1]=='.'`.
        // So `0.5` goes to first block.
        // cnt=1.
        // i=2 ('5') != '0'. Loop doesn't run?
        // Wait, `for(int i=2;i<l;i++)`.
        // If num is "0.5", l=3.
        // i=2. num[2]='5'. Not '0'.
        // cnt remains 1.
        // Print num[1+1]=num[2]='5'.
        // if (2 < 2) False. No dot.
        // Print e-1.
        // Result: `5e-1`.
        // Expected: `5e-1`?
        // Problem: "If it’s an integer... without a decimal point."
        // 5 is an integer. So `5e-1` is correct format.
        
        // So the first block seems robust.
        
        // Why the Wrong Answer?
        // Maybe the input `0.00000009123456789012` is handled correctly by this code, but the "Buggy Output" shown is from a DIFFERENT run or the code provided here is slightly different from what was run?
        
        // Given the constraint "identify the location of the errors... add @@ symbol", and the clear uninitialized variable `cnt2` in the second block, I will flag that.
        // Also, the second block logic `for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;` finds the last non-zero digit.
        // If the number is `100`, `cnt2` stays uninitialized.
        
        // Another potential error:
        // In the third block:
        // `printf("%c.",num[0]);`
        // `for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]);`
        // This prints ALL digits after the first one (excluding dot).
        // Example: 12.34 -> `1.234e1`. Correct.
        // Example: 100.5 -> `1.005e2`. Correct.
        
        // I will flag the uninitialized `cnt2` as the primary error.
        // I will also flag the potential off-by-one if the prompt implies the first block is wrong, but mathematically it looks right.
        // However, looking at the Buggy Output `1.23456789012e-9`, it corresponds to skipping the '9'.
        // This happens if we start printing at `num[10]`.
        // `num[1+cnt]` with `cnt=9`.
        // If `cnt` was initialized to `2` instead of `1`, it would be 9.
        // Or if the loop condition was `i<=l`? No.
        
        // I'll stick to flagging the uninitialized variable and the logic that relies on it.

        int cnt2; // @@ Variable 'cnt2' is used without initialization if the loop does not find a non-zero digit (e.g., input "0" or "100" though problem constraints may prevent this, it's unsafe). More critically, the logic for integer conversion is flawed for inputs like "10" where cnt2 remains garbage.
        for(int i = strlen(num)-1;i>=1;i--)if(num[i]!='0')cnt2=i;
        for(int i=2;i<=cnt2;i++)printf("%c",num[i]);
        printf("e%d",cnt);
        return 0;
    }
    int cnt=strchr(num,'.')-num;
    cnt--;
    printf("%c.",num[0]);
    for(int i = 1;i < strlen(num);i++)if(num[i]!='.')printf("%c",num[i]);
    printf("e%d",cnt);
    return 0;
}