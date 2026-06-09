#include<stdio.h>
int main(){

char ch;
char a[100];
char b[100];
a[0]='0';
b[0]='0';
int i=0,j=0;

while((ch=getchar())!='.'){
      i++;
      a[i]=ch;

}

ch=getchar();
while((ch=getchar())!='\n'){
      j++;
      b[j]=ch;

}

if((i==1)&&(a[1]=='0')){
    int k=1;

    if(j==1){printf("%de-1",b[j]-'0');} // @@ [Logic Error: The condition k==j is checked later, but for input "0.9" (j=1), this branch prints "9e-1" which is correct. However, the else block below has logical flaws for other cases. More critically, if j > 1 and all digits are zero except the last, or similar edge cases, the logic fails. But specifically for Runtime Error on "0.9", let's look closer. Actually, "0.9" -> i=1, a[1]='0'. j=1, b[1]='9'. Enters if(j==1). Prints "9e-1". This seems correct for this specific case. Wait, the problem says Runtime Error. Let's re-read carefully.
    // Ah, look at the array initialization. a[0]='0', b[0]='0'.
    // Input "0.9".
    // First while: ch='0' != '.', i=1, a[1]='0'. Next ch='.' stops loop.
    // ch=getchar() reads '.'? No, the previous loop stopped WHEN ch was '.'. So the '.' is consumed by the while condition check.
    // The next getchar() reads '9'.
    // Second while: ch='9' != '\n', j=1, b[1]='9'. Next ch='\n' stops loop.
    // i=1, a[1]='0'. Condition (i==1)&&(a[1]=='0') is true.
    // j=1. Condition if(j==1) is true.
    // printf("%de-1", b[1]-'0') -> printf("%de-1", 9). Output: "9e-1".
    // This matches expected output. Why Runtime Error?
    
    // Let's look at the `else` branch of the outer if.
    // If input was "12.34".
    // First while: '1'->a[1], '2'->a[2]. '.' stops. i=2.
    // ch=getchar() reads '3'.
    // Second while: '3'->b[1], '4'->b[2]. '\n' stops. j=2.
    // Outer if false.
    // Else: printf("%d.", a[1]-'0') -> "1.".
    // Loop m=2 to i(2): printf("%d", a[2]-'0') -> "2". Output so far "1.2".
    // Loop m=1 to j(2): printf("%d", b[m]-'0') -> "34". Output so far "1.234".
    // printf("e%d", i-1) -> "e1". Final: "1.234e1". Correct.

    // Is there a buffer overflow or uninitialized variable?
    // What if input is "0.0"? Problem says "digits before and after... all digits significant... no trailing zeros". So "0.0" is unlikely valid input per spec, but "0.5" is.
    
    // Let's look at the `while(b[k]=='0')` loop in the `else` part of the inner if.
    // Input "0.05".
    // i=1, a[1]='0'.
    // ch=getchar() reads '0'.
    // Second while: '0'->b[1], '5'->b[2]. j=2.
    // Inner if(j==1) false.
    // k=1. while(b[1]=='0') -> true. k becomes 2.
    // while(b[2]=='0') -> false (b[2] is '5').
    // k=2, j=2.
    // if(k==j) -> true.
    // printf("%de-%d", b[j]-'0', k) -> printf("%de-%d", 5, 2). Output "5e-2". Correct.

    // Input "0.005".
    // b[1]='0', b[2]='0', b[3]='5'. j=3.
    // k=1. b[1]=='0' -> k=2.
    // b[2]=='0' -> k=3.
    // b[3]=='0' -> false.
    // k=3, j=3.
    // if(k==j) -> true.
    // printf("%de-%d", b[3]-'0', 3) -> "5e-3". Correct.

    // Input "0.50". Problem says no trailing zeros. So this input shouldn't exist.

    // Where is the Runtime Error?
    // Maybe `gets` vs `getchar`? No, using getchar.
    // Maybe `a` or `b` not null terminated? `printf` with `%s` is not used, only `%d` and chars. So null termination is not strictly required for the printing logic shown.

    // Let's look at the Reference Program provided in the prompt description vs the Source Code provided for annotation.
    // The prompt asks to annotate the "Source Code" at the bottom.
    // The Reference Program in the description is different from the Source Code to be annotated.
    // The Source Code to be annotated uses `getchar`.
    
    // Is it possible the input has no decimal point? The problem guarantees format.
    
    // Let's re-examine `ch=getchar();` after the first while loop.
    // The first while loop terminates when `ch` is '.'.
    // The next line `ch=getchar();` reads the character AFTER the dot.
    // Then the second while loop reads subsequent characters until newline.
    // This logic assumes there is at least one digit after the decimal point.
    // Problem says: "has digits before and after the decimal point". So this is safe.

    // What if the number is large? `a[100]`, `b[100]`. Should be enough.

    // Let's look at the `else` block of the inner `if(j==1)` again.
    // `if(k!=j){ ... }`
    // If `k < j`, it prints decimal.
    // Example: "0.102". (Invalid per spec "no trailing zeros", but "0.102" has no trailing zero).
    // b[1]='1', b[2]='0', b[3]='2'. j=3.
    // k=1. b[1]!='0'. Loop doesn't run. k=1.
    // k!=j (1!=3).
    // printf("%d.", b[1]-'0') -> "1.".
    // Loop m=k+1(2) to j(3).
    // m=2: printf("%d", b[2]-'0') -> "0".
    // m=3: printf("%d", b[3]-'0') -> "2".
    // printf("e-%d", k) -> "e-1".
    // Result: "1.02e-1". Correct.

    // Is there an issue with `a[1]` access if `i=0`?
    // If input is ".5"? Problem says "digits before...". So "0.5" or "5.0".
    // If input is "5.0"?
    // First while: '5'->a[1]. '.' stops. i=1.
    // ch=getchar() reads '0'.
    // Second while: '0'->b[1]. '\n' stops. j=1.
    // Outer if: (i==1)&&(a[1]=='0') -> (1==1)&&('5'=='0') -> False.
    // Else branch:
    // printf("%d.", a[1]-'0') -> "5.".
    // Loop m=2 to i(1). Loop doesn't run.
    // Loop m=1 to j(1). printf("%d", b[1]-'0') -> "0".
    // printf("e%d", i-1) -> "e0".
    // Result: "5.0e0".
    // Expected for "5.0": Base must have one sig digit before/after if decimal. "5.0" is valid?
    // Problem: "If it’s a decimal, it must have one significant digit before and after... no trailing zeros".
    // "5.0" has trailing zero. So base should be integer "5"?
    // Rule: "If it’s an integer, it contains only one significant digit without a decimal point."
    // So "5.0" should become "5e0".
    // The code outputs "5.0e0". This is logically incorrect per spec, but is it a Runtime Error? No.

    // Let's look closely at the test case "0.9" again.
    // The code produces "9e-1".
    // The prompt says "Buggy Output: [Empty]" and "Expected Output: 9e-1".
    // And Error Type: Runtime Error.
    
    // If the output is empty, maybe the program crashed before printing?
    // Or maybe `printf` buffer wasn't flushed? Usually `\n` or program exit flushes.
    
    // Is it possible `getchar()` returns EOF?
    // If input is just "0.9\n".
    
    // Let's look at variable `k` initialization. `int k=1;`.
    
    // Wait, look at this line:
    // `if(j==1){printf("%de-1",b[j]-'0');}`
    // In C, array indices are 0-based.
    // `b` is filled starting at index 1. `b[0]` is initialized to '0' but unused in logic.
    // `b[1]` holds the first digit after decimal.
    // If `j=1`, `b[1]` is valid.
    
    // What if the input is `0.0`? (Even though spec says significant digits).
    // If `b[1]='0'`, `j=1`.
    // `printf("%de-1", 0)`. Output `0e-1`.
    
    // Let's reconsider the `else` part of `if((i==1)&&(a[1]=='0'))`.
    // `else {   printf("%d.",a[1]-'0');`
    // If `i=0`?
    // If input starts with `.`? e.g. `.5`.
    // While loop: `ch='.'` immediately. Loop doesn't run. `i=0`.
    // `a[1]` is uninitialized (or '0' from init? `a[0]='0'`, `a[1]` is indeterminate if not written).
    // Accessing `a[1]` when `i=0` is accessing uninitialized memory if `a[1]` wasn't explicitly set.
    // But `a[1]` was set to '0' at start? `a[0]='0'; b[0]='0';`. `a[1]` is NOT initialized.
    // If input is `.5`, `i=0`. `a[1]` is garbage.
    // However, spec says "digits before...". So input `0.5` or `5.5`.
    
    // Is there a case where `i` remains 0?
    // Only if the first char is `.`.
    
    // What if the number is `10.5`?
    // `1`->a[1], `0`->a[2]. `.` stops. i=2.
    // `a[1]='1'`.
    // Outer if `(2==1)...` False.
    // Else: `printf("%d.", a[1]-'0')` -> `1.`.
    // Loop `m=2` to `2`. `printf("%d", a[2]-'0')` -> `0`.
    // Loop `m=1` to `j`. `b[1]='5'`. `printf("%d", 5)`.
    // `e1`.
    // `1.05e1`. Correct.

    // There is a subtle bug in `while((ch=getchar())!='.')`.
    // If the input stream ends or fails, `ch` could be EOF (-1).
    // Comparing char to '.' is fine.
    
    // Let's look at the `Reference Program` in the prompt description again.
    // It uses `gets`. The `Source Code` uses `getchar`.
    // The prompt asks to identify errors in the `Source Code` below.
    
    // Is it possible the error is `Runtime Error` due to `printf` format string mismatch?
    // `printf("%de-1",b[j]-'0')`. `b[j]` is char. `b[j]-'0'` is int. `%d` expects int. Correct.
    
    // Wait! Look at the second `while` loop condition:
    // `while((ch=getchar())!='\n')`
    // If the input does not end with `\n` (e.g. EOF), this loop might run indefinitely or read EOF.
    // But problem says "ending with a newline character".
    
    // Let's look at the `if(k!=j)` block again.
    // `for(int m=k+1;m<=j;m++){ printf("%d",b[m]-'0'); }`
    // If `k=1, j=2`. `m=2`. `b[2]` accessed.
    // If `k=1, j=1`. Loop `m=2` to `1`. Doesn't run.
    
    // I suspect the issue might be related to how `a` and `b` are handled if the input is exactly `0.0` or similar, BUT the spec forbids it.
    
    // Let's look at the `else` branch of the MAIN if again.
    // `printf("%d.",a[1]-'0');`
    // If `i=0` (input `.5`), `a[1]` is uninitialized. Reading uninitialized variable is Undefined Behavior, often leading to Runtime Error or garbage output.
    // Although the spec says there are digits before the decimal, robust code should handle or assume valid input. If the test harness sends invalid input, it crashes.
    // HOWEVER, the test case is `0.9`.
    // For `0.9`:
    // `i=1, a[1]='0'`.
    // `j=1, b[1]='9'`.
    // Enters `if((i==1)&&(a[1]=='0'))`.
    // Enters `if(j==1)`.
    // Prints `9e-1`.
    // Returns 0.
    
    // Why would `0.9` cause a Runtime Error in this code?
    // It shouldn't. The logic seems sound for this specific case.
    
    // Is it possible the compiler/environment treats `char` as signed and `getchar` returns negative EOF?
    // `char ch;`
    // `while((ch=getchar())!='.')`
    // If `getchar` returns EOF (-1), and `char` is signed, `ch` becomes -1. `-1 != '.'` is true.
    // Infinite loop?
    // But input is valid.
    
    // Let's look at the `Reference Program` provided in the text block above the source code.
    // The prompt says: "Based on the problem description, the reference program correctly implemented... identify the location of the errors in the program below."
    // The "program below" is the one starting with `#include<stdio.h>` and `char ch;`.
    
    // Maybe the error is simply that `a` and `b` are not null-terminated and if any string function was used... but none are.
    
    // Wait, look at this line in the `else` block of the inner if:
    // `if(k!=j){printf("%d.",b[k]-'0');`
    // `b[k]` is a char digit.
    
    // Let's look at the `Test Case Input: 0.9`.
    // If the code provided IS the buggy code, and it fails with Runtime Error on `0.9`.
    // Could it be that `b[j]` is out of bounds?
    // `b` size 100. `j=1`. Safe.
    
    // Is it possible the `printf` format `%de-1` is interpreted strangely? No.
    
    // Let's look at the `ch=getchar();` between the loops.
    // If the input is `0.9`, the first loop consumes `0`. Stops at `.`.
    // `ch=getchar()` consumes `.`? NO.
    // The `while` condition `(ch=getchar())!='.'` reads the character AND checks it.
    // When it reads `.`, the condition fails, and the loop terminates. The `.` HAS BEEN READ.
    // The next `ch=getchar();` reads the character AFTER the `.`, which is `9`.
    // Then the second `while` loop starts.
    // It reads the NEXT character.
    // If the input is `0.9\n`:
    // 1. `getchar()` reads `0`. `0!='.'`. `a[1]='0'`.
    // 2. `getchar()` reads `.`. `.'!='.'` is False. Loop ends.
    // 3. `ch=getchar()` reads `9`.
    // 4. `while((ch=getchar())!='\n')`:
    //    `getchar()` reads `\n`.
    //    `\n!='\n'` is False. Loop ends.
    //    `j` is NOT incremented. `j` remains 0.
    //    `b` is not filled with `9`. `b[1]` is still `'0'` (from initialization).
    
    // AH! The digit `9` is read into `ch` but NEVER stored in `b` because the second loop reads the NEXT character (`\n`) immediately for its condition check.
    
    // So for `0.9`:
    // `j=0`.
    // `if((i==1)&&(a[1]=='0'))` is True.
    // `if(j==1)` is False (j is 0).
    // Goes to `else`.
    // `k=1`.
    // `while(b[k]=='0')` -> `b[1]` is `'0'` (initialized). `k` becomes 2.
    // `b[2]` is `'0'` (uninitialized/global zero? `b` is local, so uninitialized garbage? Or did `b[0]='0'` only set index 0?).
    // `b` is `char b[100]`. Local array. Uninitialized except `b[0]`.
    // `b[1]` is garbage.
    // If `b[1]` happens to be `'0'`, `k` increments.
    // If `b[1]` is not `'0'`, loop stops. `k=1`.
    // `if(k==j)` -> `1==0` False.
    // `if(k!=j)` -> `1!=0` True.
    // `printf("%d.", b[1]-'0')`. `b[1]` is garbage. Runtime Error (segfault or invalid read) or garbage output.
    
    // The error is that the first digit after the decimal point is read but not stored.
    
    // Line: `ch=getchar();`
    // This line consumes the first digit after the decimal point but does nothing with it.
    // It should store it in `b`.
    
    // Correction:
    // The structure is:
    // `ch=getchar();` // Reads first digit after dot
    // `while((ch=getchar())!='\n'){ ... }` // Reads subsequent digits
    
    // The first digit is lost.
    
    // To fix:
    // Store the result of the intermediate `getchar()` into `b`.
    
    // Location of error:
    // `ch=getchar();` @@ [Logic Error: This reads the first digit after the decimal point but discards it. The subsequent while loop reads the next character (newline or next digit) for its condition, causing the first digit to be lost and j to remain 0 or incorrect, leading to access of uninitialized memory or incorrect logic.]
    
    // Actually, looking at the code structure:
    // `ch=getchar();`
    // `while((ch=getchar())!='\n'){`
    
    // The `ch` read by the standalone `getchar()` is overwritten by the `while` condition's `getchar()`.
    
    // So for `0.9\n`:
    // 1. `ch` gets `9`.
    // 2. `while` condition calls `getchar()`, gets `\n`.
    // 3. Loop doesn't run.
    // 4. `j=0`.
    // 5. `b` is empty/uninitialized.
    
    // This confirms the error.

    else {   printf("%d.",a[1]-'0');
        for(int m=2;m<=i;m++){
        printf("%d",a[m]-'0');
        }

       for(int m=1;m<=j;m++){
       printf("%d",b[m]-'0');

       }

      printf("e%d",i-1);






}








return 0;
}