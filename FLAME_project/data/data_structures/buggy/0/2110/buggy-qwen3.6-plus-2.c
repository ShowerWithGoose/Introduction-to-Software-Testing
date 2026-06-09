#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#define N (int)1e6+1
int main(){
    char str[N];
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='-'){
            if('0'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='9'){ // @@ The condition str[i-1]<=str[i+1] allows expansion when characters are equal or when the range is invalid according to problem statement (should be strictly less than), but more importantly, this block executes for '0'-'9'. However, the logic for checking types is flawed because it doesn't ensure both are digits exclusively before checking order. But the main issue in the test case B-e is that it falls into the else block below. Wait, let's trace B-e. i=1 is '-'. str[0]='B', str[2]='e'.
                // Check 1: '0'<= 'B' ... false.
                // Check 2: 'a'<= 'B' ... false.
                // Check 3: 'A'<= 'B' && 'B' <= 'e' && 'e' <= 'Z'. 'B' <= 'e' is true (ASCII 66 <= 101). 'e' <= 'Z' is false (101 <= 90 is false). So this fails.
                // Else: prints str[i-1], str[i], str[i+1] -> "B-e".
                // Wait, the buggy output is BB-ee. This implies the characters 'B' and 'e' are printed twice?
                // Let's re-read the code logic.
                // If i=0 ('B'), it goes to else -> prints 'B'.
                // If i=1 ('-'), it goes to the big if.
                //   Checks digit: false.
                //   Checks lower: 'a' <= 'B' false.
                //   Checks upper: 'A' <= 'B' (true). 'B' <= 'e' (true). 'e' <= 'Z' (false). So this branch is NOT taken.
                //   Else: prints "B-e".
                // If i=2 ('e'), it goes to else -> prints 'e'.
                // Total output: B + B-e + e = BB-ee.
                // The error is that when '-' is processed, it prints the surrounding characters again in the else block, but those characters were already printed (or will be printed) by their own iterations in the loop.
                // Specifically, str[i-1] was printed when i was i-1. str[i+1] will be printed when i is i+1.
                // The code should only print the expanded sequence or the dash itself, not the neighbors again if they are handled separately.
                // Actually, standard approach: if we expand, we skip printing the neighbors later? Or just print the dash as is if no expansion?
                // The requirement says: "output the expanded string".
                // If no expansion, output input unchanged.
                // The current logic prints each character individually in the `else` at the end of the loop.
                // When `str[i] == '-'`, if it expands, it prints the middle chars. It does NOT print the dash. It does NOT print the neighbors (which is good, because they were/will be printed).
                // BUT, if it does NOT expand, it executes `printf("%c%c%c",str[i-1],str[i],str[i+1]);`.
                // This prints the previous char (already printed at i-1), the dash, and the next char (will be printed at i+1).
                // This causes duplication.
                // Correction: If no expansion, just print the dash `-`. The neighbors are handled by their own loop iterations.
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('a'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='z'){
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else if('A'<=str[i-1]&&str[i-1]<=str[i+1]&&str[i+1]<='Z'){
                for(int j=str[i-1]+1,k=str[i+1];j<k;j++){
                    printf("%c",j);
                }
            }
            else{
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ [Logical Error] This prints the previous character, the dash, and the next character. However, the previous character was already printed in the previous iteration (i-1), and the next character will be printed in the next iteration (i+1). This leads to duplicate output. It should only print the dash character `str[i]` (or just '-') to represent the unexpanded symbol, as the neighbors are handled independently by the loop.]
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}