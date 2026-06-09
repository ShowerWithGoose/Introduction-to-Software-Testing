#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];

int main()
{
    scanf("%s",&s);

    for(int i=0;i<strlen(s);i++){
        int a=0;
        if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z')a+=0;else a+=1; // @@ [Logic Error: The condition checks if characters are lowercase, but the 'else' increments 'a' even if they are not. This logic is flawed because 'a' accumulates errors from all three checks. More importantly, it fails to check if s[i+1] is '-' before accessing s[i+2], leading to potential out-of-bounds access or incorrect logic flow. However, the critical logical error here is that the type checking logic is mutually exclusive in intent but additive in execution. If s[i] is 'a', the first if is true (a+=0). The second if (uppercase) is false (a+=1). The third if (digit) is false (a+=1). So a becomes 2. The condition `a!=3` will be true. But if s[i] is 'A', first if false (a+=1), second if true (a+=0), third if false (a+=1). a=2. If s[i] is '0', first if false (a+=1), second if false (a+=1), third if... wait. The third condition has a typo `s[i]+2>='0'` instead of `s[i+2]>='0'`. Let's look at the third if closely.]
        if(s[i]>='A'&&s[i+2]<='Z'&&s[i]>='A'&&s[i+2]<='Z')a+=0;else a+=1; // @@ [Logic Error: Same as above. The logic for determining if the types match is incorrect. It should check if BOTH start and end are of the SAME specific type. The current structure adds 1 to 'a' for every type mismatch. Since a character can only be one type, two of these checks will always fail, making 'a' at least 2. If the character is valid, one check passes (a+=0), so a=2. If invalid, all might fail or mix. The condition `a!=3` implies that if all 3 checks fail, a=3, and we don't expand. But if one passes, a=2, and we might expand. This part is technically "working" by accident for valid types if the third bug wasn't there, but it's very fragile. The real issue is the next line.]
        if(s[i]>='0'&&s[i+2]<='9'&&s[i]+2>='0'&&s[i+2]<='9')a+=0;else a+=1; // @@ [Syntax/Logic Error: `s[i]+2>='0'` is incorrect. It should be `s[i]>='0'` (checking the start char) and `s[i+2]<='9'` (checking the end char). The expression `s[i]+2` adds 2 to the ASCII value of s[i], which is not the intended check for the character at index i. It should be `s[i]>='0' && s[i]<='9' && s[i+2]>='0' && s[i+2]<='9'`. Also, like the previous lines, it doesn't check if s[i+1] is '-'.]
        if(a!=3&&s[i+1]=='-'&&s[i+2]>s[i]&&i+2<strlen(s)){ // @@ [Logic Error: The boundary check `i+2<strlen(s)` should be performed BEFORE accessing `s[i+1]` and `s[i+2]` to prevent out-of-bounds memory access. Additionally, the variable `a` logic is flawed as described above. For the input `a-c-g`, when i=0 ('a'), s[1]='-', s[2]='c'. Types match. a=2. Condition holds. Expands a-c to abc. i becomes 2 (i+=2 inside loop body? No, i+=2 is inside the if block, then the for loop does i++. So i goes 0 -> 2 -> 3. At i=3, s[3]='-'. s[4]='g'. s[5] is out of bounds or next char. Wait, input is `a-c-g0-A`. Indices: 0:a, 1:-, 2:c, 3:-, 4:g, 5:0, 6:-, 7:A.
            // When i=0: expands a-c. Prints abc. i+=2 makes i=2. Loop increment makes i=3.
            // When i=3: s[3]='-'. It is not a letter/digit start. The type checks will likely result in a=3 or similar.
            // Let's trace `a-c-g`.
            // i=0: 'a'. Checks pass. Expands 'a' to 'c'. Output: abc. i+=2 -> i=2. Loop end i++ -> i=3.
            // i=3: '-'.
            // Check 1: '-' is not 'a'-'z'. a+=1.
            // Check 2: '-' is not 'A'-'Z'. a+=1.
            // Check 3: '-' is not '0'-'9'. a+=1.
            // a=3. Condition `a!=3` is false. Else prints '-'.
            // i++ -> i=4.
            // i=4: 'g'.
            // Check 1: 'g' is lower. s[6] is '-'. s[6] is not 'a'-'z'. a+=1.
            // Check 2: a+=1.
            // Check 3: a+=1.
            // a=3. Condition false. Prints 'g'.
            // This explains why `a-c-g` outputs `abc-g`. The second expansion `c-g` is missed because the loop skips over the 'c' (index 2) after the first expansion. The code jumps from index 0 to 3. It completely skips index 2 ('c'). But wait, the expansion was `a-c`. The string is `a-c-g`.
            // The problem is that after expanding `a-c`, the index `i` is at 2 (the 'c'). The code does `i+=2` making it 4? No, `i+=2` on `i=0` makes `i=2`. Then the `for` loop does `i++`, making `i=3`.
            // The character at index 2 is 'c'. It was already printed as part of the expansion.
            // The character at index 3 is '-'.
            // The character at index 4 is 'g'.
            // We want to expand `c-g`? No, the input is `a-c-g`. The expansions are `a-c` and then what?
            // The expected output is `abcdefg`. This implies `a-c` becomes `abc` and `c-g` becomes `cdefg`? No, that would duplicate c.
            // Expected: `a-c-g` -> `abcdefg`.
            // This means `a-c` expands to `abc`. Then `-g`? No.
            // The input is `a-c-g`.
            // If we expand `a-c`, we get `abc`. The remaining string is `-g`.
            // If we expand `c-g`, we get `cdefg`.
            // The standard interpretation of `a-c-g` is usually chained. `a` to `c` and `c` to `g`.
            // However, the reference program processes left-to-right.
            // Reference program:
            // i=0 ('a'): sees `a-c`. Expands `a` to `c` (prints `abc`). `i` becomes `i+1` inside if? No, reference has `i++` inside if.
            // Reference: `for(int i=0...){ if(...){ ... i++; } }`.
            // If reference expands `a-c`, it prints `abc`. Then `i++` makes `i=1`. Loop `i++` makes `i=2`.
            // At `i=2` ('c'): checks `c-g`. Expands `c` to `g` (prints `cdefg`). Total `abcdefg`.
            // My buggy code: `i+=2` inside if.
            // i=0. Expands `a-c`. Prints `abc`. `i+=2` -> `i=2`. Loop `i++` -> `i=3`.
            // Skips `c` at index 2. So `c-g` is never processed as a start of expansion.
            // The error is `i+=2` should be `i+=1` or handled differently to allow the next character (the end of the current range) to be the start of the next range.
            
            char put=s[i];

            for(int j=0;j<=s[i+2]-s[i];j++){
                printf("%c",put+j);
            }i+=2; // @@ [Logic Error: Incrementing i by 2 skips the character at s[i+2] (the end of the range). In a chain like a-c-g, the 'c' at s[i+2] should be the starting point for the next potential expansion (c-g). By skipping it, the second expansion is missed. It should be `i+=1` so that the loop's subsequent `i++` moves to `s[i+2]`.]


        } else printf("%c",s[i]);

    }
    

    system("pause");
    return 0;
}