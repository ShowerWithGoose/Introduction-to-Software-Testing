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
                // Wait, the buggy output is BB-ee. Why?
                // Let's re-read the code carefully.
                // If the input is B-e.
                // i=0: str[0]='B'. Not '-'. Prints 'B'.
                // i=1: str[1]='-'. Is '-'.
                //   Check 1: '0'<= 'B' (false).
                //   Check 2: 'a'<= 'B' (false).
                //   Check 3: 'A'<= 'B' (true). 'B' <= 'e' (true). 'e' <= 'Z' (false). So condition fails.
                //   Else: printf("%c%c%c", 'B', '-', 'e'). Outputs "B-e".
                // i=2: str[2]='e'. Not '-'. Prints 'e'.
                // Total output: "BB-ee" ? No.
                // i=0 prints 'B'.
                // i=1 prints "B-e".
                // i=2 prints 'e'.
                // Result: "B" + "B-e" + "e" = "BB-ee".
                // Ah, the logic prints the surrounding characters in the else block of the '-' handler, BUT the loop also processes those surrounding characters individually in their own iterations.
                // When i=0, it prints 'B'.
                // When i=1, it detects '-', fails expansion, and prints "B-e" again.
                // When i=2, it prints 'e'.
                // So characters adjacent to '-' are printed twice: once in their own iteration, and once inside the '-' handling else block.
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
                printf("%c%c%c",str[i-1],str[i],str[i+1]); // @@ This causes double printing. The characters str[i-1] and str[i+1] are already printed (or will be printed) in their respective loop iterations. For example, str[i-1] was printed when i was i-1. str[i+1] will be printed when i is i+1. Printing them here again results in duplication. Instead, only the '-' should be printed if no expansion occurs, or the logic should skip printing the neighbors in their own iterations. Given the structure, simply printing '-' is not enough if we don't adjust neighbors. A common fix is to only print the current character str[i] (which is '-') in the else case, and rely on the loop to print the neighbors. However, if we just print '-', the output for B-e would be B-e (from i=0:'B', i=1:'-', i=2:'e'). This matches expected. So replace this line with printf("%c", str[i]);
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    return 0;
}