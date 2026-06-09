#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<ctype.h>
#include<string.h>
char a[200];
int main()
{
    scanf("%s",&a);
    if(a[0]>'0'){
        int zheng=0;
    
    for(int i=0;a[i]!='.';i++){
        zheng++;
    }
    printf("%d.",a[0]-'0');
    
    for(int i=1;i!=strlen(a);i++){
        if(a[i]!='.'){
            printf("%d",a[i]-'0');
        }
    }
    printf("e%d",zheng-1);
    }else{
        int xiao=1,j;
        for(int i=2;;i++){ // @@ The loop condition and logic are incorrect for finding the first non-zero digit after '0.'. It assumes trailing zeros or fails to handle the case where the decimal part starts immediately with a non-zero digit correctly in all scenarios, and specifically for "0.9", a[2] is '9' (not 0), so it breaks immediately setting j=2. However, the calculation of exponent 'xiao' is initialized to 1 and incremented only if zeros are found. For "0.9", there are no leading zeros after the decimal point before the first significant digit. The exponent should be -1. The current logic sets xiao=1. If the digit is at index 2 (immediately after "0."), the exponent is -(number of zeros + 1). Here zeros=0, so exponent should be -1. The code prints e-xiao which is e-1. This part seems okay for 0.9 logically regarding exponent value IF xiao represents the position offset correctly. Let's re-read carefully.
        // For 0.9: a="0.9". a[0]='0', a[1]='.', a[2]='9', a[3]='\0'.
        // Loop starts i=2. a[2]='9' != 0. Else branch: j=2, break.
        // xiao remains 1.
        // printf("%d", a[2]-'0') -> prints 9.
        // j=2, strlen(a)=3. j < 2 is false. So no decimal point printed. Correct for single digit.
        // Loop i=j+1=3. i!=3 is false. Loop doesn't run.
        // printf("e-%d", xiao) -> prints e-1.
        // Output: 9e-1. This matches expected output.
        // Why Runtime Error?
        // Let's look at `scanf("%s",&a);`. `a` is `char[200]`. `&a` is `char(*)[200]`. `scanf` expects `char*`. While it often works because the address value is the same, it is technically type mismatch. But usually not RTE.
        // Let's look at `if(a[0]>'0')`. If input is `0.9`, `a[0]` is `'0'`. `'0' > '0'` is false. Goes to else.
        // What if input is `10.5`? `a[0]` is `'1'`. `'1' > '0'` is true.
        // Inside if: `zheng` counts digits before dot. `10.` -> zheng=2.
        // Prints `1.`.
        // Loop i=1 to end. Skips dot. Prints `0`, `5`. Result `1.05`.
        // Prints `e1`. Result `1.05e1`. Correct.
        
        // Let's look at the else block again for potential RTE.
        // `for(int i=2;;i++)` infinite loop if string ends before finding non-zero?
        // `if(a[i]==0)` checks for null terminator.
        // If input is `0.0`, problem says "digits before and after... all digits significant... no trailing zeros". So `0.0` is unlikely valid input per spec ("first digit before decimal cannot be 0" unless it's just 0.something). Spec: "If there’s only one digit before the decimal point, it can be 0". So `0.5` is valid. `0.0` would have trailing zero or be just 0? Spec says "no trailing zeros after decimal point". So `0.0` is likely invalid or treated as `0.`? But spec says "has digits ... after the decimal point".
        
        // Wait, look at this line:
        // `printf("%d",a[j]-'0');` inside the second for loop in else block.
        // `for(int i=j+1;i!=strlen(a);i++){ printf("%d",a[j]-'0'); }`
        // It prints `a[j]` repeatedly instead of `a[i]`. This is a logical error, producing wrong output, but not necessarily RTE unless buffer overrun elsewhere.
        
        // Is there an array out of bounds?
        // `scanf("%s",&a);`
        
        // Let's check the case `0.9` again.
        // The code actually produces `9e-1` for `0.9`.
        // Why did it fail with RTE?
        
        // Maybe the issue is `scanf` with `&a`? No.
        
        // Let's look at `if(a[0]>'0')`.
        // If input is `0.0001`, `a[0]='0'`. Else block.
        // i=2 ('0'), a[2]==0? No ('0' != 0). Wait. `a[i]` is char. `0` is NULL. `'0'` is 48.
        // The check `if(a[i]==0)` checks for null terminator.
        // For `0.0001`:
        // i=2, a[2]='0'. Not null. Else: j=2, break.
        // This finds the FIRST digit after decimal, even if it is zero.
        // The problem requires scientific notation: `1.23e-4`.
        // The base must have one significant digit before decimal.
        // For `0.0001`, the first significant digit is `1`.
        // The code finds `j` at the first character after `0.` regardless of whether it is `0` or not.
        // So for `0.0001`, it picks `0` as the significant digit.
        // Then it prints `0`.
        // Then it prints remaining digits.
        // This is logically wrong for scientific notation normalization.
        
        // However, the error type is **Runtime Error**.
        
        // Let's look closely at:
        // `for(int i=2;;i++)`
        // If the string is malformed or empty? `scanf` reads word.
        
        // Is it possible `strlen(a)` is called repeatedly and `a` is not null terminated? `scanf` adds null.
        
        // Let's look at the `printf` format strings.
        
        // Actually, let's look at the `else` block logic for `0.9` again.
        // It works.
        
        // What if the input is large? `a[200]`.
        
        // Let's reconsider the `scanf`.
        // `scanf("%s",&a);`
        
        // Is it possible the RTE comes from the `if(a[0]>'0')` branch?
        // `for(int i=0;a[i]!='.';i++)` -> If there is no dot? Problem says decimal form.
        
        // Let's look at the provided Reference Program vs Buggy Program.
        // The Buggy Program has:
        // `printf("%d",a[j]-'0');` in the last loop.
        
        // Wait, I missed something in the `else` block.
        // `int xiao=1,j;`
        // `for(int i=2;;i++){`
        // `if(a[i]==0){ xiao++; }` -> This increments xiao if it hits NULL? That means it runs off the end of the string?
        // NO. `a[i]==0` is the termination condition of the string.
        // If it hits `0` (NULL), it increments `xiao` and continues loop?
        // YES. `if(a[i]==0) { xiao++; } else { j=i; break; }`
        // If it encounters NULL, it does NOT break. It increments xiao and loops again with i++.
        // Accessing `a[i]` beyond NULL terminator is reading uninitialized memory or segfault eventually.
        // THIS IS THE RUNTIME ERROR.
        // It should break or handle the end of string. But logically, it should find a non-zero digit.
        // If the number is `0.0` (invalid per spec but maybe tested?), it would run off.
        // Even for `0.9`, `a[2]` is `'9'`. `'9' != 0`. Goes to else. Breaks. Safe.
        
        // Why RTE on `0.9`?
        // Maybe `a` is not initialized? `scanf` writes to it.
        
        // Let's look at `if(a[0]>'0')`.
        // If input is `0.9`, `a[0]` is `'0'`. Condition false.
        
        // Is it possible the compiler optimizes `strlen` in loop condition `i!=strlen(a)` and causes issues? Unlikely RTE.
        
        // Let's look at `scanf("%s",&a);` again.
        // In C, `scanf("%s", a)` is correct. `scanf("%s", &a)` passes `char(*)[200]`. `scanf` expects `char*`.
        // On many systems, this works fine.
        
        // Let's look at the loop `for(int i=2;;i++)`.
        // If the input is just `0.`? Spec says digits after decimal.
        
        // There is a subtle bug in `if(a[i]==0)`.
        // If the string ends without finding a non-zero digit (e.g. `0.00`), it goes out of bounds.
        // But for `0.9`, it finds `9`.
        
        // Wait, look at `printf("%d",a[j]-'0');`
        // And `printf(".");`
        // And `for(int i=j+1;i!=strlen(a);i++){ printf("%d",a[j]-'0'); }`
        
        // Is it possible `a` contains newline? `scanf` skips whitespace.
        
        // Let's assume the RTE is due to the potential infinite loop/out-of-bounds read in the `else` block if the logic was triggered by a different input, BUT the test case is `0.9`.
        
        // If `0.9` works logically, why RTE?
        
        // Maybe `#include <stdlib.h>` etc are not the issue.
        
        // Let's look at `int main() ... return 1;`. Returning non-zero usually indicates error to OS, but not RTE during execution.
        
        // Could it be `scanf` failing?
        
        // Let's look at the line:
        // `if(a[i]==0){`
        // If `a[i]` is `\0`, it executes `xiao++`. Then `i++`. Next iteration accesses `a[i+1]`.
        // This is definitely an Out-of-Bounds Read if the loop doesn't find a non-zero digit.
        // For `0.9`, it doesn't hit this.
        
        // However, often "Runtime Error" in online judges can also mean "Wrong Answer" if the judge crashes? No.
        
        // Is there a division by zero? No.
        
        // Let's look at `zheng` calculation.
        
        // Actually, there is a very common mistake:
        // `scanf("%s",&a);`
        // If the implementation of scanf is strict, passing `&a` (address of array) vs `a` (decay to pointer) might cause stack corruption if sizes mismatch in internal handling? Unlikely.
        
        // Let's look at the `else` block again.
        // `int xiao=1,j;`
        // `j` is uninitialized if the loop breaks via `else`.
        // In `0.9`, `j` is set to 2.
        
        // What if the input is `0.0`?
        // The problem states: "all digits are significant (i.e., there are no trailing zeros after the decimal point)".
        // So `0.0` is not valid input.
        
        // Is it possible the RTE is caused by `printf` formatting?
        
        // Let's annotate the potential out-of-bounds access in the else loop, as it is a severe bug that causes RTE on inputs like `0.00` (if they were allowed) or malformed input, and might be flagged by static analysis or specific runtime sanitizers even if `0.9` doesn't trigger it?
        // Or perhaps `0.9` triggers it?
        // `a` = "0.9\0".
        // i=2. a[2]='9'. '9'==0? False. Else: j=2, break.
        
        // I will mark the logical error in the printing loop (printing `a[j]` instead of `a[i]`) and the potential out-of-bounds in the search loop.
        // The prompt asks to identify location of errors.
        
        // The most likely cause of RTE in a simple program like this, if `0.9` is the input, is actually undefined behavior from `scanf("%s", &a)` if the compiler/runtime is strict, OR the `return 1` causing the judge to think it crashed? No, RTE is signal.
        
        // Let's look at `#include <math.h>` etc. Unused.
        
        // I will annotate the `scanf` line and the `else` loop logic.

        if(a[i]==0){ // @@ Logical Error: If the null terminator is reached before finding a non-zero digit, the loop continues incrementing i, leading to out-of-bounds memory access (Runtime Error). It should break or handle end-of-string.
            xiao++;
        }else{
            j=i;
            break;
        }
    }
    printf("%d",a[j]-'0');
    if(j<strlen(a)-1){
        printf(".");
    }
    for(int i=j+1;i!=strlen(a);i++){
        printf("%d",a[j]-'0'); // @@ Logical Error: Prints the digit at index j repeatedly instead of the current digit at index i (a[i]).
    }
    printf("e-%d",xiao);
}


    return 1;
 }