#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char s[200]={0},tmp;
    gets(s);
    int i,num=-1,sum=0,flag=1,j;
    for(i=0;s[i];i++){
        if(s[i]=='.'){
            if(sum==1&&s[i-1]!=0){ // @@ [Logic error: The condition `s[i-1]!=0` checks against the ASCII value 0 (null terminator), not the character '0'. It should be `s[i-1] != '0'`. Also, this branch handles numbers like "5.0" or single digit integers incorrectly based on the problem description which implies standard scientific notation conversion.]
                printf("%se0",s); // @@ [Output format error: This prints the original string followed by e0, which is not scientific notation. For input "0.9", this branch is skipped, but for valid inputs like "5.2", it produces wrong output.]
                break;
            }else if(sum>1){
                for(j=0;s[j];j++){
                    if(j==1){
                        printf(".%c",s[j]); // @@ [Logic error: This logic for reconstructing the number is flawed. It assumes the first digit is at index 0 and inserts a dot after it, but the loop structure and conditions are confusing and likely incorrect for general cases.]
                    }else if(s[j]=='.'){
                        continue;
                    }else{
                        printf("%c",s[j]);
                    }
                }
                printf("e%d",num);
            }else {
                for(j=i;s[i];j++){ // @@ [Infinite loop/Logic error: The loop condition `s[i]` depends on `i`, but `i` is not incremented inside this inner loop. It should likely be `s[j]`. Also, `j` starts at `i` (the position of '.'), so `s[j+1]` is the first digit after decimal.]
                    if(s[j+1]!='0'&&s[j+2]!=NULL){ // @@ [Logic error: `s[j+2]!=NULL` compares a char to a pointer NULL. It should check for null terminator `\0`. More importantly, this logic tries to find the first non-zero digit but fails to correctly strip trailing zeros or handle the case where the significant digit is the last one properly for the "integer" base case.]
                            printf("%c.%se-%d",s[j+1],&s[j+2],flag); // @@ [Format error: `%s` expects a string, passing `&s[j+2]` prints the rest of the string. This does not remove trailing zeros as required by "no trailing zeros after the decimal point". For "0.9", `s[j+1]` is '9', `s[j+2]` is '\0'. It prints "9.e-1" or similar depending on memory, but definitely not "9e-1".]
                            break;
                    }else if(s[j+1]!='0'){ // @@ [Logic error: This condition handles the case where the next digit is non-zero but the one after is null (end of string). However, the previous `if` already caught non-zero followed by something. This branch is for single significant digit after decimal? But it prints `%ce-%d`, which is correct for "9e-1" IF flag is correct. Let's trace "0.9". `i`=1. `sum`=1. Enters `else`. `j`=1. `s[2]` is '\0'. `s[2]!=NULL` is false (assuming NULL is 0). So it goes to `else if`. `s[2]` is '\0' which is 0. So `s[j+1]!='0'` is `s[2]!='0'` -> `0!=48` true. Prints `s[2]` which is `\0`? No, `j=1`, `s[j+1]` is `s[2]` which is `\0`. Wait. `j=i=1`. `s[1]` is '.'. `s[2]` is '9'. `s[3]` is '\0'.
                        // Trace again: Input "0.9". `s[0]='0'`, `s[1]='.'`, `s[2]='9'`, `s[3]='\0'`.
                        // Loop `i=0`: `s[0]!='.'`. `sum=1`, `num=0`.
                        // Loop `i=1`: `s[1]=='.'`. `sum==1`. `s[0]!='0'` is false ('0'=='0'). So enters `else`.
                        // `j=i=1`. Condition `s[i]` i.e., `s[1]` is '.' (true).
                        // `if(s[2]!='0' && s[3]!=NULL)`. `s[2]` is '9' (!='0' true). `s[3]` is '\0' (0). `NULL` is 0. So `0!=0` is false. Condition false.
                        // `else if(s[2]!='0')`. `s[2]` is '9'. True.
                        // `printf("%ce-%d", s[2], flag)`. `s[2]` is '9'. `flag` is 1. Output: "9e-1".
                        // This actually seems correct for this specific case? Why did it fail?
                        // Ah, look at the first `if` in the `else` block: `if(s[j+1]!='0'&&s[j+2]!=NULL)`.
                        // If input was "0.09", `j=1`. `s[2]='0'`. First if false. Second if `s[2]!='0'` false. `flag++` becomes 2. `j` doesn't increment? No, `j` is not incremented in the loop body explicitly, nor in the `for` update because the `for` loop syntax is `for(j=i;s[i];j++)`. Wait, the `for` loop increments `j`.
                        // But the condition is `s[i]`. `i` is static. Infinite loop if `s[i]` is not null.
                        // In "0.9", `s[1]` is '.', not null. So it enters.
                        // Inside, it breaks. So it exits.
                        // So why Wrong Answer?
                        // Let's look at `printf("%c.%se-%d",s[j+1],&s[j+2],flag);`.
                        // If input is "0.12". `j=1`. `s[2]='1'`, `s[3]='2'`, `s[4]='\0'`.
                        // `s[2]!='0'` true. `s[3]!=NULL` ('2'!=0) true.
                        // Prints `s[2]` ('1'), then string starting at `s[3]` ("2"), then `-1`.
                        // Output: "1.2e-1". Correct.
                        // What if input is "0.10"? Problem says no trailing zeros.
                        // What if input is "1.0"? `sum=2`. Enters `else if(sum>1)`.
                        // The code is very fragile.
                        // The main issue identified in typical student errors here is often the handling of the exponent sign or the base formatting.
                        // However, looking closely at the provided Buggy Output for "0.9": `0.9e0`.
                        // My trace suggested it should output `9e-1`.
                        // Why did it output `0.9e0`?
                        // Maybe the `if(sum==1&&s[i-1]!=0)` evaluated to true?
                        // `s[i-1]` is `s[0]` which is '0' (ASCII 48). `0` (integer) is 0.
                        // `48 != 0` is TRUE.
                        // So it enters the first branch!
                        // `printf("%se0", s)` prints "0.9e0".
                        // Yes! The error is `s[i-1]!=0` should be `s[i-1]!='0'`.
                        // Because '0' (char) is 48, which is not equal to 0 (int).
                        // So it thinks "0.9" has a non-zero digit before decimal? No, it checks if it's NOT zero.
                        // The condition `s[i-1]!=0` is intended to check if the digit is not '0'.
                        // But it compares with integer 0 (null), not character '0'.
                        // So '0' != 0 is true. It treats "0.9" as a number >= 1 or single non-zero digit?
                        // The logic `if(sum==1 && s[i-1]!='0')` is meant for numbers like "5.2" -> "5.2e0"? No, "5.2" should be "5.2e0" only if we don't normalize? No, scientific notation for 5.2 is 5.2e0.
                        // But for "0.9", it enters this block because '0' != 0 is true.
                        // So it prints "0.9e0".
                        // This confirms the error location.
                    }
                    flag++;
                }
                break;
            }
        }
        sum++;
        num++;
    }

    return 0;
}