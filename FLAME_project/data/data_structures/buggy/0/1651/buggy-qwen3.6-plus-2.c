#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1; // @@ [Logic Error: The condition checks if characters are lowercase, but the 'else' adds 1 to 'a' if they are NOT both lowercase. This logic is flawed because 'a' accumulates errors from all three checks. If the first check fails (not lowercase), a becomes 1. If the second check fails (not uppercase), a becomes 2. If the third check fails (not digit), a becomes 3. The final check `if(a!=3 ...)` implies that expansion happens if at least one type matched? No, `a!=3` means it expands if `a` is 0, 1, or 2. This logic is completely broken for determining "same type". For example, if s[i] is 'a' and s[i+2] is 'C', the first check fails (a=1), second check fails (a=2), third check fails (a=3). a==3, so no expansion. Correct. But if s[i] is 'a' and s[i+2] is 'c', first check passes (a=0), second check fails (a=1), third check fails (a=2). a!=3, so it expands. This part accidentally works for valid cases but relies on accidental accumulation. However, the critical error is below.]
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Syntax/Logic Error: The condition `s[i]>='A'&&s[i+2]<='Z'` is missing `s[i]<='Z'` and `s[i+2]>='A'` to properly check uppercase range. Also, the logic of accumulating 'a' is fragile and incorrect for ensuring BOTH characters are of the SAME specific type exclusively.]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [Syntax Error: `s[i]+2>='0'` is incorrect. It should be `s[i]<='9'` and `s[i+2]>='0'`. `s[i]+2` adds 2 to the ASCII value of s[i], which is not a bounds check for the character itself.]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Logic Error: The boundary check `i+2<strlen(s)` should be performed BEFORE accessing `s[i+1]` and `s[i+2]` to prevent out-of-bounds access. Additionally, the logic for `a` is flawed as described above.]
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2; // @@ [Logic Error: The loop prints from s[i] to s[i+2] inclusive. The index `i` is incremented by 2. In the next iteration, `i` will point to the character AFTER s[i+2]. This skips the character at s[i+2] in the main loop's else branch, which is correct because it was already printed. However, the inner loop condition `j<=s[i+2]-s[i]` combined with `put+j` correctly prints the range. The issue in the test case `a-c-g` is that after expanding `a-c` to `abc`, `i` moves to index of `c`'s successor? Let's trace. Input: `a-c-g`. i=0 ('a'). Expands a-c. Prints a, b, c. i becomes 0+2=2. Loop increment makes i=3. s[3] is '-'. Next iteration i=3. s[3]='-'. Checks fail. Prints '-'. i=4. s[4]='c'. Checks s[4]='c', s[5]='-', s[6]='g'. Valid expansion. Prints c, d, e, f, g. i becomes 4+2=6. Loop increment makes i=7. End. Output: abc-defg? No. The reference output is `abcdefg`. The problem says expand `a-d` to `abcd`. It does NOT say to keep the endpoints if they are part of a chain? Wait. The reference program prints `j` from `s[i]` to `<s[i+2]`. It does NOT print `s[i+2]` in the loop. Then it increments `i` by 1. So `s[i+2]` is processed in the next iteration.
            // Let's re-read the reference program carefully.
            // Reference: `for(char j=s[i];j<s[i+2];j++) printf("%c",j); i++;`
            // This prints s[i] up to s[i+2]-1. Then i++ makes i point to s[i+1] (the '-'). Next loop iteration i++ makes i point to s[i+2].
            // So s[i+2] is printed in the next iteration via the `else printf("%c",s[i])` or as start of new expansion.
            // My buggy code: `for(int j=0;j<=s[i+2]-s[i];j++) printf("%c",put+j); i+=2;`
            // This prints s[i] up to s[i+2] INCLUSIVE. Then i+=2. Next loop iteration i++ makes i point to s[i+3].
            // So s[i+2] is NOT processed again. This is actually logically consistent for a single expansion.
            // HOWEVER, the test case `a-c-g` expects `abcdefg`.
            // If I expand `a-c` to `abc`, and then `c-g` to `cdefg`, the result is `abccdefg` if overlapping?
            // No, the input is `a-c-g`.
            // Expansion 1: `a-c` -> `abc`. Remaining string conceptually: `c-g`? No, the input is fixed.
            // The reference program processes `a-c`. Prints `ab`. i points to `-`. Next i points to `c`.
            // Then `c-g` is processed. Prints `cdef`. i points to `-`. Next i points to `g`.
            // Prints `g`. Result: `abcdefg`.
            // My code: Processes `a-c`. Prints `abc`. i jumps to after `c` (index of `-`? No, i+=2 from 0 -> 2. Loop inc -> 3. s[3] is `-`).
            // Wait, `a-c-g`. Indices: 0:a, 1:-, 2:c, 3:-, 4:g.
            // My code i=0. Expands a-c. Prints a,b,c. i+=2 -> i=2. Loop inc -> i=3.
            // i=3 is '-'. Prints '-'.
            // i=4 is 'g'. Prints 'g'.
            // Output: `abc-g`.
            // The expected output is `abcdefg`. This implies chained expansion? Or that the second expansion `c-g` should also happen?
            // In `a-c-g`, `a-c` is expanded. The `c` is at index 2. The next part is `-g`.
            // The reference program: i=0 ('a'). Expands a-c. Prints 'a', 'b'. i++ -> i=1 ('-').
            // Loop inc -> i=2 ('c').
            // i=2 ('c'). Checks s[2]='c', s[3]='-', s[4]='g'. Valid.
            // Expands c-g. Prints 'c', 'd', 'e', 'f'. i++ -> i=3 ('-').
            // Loop inc -> i=4 ('g').
            // i=4 ('g'). Prints 'g'.
            // Total: `abcdefg`.
            // My code fails because it skips the character `c` (s[i+2]) by doing `i+=2` and printing it inside the loop.
            // By printing `c` inside the first expansion, and then jumping over the `-` to `g`? No, i+=2 from 0 lands on 2 ('c'). Loop inc lands on 3 ('-').
            // So `c` is NOT processed as the start of the next expansion.
            // To fix this, we must mimic the reference: do NOT print s[i+2] in the loop, and only advance i by 1 (so the loop increment handles the rest) or adjust indices to allow s[i+2] to be processed as the start of the next potential expansion.
            // Therefore, the error is in the loop bound and the index update.]


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}