#include <stdio.h>

int main() {
    char a[9999];
    scanf("%c", &a[0]);
    if (a[0] == '0') {
        int i = 1, p = 9999;
        while (scanf("%c", &a[i]) != EOF) {
            if (a[i] != '0' && i > 1 && p > i)
                p = i;
            i++;
        }
        if (i - p == 2) { // @@ The condition `i - p == 2` is incorrect for determining if the mantissa is an integer. For input "0.9", `p` becomes 2 (index of '9'), `i` becomes 4 (after reading '\n'). `i - p` is 2. This branch prints "%ce-%d", which outputs "9e-1". However, the logic for detecting trailing zeros or single digit mantissa is flawed in general and specifically here it relies on `i` including the newline. Let's look closer. Input "0.9\n". a[0]='0', a[1]='.', a[2]='9', a[3]='\n'. Loop: i=1, read '.', a[1]='.'. i=2. i=2, read '9', a[2]='9'. p=2. i=3. i=3, read '\n', a[3]='\n'. i=4. Loop ends. i=4, p=2. i-p = 2. Condition holds. Prints "9e-1". This matches expected output for this specific case. Wait, the buggy output provided in the prompt is "9.e-1". Let's re-read the provided Buggy Output. It says `9.e-1`. My analysis of the code suggests it should print `9e-1` if `i-p==2`. Let's re-examine the code logic carefully.
        // Actually, looking at the else branch: `printf("%c.", a[p]);`. If the condition `i - p == 2` fails, it prints with a dot.
        // Why did the prompt say Buggy Output is `9.e-1`?
        // Let's check the loop condition again. `while (scanf("%c", &a[i]) != EOF)`.
        // If input is `0.9`, there might not be a newline if it's not strictly enforced or if EOF comes immediately.
        // But problem says "ending with a newline character".
        // Let's look at the `else` block of the outer `if`.
        // The issue might be in how `p` is initialized or updated.
        // If input is `0.9`, `a[0]='0'`. `i=1`. Read `.`. `a[1]='.'`. `i=2`.
        // Read `9`. `a[2]='9'`. `a[2]!='0'`, `i>1` (2>1), `p>i` (9999>2). `p=2`. `i=3`.
        // Read `\n`. `a[3]='\n'`. `i=4`.
        // Loop ends. `i=4`, `p=2`. `i-p = 2`.
        // So it enters `if (i - p == 2)`. Prints `9e-1`.
        // Why does the prompt claim the output is `9.e-1`?
        // Perhaps the test case input in the prompt description "0.9" implies just those chars? No, "ending with a newline".
        // Maybe the code provided in the "Source Code" section is different from what I'm analyzing? No, it's the same.
        // Let's look at the `else` part of the inner `if` in the `a[0]=='0'` block.
        // `printf("%c.", a[p]);` ... `printf("e-%d", p - 1);`
        // If the condition `i - p == 2` was false, it would print `9.e-1`.
        // When would `i - p == 2` be false?
        // If there are more digits? E.g., `0.09`.
        // `a[0]='0'`. `i=1`. Read `.`. `i=2`.
        // Read `0`. `a[2]='0'`. `a[2]=='0'`, so `p` stays 9999. `i=3`.
        // Read `9`. `a[3]='9'`. `a[3]!='0'`, `i>1`, `p>i` (9999>3). `p=3`. `i=4`.
        // Read `\n`. `i=5`.
        // `i=5, p=3`. `i-p = 2`. Still true. Prints `9e-2`. Correct.
        // What if `0.90`? Problem says "no trailing zeros".
        
        // Let's look at the other branch: `else` (when a[0] != '0').
        // Input `1.23`.
        // `a[0]='1'`. `i=1`. Read `.`. `k=1`. `i=2`.
        // Read `2`. `i=3`.
        // Read `3`. `i=4`.
        // Read `\n`. `i=5`.
        // `m=5`. `k=1`.
        // `printf("%c", a[0])` -> `1`.
        // `i > 2` (5>2) -> `printf(".")` -> `1.`.
        // Loop `j=1` to `j < 3` (i-2 = 3).
        // `j=1`. `a[1]='.'`. `j==k` (1==1). Continue.
        // `j=2`. `a[2]='2'`. `j!=k`. Print `2`. -> `1.2`.
        // Loop ends.
        // `k!=0`. Print `e%d`, `k-1` = 0. -> `1.2e0`. Correct.
        
        // Back to `0.9`.
        // Is it possible `scanf` behaves differently?
        // If the input buffer contains `0.9\n`, `scanf` reads char by char.
        
        // Let's look closely at the line: `if (i - p == 2)`.
        // If the input is `0.9` without newline? The problem states there IS a newline.
        
        // Wait, look at this line:
        // `if (a[i] != '0' && i > 1 && p > i)`
        // For `0.9`:
        // i=1, char='.'. a[1]!='0' is true. i>1 is false. Skip.
        // i=2, char='9'. a[2]!='0' is true. i>1 is true. p(9999)>2 is true. p=2.
        // i=3, char='\n'. a[3]!='0' is true. i>1 is true. p(2)>3 is false. Skip.
        // i=4. Loop ends.
        // i=4, p=2. i-p=2.
        
        // There must be an error in my simulation or the code has a subtle bug.
        // Let's check the `else` branch of the `if (a[0] == '0')` block again.
        // The prompt says the output IS `9.e-1`. This implies the code went into the `else` branch of `if (i - p == 2)`.
        // This means `i - p != 2`.
        // How can `i - p != 2` for `0.9`?
        // Only if `i` is different or `p` is different.
        // If `p` remained 9999? No, it found '9'.
        // If `i` is larger?
        
        // Ah! Look at the variable `p` initialization: `int i = 1, p = 9999;`.
        // And the update: `p = i;`.
        
        // Is it possible the newline is not read?
        // If `scanf` returns EOF before reading newline? No, standard input usually buffers line.
        
        // Let's look at the `else` block for non-zero start.
        // `if (k == 0) { while (a[i - 2] == '0') { i--; } }`
        // This handles integers like `1200`.
        
        // Let's reconsider the `0.9` case.
        // What if the code provided in the prompt is NOT the code that produced `9.e-1`?
        // The prompt asks to identify errors in the program BELOW.
        // The program below IS the source code.
        // The "Buggy Output" is what THIS program produces.
        // If my simulation says it produces `9e-1`, but the prompt says `9.e-1`, then either:
        // 1. My simulation is wrong.
        // 2. The prompt's "Buggy Output" description is based on a slightly different version or environment.
        // 3. There is a hidden character or behavior.
        
        // Let's look at this condition: `if (i - p == 2)`.
        // If the input was `0.90` (violating constraints), p=2, i=5. i-p=3. Else branch. `9.0e-1`.
        
        // Let's look at the `else` branch logic:
        // `printf("%c.", a[p]);` -> Prints `9.`
        // `for (int j = p + 1; j < i - 1; j++)` -> j=3. i-1=3. Loop doesn't run.
        // `printf("e-%d", p - 1);` -> `e-1`.
        // Result: `9.e-1`.
        
        // So, for the output to be `9.e-1`, the code MUST have entered the `else` branch.
        // This implies `i - p != 2`.
        // Since `p=2`, `i` must not be 4.
        // If `i=3`? That would mean the loop ran only twice?
        // i=1 (read '.'), i=2 (read '9'). If EOF here?
        // If input is just `0.9` without newline?
        // Then `scanf` at i=2 reads '9'. Returns 1.
        // Next `scanf` at i=3 waits or returns EOF?
        // If it returns EOF, loop terminates.
        // i=3. p=2.
        // i - p = 1.
        // 1 != 2. Enters else.
        // Prints `9.e-1`.
        
        // BUT the problem states: "Input Format: ... ending with a newline character."
        // So there SHOULD be a newline.
        
        // However, often in these problems, if the last scanf fails to read the newline because of how EOF is handled in some judges, or if the newline is consumed differently...
        
        // Actually, there is a known issue with `scanf("%c")` and newlines.
        // If the input is `0.9\n`, `scanf` reads `0`, `.`, `9`, `\n`.
        
        // Let's look at the reference program. It uses `while ((scanf("%c", &a[i])) != EOF)`.
        // It processes until EOF.
        
        // If the judge provides `0.9\n`, `i` becomes 4.
        
        // Is there any other path?
        // What if `p` is not updated?
        // `if (a[i] != '0' && i > 1 && p > i)`
        // If `a[i]` is `.`? `.` != `0`. `i=1`. `i>1` is false.
        // If `a[i]` is `9`? `9` != `0`. `i=2`. `i>1` true. `p=2`.
        
        // There is a logical flaw in `i - p == 2`.
        // `p` is the index of the first significant digit.
        // `i` is the index AFTER the last read character.
        // The characters after `p` are `a[p+1] ... a[i-2]` (assuming `a[i-1]` is `\n`).
        // Number of digits after `p` = `(i - 2) - (p + 1) + 1` = `i - p - 2`.
        // If there are NO digits after `p` (i.e., `0.9`), then `i - p - 2 = 0` => `i - p = 2`.
        // So `i - p == 2` correctly identifies that there are no digits after the significant digit `9` before the newline.
        // So it SHOULD print `9e-1`.
        
        // Why does the prompt say it outputs `9.e-1`?
        // Maybe the input DOES NOT have a newline?
        // Or maybe `scanf` fails to read the newline?
        
        // Regardless of why the buggy output is what it is, the GOAL is to fix the code to produce `9e-1` for `0.9`.
        // The current code produces `9e-1` IF `i-p==2`.
        // If the environment causes `i` to be different, it fails.
        
        // A more robust check for "is there any non-zero digit after p?" or "is p the last digit?"
        // Actually, the condition `i - p == 2` assumes exactly one character (newline) after the digit at `p`.
        // If the input is `0.9\n`, `a[2]='9'`, `a[3]='\n'`. `i=4`. `p=2`. `4-2=2`. Correct.
        
        // Let's assume the provided "Buggy Output" is correct and my simulation missed something.
        // Could `p` be 1? No, `i>1`.
        // Could `p` be 3? No.
        
        // Let's look at the `else` branch again.
        // `printf("%c.", a[p]);`
        // This always prints a dot.
        // The requirement: "If it’s an integer, it contains only one significant digit without a decimal point."
        // `0.9` -> `9e-1`. Base is `9` (integer).
        // `0.09` -> `9e-2`. Base is `9` (integer).
        // `0.12` -> `1.2e-1`. Base is `1.2` (decimal).
        
        // The logic `if (i - p == 2)` attempts to detect if the base is an integer (single digit).
        // It works for `0.9` if `i=4, p=2`.
        
        // If the code is failing, it's likely because `i - p == 2` is FALSE in the failing environment.
        // Why? Maybe trailing whitespace?
        
        // To fix this robustly:
        // We should check if there are any significant digits AFTER `p`.
        // In the `0.9` case, `p=2`. The next char is `\n`.
        // In `0.12`, `p=2` ('1'). Next char `a[3]='2'`.
        
        // Instead of relying on `i` (which depends on newline presence), we can check `a[p+1]`.
        // If `a[p+1]` is `\n` or `\0` or EOF, then it's a single digit.
        
        // Let's modify the condition.
        // Replace `if (i - p == 2)` with a check on the content.
        
        // Also, look at the `else` part of the main `if` (non-zero start).
        // `if (i > 2) { printf("."); }`
        // For `9` (input `9\n`? No, input has decimal point).
        // Input `9.0`? No, "digits before and after".
        // Input `9.1`.
        // `a[0]='9'`. `k=1` ('.'). `i` goes to 4 (`\n`).
        // `printf("9")`. `i>2` true. `printf(".")`.
        // Loop `j=1` to `2`.
        // `j=1` ('.'). Skip.
        // `j=2` ('1'). Print `1`.
        // `e0`.
        // `9.1e0`. Correct.
        
        // What about `9.0`? Problem says "all digits are significant... no trailing zeros". So `9.0` won't appear.
        
        // Back to `0.9`.
        // The error is likely that the condition `i - p == 2` is fragile.
        // If we change it to check if `p` is the last digit before newline.
        
        // Let's annotate the line with the fragile condition.
        
        // Another potential error:
        // `printf("%ce-%d", a[p], p - 1);`
        // For `0.9`, `p=2`. `a[2]='9'`. `p-1 = 1`. `9e-1`.
        
        // If the code entered the else branch:
        // `printf("%c.", a[p]);` -> `9.`
        // `for (int j = p + 1; j < i - 1; j++)`
        // If `i=4, p=2`. `j=3`. `j < 3` is false. Loop doesn't run.
        // `printf("e-%d", p - 1);` -> `e-1`.
        // Output `9.e-1`.
        
        // So the bug is definitely that the code enters the else branch when it shouldn't, OR the condition is wrong.
        // Given the prompt says the output IS `9.e-1`, the code IS entering the else branch.
        // This implies `i - p != 2`.
        
        // To fix: Change the condition to be more robust.
        // Check if `a[p+1]` is a newline or end of string.
        
        // Line to annotate:
        // `if (i - p == 2) {`
        
        // Reason: The condition `i - p == 2` relies on `i` being exactly `p + 2`, which assumes a specific reading behavior (specifically that the newline is read and counted in `i`). If the input handling varies (e.g., no newline, or extra whitespace), this fails. A better check is whether the character immediately following the significant digit `a[p]` is a newline or null terminator, indicating no further significant digits.
        
        // However, I must output the annotated code.
        
        // One more thing: The `else` branch prints a dot unconditionally.
        // `printf("%c.", a[p]);`
        // This is wrong if the base is an integer.
        
        // So the fix is to ensure the `if` branch is taken for single-digit bases.
        
        // Annotated line:
        //         if (i - p == 2) { // @@ [The condition `i - p == 2` is fragile and depends on `i` including the newline character. If the input format or `scanf` behavior results in `i` not being exactly `p + 2` (e.g., missing newline or extra characters), it incorrectly falls through to the `else` block which always prints a decimal point, producing `9.e-1` instead of `9e-1`. A more robust check would verify if `a[p+1]` is a newline or null terminator.]
        
        // Wait, I should check if there are other errors.
        // In the `else` block (non-zero start):
        // `if (k == 0) { while (a[i - 2] == '0') { i--; } }`
        // This trims trailing zeros for integers?
        // If input `100.`? No, "digits before and after".
        
        // The primary error causing the reported failure is the condition.
        
        // Final check on annotations format.
        // Add @@ symbol directly after that line and explain.
        
        // Line 13: `if (i - p == 2) {`
        
        // Let's verify the line number in the provided source.
        // 1: #include
        // 2: 
        // 3: int main() {
        // 4:     char a[9999];
        // 5:     scanf("%c", &a[0]);
        // 6:     if (a[0] == '0') {
        // 7:         int i = 1, p = 9999;
        // 8:         while (scanf("%c", &a[i]) != EOF) {
        // 9:             if (a[i] != '0' && i > 1 && p > i)
        // 10:                p = i;
        // 11:            i++;
        // 12:        }
        // 13:        if (i - p == 2) {
        
        // Yes.