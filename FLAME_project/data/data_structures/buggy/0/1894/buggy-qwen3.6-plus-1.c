#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s);
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ The original code uses independent 'if' statements. If the first 'if' (digits) fails, it falls through. However, the logic for printing the current character '-' or handling non-expansion cases is flawed in the original structure because the 'else' at the end only applies to the outer 'if'. More critically, if none of the expansion conditions are met (like B-e where types differ), the code falls through to the end of the loop iteration without printing anything for the '-' or the surrounding characters correctly in all paths, or it prints them via the final else. Let's look closer.
        // The main issue is that if an expansion condition is NOT met, the code does nothing inside the `if(s[i]=='-')` block, and then proceeds to the next iteration? No, the `else` belongs to `if(s[i]=='-')`.
        // Wait, the structure is:
        // if (is dash) {
        //    if (digit range) { expand }
        //    if (lower range) { expand }
        //    if (upper range) { expand }
        // }
        // else { print char }
        //
        // If input is "B-e":
        // i=0 ('B'): not dash -> else -> prints 'B'.
        // i=1 ('-'): is dash.
        //   Check digit: 'B' is not >= '0' && <= '9' (well, 'B' > '9' is false? 'B' is 66, '9' is 57. So 'B'<='9' is false). Condition fails.
        //   Check lower: 'B' is not >= 'a'. Condition fails.
        //   Check upper: 'B' >= 'A' and 'e' <= 'Z'? 'e' is 101, 'Z' is 90. 'e' <= 'Z' is false. Condition fails.
        //   So inside the `if(s[i]=='-')` block, nothing happens. No output is generated for the '-' or the subsequent character 'e' in this iteration.
        // i=2 ('e'): not dash -> else -> prints 'e'.
        // Output: "Be". Expected: "B-e".
        // The error is that when the dash is found but expansion conditions are NOT met, the dash itself and potentially other characters need to be handled. Currently, the dash is skipped entirely (not printed), and the logic relies on the `else` branch to print non-dash characters. But the dash IS a character that should be printed if not expanded.
        // To fix this, if expansion doesn't happen, we must print the previous character (which was already printed in the previous iteration? No, wait.)
        
        // Let's re-trace "a-c".
        // i=0 ('a'): else -> prints 'a'.
        // i=1 ('-'): is dash.
        //   Digit check fail.
        //   Lower check: 'a'>='a', 'c'<='z', 'a'<'c'. True.
        //   k = 'c'-'a' = 2.
        //   Loop j=1 to <2. j=1. Prints 'a'+1 = 'b'.
        //   End of dash block.
        // i=2 ('c'): else -> prints 'c'.
        // Output: "abc". Correct.
        
        // Now "B-e".
        // i=0 ('B'): else -> prints 'B'.
        // i=1 ('-'): is dash.
        //   Checks fail. Nothing printed.
        // i=2 ('e'): else -> prints 'e'.
        // Output: "Be". Missing '-'.
        
        // So the error is that when the expansion conditions are not met, the '-' character is not printed.
        // We need an else clause to the inner checks or a flag to indicate if expansion happened. If not, print '-'.
        // However, simply adding `else printf("-");` after the three ifs might work, but we must ensure we don't double print.
        // Actually, the standard way to handle this "lookahead" or "contextual" replacement is often to handle the printing of the current char carefully.
        // A simpler fix for the specific bug "Wrong Answer" on "B-e" is to ensure that if no expansion occurs, the '-' is printed.
        
        // Let's look at the structure again.
        // if (dash) {
        //    if (valid expand 1) { ... }
        //    if (valid expand 2) { ... }
        //    if (valid expand 3) { ... }
        //    // If none executed, we need to print '-'
        // } else {
        //    print s[i]
        // }
        
        // So we need to add an else block or a flag.
        // Since I can only annotate lines, I will identify the logical gap.
        // The lines with the `if` checks for expansion are logically incomplete because they don't handle the negative case (no expansion).
        
        // However, looking at the provided solution format, I need to mark the line where the error *is*.
        // The error is effectively that the code *doesn't* print the dash when expansion fails.
        // This is a missing logic block.
        // Is there a line that is *wrong*?
        // The `else` at the end `else{printf("%c",s[i]);}` handles non-dash chars.
        // The dash char is handled by the `if(s[i]=='-')` block. If that block does nothing, the dash is lost.
        
        // I will mark the last `if` condition line as the place where the logic flow fails to account for the "else" case of "no expansion".
        // Or perhaps I should mark the closing brace of the dash block?
        
        // Let's look at the instructions: "If you think an error may occur on a particular line, add @@ symbol directly after that line and explain the reason for the error."
        
        // The most precise explanation is that the conditional blocks for expansion do not have an `else` to print the '-' when expansion is invalid.
        
        // I will annotate the line with the third `if` statement, noting that if this and previous checks fail, the '-' is not printed.
        
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
    }
    else{printf("%c",s[i]);
    }    
}
return 0;
}