#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
char str[1001];
int main(){
    fgets(str,1000,stdin);
    int count=0,n=0,l=strlen(str);
    for(int i=0;i<l-1;i++){
        if('0'==str[i]) // @@ [Logic error: This condition checks if the character is '0', but continues loop. However, the subsequent logic for finding the first significant digit is flawed because it doesn't correctly handle the position relative to the decimal point for numbers like 0.9]
        continue;
        if(str[i]!='0'&&str[i]!='.'){
            if(n!=0)
            continue;
            n=i+1;
            if('0'==str[0])
            n=i-1; // @@ [Logic error: For input "0.9", str[0] is '0'. The first non-zero/non-dot char is '9' at index 2. n becomes 2+1=3. Then this line sets n = 2-1 = 1. This variable 'n' is intended to track the position of the first significant digit or related index, but the calculation is incorrect for determining the exponent and base construction.]
        }
        if('.'==str[i])
        count=i-1; // @@ [Logic error: 'count' is used to help calculate the exponent. For "0.9", dot is at index 1. count becomes 0. The exponent should be -1. The formula used later abs(n-count) or similar needs to correctly reflect the shift. Standard scientific notation for 0.9 is 9e-1. The exponent is -(number of places decimal moved right). Here decimal moves 1 place right. So exponent is -1.]
    }
    if('0'==str[0]){
        if(n+2>=l-1) // @@ [Logic error: This condition attempts to check if there are digits after the first significant one to decide if a decimal point is needed in the output base. For "0.9", l=4 (including newline). n=1. n+2=3. l-1=3. 3>=3 is true. It prints str[n+1] which is str[2] ('9'). This part accidentally works for single digit but the logic is fragile.]
        printf("%c",str[n+1]);
        for(int i=n+2;i<l-1;i++){
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count)); // @@ [Output error: For "0.9", n=1, count=0. abs(1-0)=1. Output is e-1. This matches expected exponent. However, the base printing logic above printed '9'. But wait, if n=1, str[n+1] is str[2]='9'. The loop starts at n+2=3. l-1=3. Loop doesn't run. So base is "9". Exponent is "-1". Result "9e-1". This seems correct for this specific case? Let's re-evaluate n calculation.
        // In the loop:
        // i=0: str[0]='0'. Continues.
        // i=1: str[1]='.'. count = 1-1=0.
        // i=2: str[2]='9'. Not '0', not '.'. n!=0 is false. n = 2+1=3. str[0]=='0' is true. n = 2-1=1.
        // So n=1, count=0.
        // Base print: str[n+1] = str[2] = '9'.
        // Exponent: abs(n-count) = abs(1-0) = 1. Prints "e-1".
        // Total: "9e-1".
        // Why did it fail? The buggy output was ".e-0".
        // Let's look at the other branch or initialization.
        // Ah, look at the first if in the loop: if('0'==str[i]) continue;
        // If the number is 0.9, str[0] is '0'. It continues.
        // str[1] is '.'. It is not '0'. It goes to next if.
        // str[1] is '.', so str[i]!='0' && str[i]!='.' is FALSE.
        // Next if: '.'==str[i] is TRUE. count = 0.
        // i=2. str[2] is '9'.
        // '0'==str[2] is FALSE.
        // str[2]!='0' && str[2]!='.' is TRUE.
        // n!=0 is FALSE (n is 0).
        // n = 2+1 = 3.
        // '0'==str[0] is TRUE.
        // n = 2-1 = 1.
        // So n=1.
        // Then if('0'==str[0]) is TRUE.
        // if(n+2 >= l-1). l=strlen("0.9\n") = 4. l-1=3. n+2 = 3. 3>=3 TRUE.
        // printf("%c", str[n+1]) -> str[2] -> '9'.
        // Loop i from 3 to 2. Doesn't run.
        // printf("e-%d", abs(1-0)) -> "e-1".
        // Expected: 9e-1.
        // Buggy Output provided in prompt: .e-0
        // This implies my trace of the provided code might differ from the actual execution environment or I missed something subtle.
        // Wait, look at the variable `n` initialization. `int count=0,n=0`.
        // What if the input parsing or string length is different?
        // Let's look at the `else` branch `if(str[0]!='0')`.
        // The prompt says Buggy Output is `.e-0`.
        // This output `.e-0` suggests that the base printed was just `.` and exponent `0`.
        // This would happen if the code entered the `str[0]!='0'` branch? No, "0.9" starts with '0'.
        // Or if the `if('0'==str[0])` branch printed nothing for the digit?
        // If `n+2 >= l-1` was false?
        // If n was calculated differently?
        
        // Let's re-read the code carefully.
        // `if('0'==str[i]) continue;`
        // If input is `0.9`, `str` is `{'0', '.', '9', '\n', '\0'}`.
        // i=0: `str[0]` is '0'. Continue.
        // i=1: `str[1]` is '.'. Not '0'.
        // `str[1]!='0' && str[1]!='.'` is False.
        // `'.'==str[1]` is True. `count = 1-1 = 0`.
        // i=2: `str[2]` is '9'. Not '0'.
        // `str[2]!='0' && str[2]!='.'` is True.
        // `n!=0` is False.
        // `n = 2+1 = 3`.
        // `'0'==str[0]` is True.
        // `n = 2-1 = 1`.
        // End of loop.
        // `if('0'==str[0])` is True.
        // `n+2 = 3`. `l-1 = 3`. `3>=3` is True.
        // `printf("%c", str[2])` prints '9'.
        // Loop `i=n+2` (3) `< l-1` (3). False.
        // `printf("e-%d", abs(1-0))` prints "e-1".
        // Result: "9e-1".
        
        // Why does the prompt say Buggy Output is `.e-0`?
        // Perhaps the `n` calculation logic is fundamentally broken for other cases, or I am misinterpreting `n`.
        // Let's look at the `str[0]!='0'` branch.
        // `printf("%c.", str[n-1]);`
        // If the code somehow fell through or `n` was 0?
        // If `n` remained 0?
        // If the loop didn't find any non-zero digit? Impossible for 0.9.
        
        // Is it possible `fgets` includes `\r\n`?
        // If input is `0.9\r\n`, l=5.
        // i=0: '0' continue.
        // i=1: '.' count=0.
        // i=2: '9' n=1.
        // i=3: '\r' not '0'. not '.'. n!=0 (True) continue.
        // i=4: '\n' loop ends (i<l-1 -> 4<4 False).
        // Same result.
        
        // Let's look at the provided Buggy Output again: `.e-0`.
        // This looks like the output from the `str[0]!='0'` branch where `str[n-1]` was `.`?
        // Or maybe `n` was 1, so `str[0]` which is `0`? No.
        
        // Actually, there is a major logical flaw in how `n` is computed.
        // `n` is supposed to be the index of the first significant digit?
        // In `0.9`, first sig digit is '9' at index 2.
        // Code sets `n=1`.
        // In `12.3`, first sig digit is '1' at index 0.
        // i=0: '1'. n=1. str[0]!='0'. n stays 1.
        // count: dot at 2. count=1.
        // Branch `str[0]!='0'`:
        // printf("%c.", str[n-1]) -> str[0] -> '1.'.
        // Loop i=1 to end. skip dot. print '2','3'.
        // Base: "1.23".
        // Exp: abs(n-count-1) = abs(1-1-1) = 1.
        // Result: "1.23e1". Correct for 12.3.
        
        // Back to `0.9`.
        // If the code produced `.e-0`, it implies the base was `.` and exp `0`.
        // This happens if `printf("%c", str[n+1])` printed nothing or a dot?
        // And `abs(n-count)` was 0?
        
        // There is a subtle bug: `if('0'==str[i]) continue;`
        // This skips zeros.
        // What if the number is `0.09`?
        // i=0 '0' skip.
        // i=1 '.' count=0.
        // i=2 '0' skip.
        // i=3 '9' n=3-1=2?
        // n=3+1=4. n=3-1=2.
        // n=2. count=0.
        // Branch 0:
        // n+2=4. l=5 ("0.09\n"). l-1=4. 4>=4 True.
        // printf str[3] ('9').
        // exp abs(2-0)=2. "9e-2". Correct.
        
        // The prompt's buggy output `.e-0` is very strange for input `0.9` with this code.
        // However, looking at the line `if('0'==str[0])`, if this evaluates to false incorrectly? No.
        
        // Let's look at the line `n=i-1;` again.
        // For `0.9`, i=2. n=1.
        // The first significant digit is at index 2.
        // The code uses `n` as an offset.
        
        // Maybe the error is in the `str[0]!='0'` branch logic interfering? No, they are if/if.
        
        // Wait, look at `if(n+2>=l-1)`.
        // If this condition is FALSE, it prints nothing for the integer part?
        // Then it goes to loop `for(int i=n+2...`.
        // If `n+2 < l-1`, it prints digits starting from `n+2`.
        // It DOES NOT print a decimal point in the `0` branch!
        // The `0` branch assumes the first digit printed is the integer part?
        // No, scientific notation for 0.9 is `9e-1`. Base is `9` (integer).
        // Scientific notation for 0.09 is `9e-2`. Base is `9`.
        // Scientific notation for 0.12 is `1.2e-1`. Base is `1.2`.
        
        // In `0.12`:
        // i=0 '0' skip.
        // i=1 '.' count=0.
        // i=2 '1' n=2-1=1.
        // i=3 '2' n!=0 continue.
        // n=1. count=0. l=5.
        // n+2=3. l-1=4. 3>=4 False.
        // Skips `printf("%c", str[n+1])` which is str[2]='1'. **ERROR HERE**. It should print '1'.
        // Because `n+2 >= l-1` is false, it thinks there are more digits?
        // It enters loop `i=3`. prints str[3]='2'.
        // Output base: "2". Missing '1' and '.'.
        // Exp: abs(1-0)=1. "2e-1". Wrong. Should be "1.2e-1".
        
        // So the logic for printing the base in the `0` branch is completely broken.
        // It fails to print the first significant digit if there are subsequent digits.
        // And it never prints a decimal point.
        
        // Therefore, the lines responsible for printing the base in the `if('0'==str[0])` block are erroneous.
        ]
        printf("%c",str[n+1]);
        for(int i=n+2;i<l-1;i++){
            printf("%c",str[i]);
        }
        printf("e-%d",abs(n-count));
    }
    if(str[0]!='0'){
        printf("%c.",str[n-1]);
        for(int i=n;i<l-1;i++){
            if('.'==str[i])
            continue;
            printf("%c",str[i]);
        }
        printf("e%d",abs(n-count-1));
    }
return 0;
}