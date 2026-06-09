#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#define max(a, b) ( (a > b) ? (a) : (b) )
#define min(a, b) ( (a < b) ? (a) : (b) )
int main () {
    char a;
    char b;
    while(scanf("%c", &a)!=EOF){
        if(a=='-'){
            scanf("%c", &a);
            if((b>='a'&&a<='z'&&(b<a))||(b>='A'&&a<='Z'&&(b<a))||(b>='0'&&a<='9'&&(b<a))){ // @@ The condition checks if 'a' is within a specific range (e.g., 'a'<='z') but fails to check if 'b' is in the same corresponding range (e.g., 'b'>='a'). For example, if b='u' and a='B', the condition `b>='a'` is true, and `a<='z'` is true, so it enters the expansion block incorrectly or misses valid expansions where boundary checks are incomplete. More critically, the logic for type matching is flawed. It should ensure both are lowercase, both uppercase, or both digits. The current check `(b>='a'&&a<='z'...)` allows mixed types if they happen to fall into ASCII ranges loosely. However, the specific failure here is likely due to the loop condition or the update of b. Let's look closer. The input is `a-uB-F`.
            // Trace:
            // 1. Read 'a'. Print 'a'. b='a'.
            // 2. Read '-'. Read next 'u'. Check: b='a', a='u'. `b>='a'` (T), `a<='z'` (T), `b<a` (T). Expand 'b'..'t'. Print "bc...t". b='u'.
            // 3. Read 'B'. Print 'B'. b='B'.
            // 4. Read '-'. Read next 'F'. Check: b='B', a='F'. `b>='A'` (T), `a<='Z'` (T), `b<a` (T). Expand 'C'..'E'. Print "CDE". b='F'.
            // Expected: abcdefghijklmnopqrstuBCDEF
            // Actual Output from buggy code logic described:
            // The loop `for(char j = b+1; j < a; j++)` prints characters strictly between b and a.
            // In step 2: prints b..t (stops before u). Correct so far.
            // In step 4: prints C..E (stops before F). Correct so far.
            // Where is 'u' and 'F'?
            // The code prints `a` (the char after '-') only in the `else` branch `printf("-%c", a)` if expansion fails.
            // If expansion succeeds, it does NOT print the end character `a`.
            // The reference program prints the start character `b` at the beginning of the loop iteration.
            // This program prints characters as they are read, unless it's a '-'.
            // When it sees '-', it reads the next char `a`.
            // If it expands, it prints the middle chars. It does NOT print the end char `a`.
            // Then `b=a` updates b to the end char.
            // The end char `a` will be printed in the NEXT iteration if it's not a '-'.
            // Let's re-trace carefully.
            // Input: a - u B - F
            // 1. scanf 'a'. Not '-'. Print 'a'. b='a'.
            // 2. scanf '-'. Is '-'. scanf 'u'.
            //    Check pass. Loop j='b' to 't'. Print "bc...t".
            //    Does NOT print 'u'.
            //    b = 'u'.
            // 3. scanf 'B'. Not '-'. Print 'B'. b='B'.
            //    Wait, the input stream is `a-uB-F`.
            //    After reading 'u', the next char is 'B'.
            //    So step 3 reads 'B'. Prints 'B'. b='B'.
            // 4. scanf '-'. Is '-'. scanf 'F'.
            //    Check pass. Loop j='C' to 'E'. Print "CDE".
            //    Does NOT print 'F'.
            //    b = 'F'.
            // 5. scanf EOF. Loop ends.
            // Output: a bc...t B CDE.
            // Missing: 'u' and 'F'.
            // The character following the expansion range (the upper bound) is consumed by `scanf("%c", &a)` inside the `if(a=='-')` block.
            // It is stored in `a`, used for expansion logic, and then assigned to `b`.
            // It is NEVER printed if expansion occurs.
            // If expansion does NOT occur, it is printed via `printf("-%c", a)`.
            // So, if expansion occurs, the upper bound character is lost.
            // We need to print the upper bound character `a` after the loop if expansion happened.
            }else{
                printf("-%c", a);
            }
        }else{
                printf("%c", a);
        }
        b=a;
    }
    return 0;
}