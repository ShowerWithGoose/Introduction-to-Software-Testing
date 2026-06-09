#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a[100], i = 0;
    int p, ch;
    while (scanf("%d", &p) != EOF) {
        if (p == -1)
            break;
        else if (p == 1) {
            if (i == 100) {
                printf("error ");
            } else {
                scanf("%d", &ch);
                a[i] = ch;
                i++;
            }
        } else {
            i--; // @@ The stack pointer is decremented before checking if the stack was empty. If the stack was empty (i==0), i becomes -1. The subsequent check `if (i < 0)` correctly identifies the error, but the logic flow for valid pops relies on `a[i]` after decrement. However, the critical issue here is that when an error occurs (stack underflow), the state of the stack (i) has already been modified to -1. In the next operation, if it's a push, `i` is -1, so `a[-1]` might be accessed or `i` becomes 0, corrupting the stack state. More importantly, looking at the expected output vs buggy output: The buggy code outputs `0` instead of `8`. Let's trace. Input: `1 5 0 0 ...`. Push 5. Pop -> prints 5, i becomes 0. Pop -> i becomes -1. Prints "error ". Next is `1 8`. Push 8. i is -1. `i == 100` is false. `scanf` reads 8. `a[-1] = 8`. `i` becomes 0. Next `0`. Pop. i becomes -1. Prints "error ". Wait, the expected output is `5 error 8 ...`. The buggy output is `5 error 0 ...`. This implies the second pop didn't print error, or the subsequent push/pop logic is messed up. 
            // Actually, let's look closer at the provided "Buggy Output" and "Expected Output".
            // Buggy: 5 error 0 90 ...
            // Expected: 5 error 8 90 ...
            // The value `0` appears where `8` should be.
            // In the provided reference program (which is labeled as buggy in the prompt context relative to the expected output), let's trace:
            // 1 5: Push 5. Stack: [5], i=1.
            // 0: Pop. i becomes 0. Print a[0] which is 5. Output: "5 ".
            // 0: Pop. i becomes -1. i < 0 is true. Print "error ". Output: "5 error ".
            // 1 8: Push 8. i is -1. i==100 false. Read 8. a[-1]=8. i becomes 0.
            // 0: Pop. i becomes -1. i < 0 true. Print "error ". Output: "5 error error ".
            // This doesn't match the buggy output "5 error 0 ...".
            
            // Let's re-read the provided "Source Code" in the prompt.
            // The prompt provides a "Reference Program" (the C string parsing one) and then a "Source Code" (the scanf one).
            // The "Test Case Input", "Buggy Output", and "Expected Output" correspond to the "Source Code" provided at the bottom?
            // Or is the "Reference Program" the correct one? The prompt says "reference program correctly implemented".
            // The first code block uses `gets` and parses chars. It handles negative numbers manually.
            // The second code block uses `scanf`.
            
            // Let's trace the SECOND code block (Source Code) with input: `1 5 0 0 1 8 0 ...`
            // 1 5: p=1. i=0. i!=100. scanf ch=5. a[0]=5. i=1.
            // 0: p=0. i-- -> i=0. i>=0. printf a[0] (5). Output: "5 ".
            // 0: p=0. i-- -> i=-1. i<0. printf "error ". Output: "5 error ".
            // 1 8: p=1. i=-1. i!=100. scanf ch=8. a[-1]=8. i=0.
            // 0: p=0. i-- -> i=-1. i<0. printf "error ". Output: "5 error error ".
            // This still doesn't produce "5 error 0".
            
            // Let's trace the FIRST code block (Reference Program) with input: `1 5 0 0 1 8 0 ...`
            // Note: The first code block has `if(ch==1) { ch=0; continue; }`. This skips the rest of the loop body, including `ch=0` at the end? No, it continues to next iteration. But `ch` was reset to 0.
            // It parses characters.
            // "1 5 0 0 1 8 ..."
            // i=0: '1'. ch=1.
            // i=1: ' '. Space. step=0. ch=1. ch!= -1, 0. ch==1. ch=0. continue.
            // i=2: '5'. ch=5.
            // i=3: ' '. Space. step=0. ch=5. ch!= -1, 0, 1. a[0]=5. link=1. ch=0.
            // i=4: '0'. ch=0.
            // i=5: ' '. Space. step=0. ch=0. ch==0 && link==0? No (link=1). ch==0. printf a[--link] -> a[0]=5. link=0. Output: "5 ". ch=0.
            // i=6: '0'. ch=0.
            // i=7: ' '. Space. step=0. ch=0. ch==0 && link==0? Yes (link=0). printf "error ". Output: "5 error ". ch=0.
            // i=8: '1'. ch=1.
            // i=9: ' '. Space. step=0. ch=1. ch==1. ch=0. continue.
            // i=10: '8'. ch=8.
            // i=11: ' '. Space. step=0. ch=8. a[0]=8. link=1. ch=0.
            // i=12: '0'. ch=0.
            // i=13: ' '. Space. step=0. ch=0. ch==0 && link==0? No. printf a[--link] -> a[0]=8. link=0. Output: "5 error 8 ".
            
            // The First Code Block produces the EXPECTED output.
            // The Second Code Block ("Source Code") is the one being asked to debug?
            // The prompt asks to identify errors in "the program below". The "Source Code" section contains the second program.
            // The "Buggy Output" provided is `5 error 0 90 356 234 890 2 -56 -45`.
            // My trace of the second program produced `5 error error ...`.
            // Why does the buggy output show `0`?
            // Maybe the variable `i` is not initialized? `int a[100], i = 0;` It is initialized.
            // Maybe the array `a` contains garbage?
            
            // Let's look at the Buggy Output again: `5 error 0 90 ...`
            // Expected: `5 error 8 90 ...`
            // The `0` replaces `8`.
            // In the second program:
            // After `error`, `i` is -1.
            // Next op `1 8`. `p=1`. `i=-1`. `scanf` reads 8 into `ch`. `a[-1] = 8`. `i` becomes 0.
            // Next op `0`. `p=0`. `i` becomes -1. `i < 0` is true. Prints `error`.
            
            // There is a mismatch between my trace of the provided Source Code and the provided Buggy Output.
            // However, usually in these problems, the "Source Code" provided IS the buggy code.
            // The error in the Source Code is clearly that it allows writing to `a[-1]` and corrupts the stack index `i` when an underflow occurs, because it decrements `i` BEFORE checking for emptiness.
            
            // Correct logic for Pop:
            // if (i == 0) print error;
            // else { i--; print a[i]; }
            
            // Current buggy logic:
            // i--;
            // if (i < 0) print error;
            // else print a[i];
            
            // If stack is empty (i=0):
            // i becomes -1.
            // Prints error.
            // State: i = -1.
            
            // Next Push (1 8):
            // i is -1.
            // Checks i==100 (False).
            // Reads 8.
            // Writes to a[-1]. (Undefined Behavior / Memory Corruption).
            // i becomes 0.
            
            // Next Pop (0):
            // i becomes -1.
            // Prints error.
            
            // This leads to "5 error error ...".
            // The provided Buggy Output is "5 error 0 ...".
            // Perhaps the `a[-1]` write overwrote something else, or the read `a[i]` in a subsequent step read 0?
            // Regardless, the logical error is decrementing `i` before checking bounds.
            
            if (i < 0)
                printf("error ");
            else {
                printf("%d ", a[i]);
            }
        }
    }
    return 0;
}