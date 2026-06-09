#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int a,b,c;
    char x,y,z;
    a=0;
    x='+';
    scanf("%d %c",&b,&y); // @@ The format string "%d %c" consumes one optional space, but if there are multiple spaces or no spaces, it might behave unexpectedly compared to the requirement "The expression may contain spaces". However, the main logic error is below.
    while(1)
    {
        if(y=='*'||y=='/')
        {
            scanf("%d %c",&c,&z);
            if(y=='*') b=b*c;
            else if(y=='/') b=b/c;
            
            y=z;
        }
        if(y=='+'||y=='-')
        {
            if(y=='+') a=a+b;
            else if(y=='-') a=a-b;
            
            x=y;
            scanf("%d %c",&b,&y);
        }
        if(y=='=')
        {
            if(x=='+') a=a+b; // @@ Logic Error: When '=' is encountered, the last term 'b' has not yet been added/subtracted to 'a' in the previous loop iteration because the loop breaks immediately upon seeing '=' after processing high-precedence operators. However, the variable 'x' holds the operator *before* the current term 'b'. The code attempts to apply 'x' to 'b'. But 'x' was updated in the previous step. Let's trace: 10 + 20... x='+', b=10. y='+'. a=0+10=10. x='+'. scanf -> b=20, y='*'. Loop. y=='*'. scanf c=30, z='-'. b=600. y='-'. Loop. y=='-'. a=10+600=610. x='-'. scanf -> b=40, y='/'. Loop. y=='/'. scanf c=5, z='='. b=8. y='='. Loop. y=='='. if(x=='-') a=610-8=602. This seems correct for this case. 
            // Wait, let's look at the failure case: 10 + 20 * 30 - 40 / 5 =
            // Trace:
            // Init: a=0, x='+'. scanf: b=10, y='+'.
            // Iter 1: y is '+'. if(y=='+'||'-') true. a = 0+10=10. x='+'. scanf: b=20, y='*'.
            // Iter 2: y is '*'. if(y=='*'||'/') true. scanf: c=30, z='-'. b=20*30=600. y='-'.
            // Next check: if(y=='+'||'-') true. a=10+600=610. x='-'. scanf: b=40, y='/'.
            // Iter 3: y is '/'. if(y=='*'||'/') true. scanf: c=5, z='='. b=40/5=8. y='='.
            // Next check: if(y=='+'||'-') false.
            // Next check: if(y=='=') true. if(x=='-') a=610-8=602. Output 602.
            // The provided buggy output is -598. Why?
            // Let's re-read the code carefully.
            // The issue might be how `scanf("%d %c", ...)` handles spaces.
            // If input is "10 + 20 * 30 - 40 / 5 =", scanf("%d %c") reads 10 into b, then skips whitespace and reads '+' into y.
            // Then inside loop: y is '+'. a+=b (a=10). x='+'. scanf("%d %c") reads 20 into b, skips whitespace, reads '*' into y.
            // y is '*'. scanf("%d %c") reads 30 into c, skips whitespace, reads '-' into z. b=600. y=z='-'.
            // y is '-'. a+=b (a=610). x='-'. scanf("%d %c") reads 40 into b, skips whitespace, reads '/' into y.
            // y is '/'. scanf("%d %c") reads 5 into c, skips whitespace, reads '=' into z. b=8. y=z='='.
            // y is '='. if(x=='-') a-=b -> 610-8=602.
            // So why did it fail?
            // Perhaps the input format has specific spacing issues or the `scanf` format string is too rigid?
            // Actually, look at the first scanf: `scanf("%d %c",&b,&y);`.
            // If the input starts with spaces, `%d` skips them. Then `%c` with a space in format string skips whitespace.
            // The problem says "The expression may contain spaces".
            // Let's look at the reference program. It uses `for(;y==' ';scanf("%c",&y));` to handle multiple spaces.
            // The buggy code uses `scanf("%d %c", ...)`. The space in `%d %c` tells scanf to skip any amount of whitespace between the integer and the character. This is generally robust for single spaces.
            // However, what if there are NO spaces? e.g., `10+20`. `%d` reads 10. `%c` with space in format skips whitespace (none). Reads `+`. Correct.
            // What if there are multiple spaces? `10   +`. `%d` reads 10. Space in format skips all spaces. Reads `+`. Correct.
            
            // Is there a logical error in operator precedence handling?
            // The code accumulates `a` only when encountering `+` or `-`.
            // When `*` or `/` is encountered, it updates `b` immediately.
            // This effectively handles precedence: `b` holds the current term value.
            
            // Let's check the case where the expression ends.
            // When `y` becomes `=`, we execute the final addition/subtraction using `x` and `b`.
            // `x` holds the operator preceding the current term `b`.
            // This logic seems sound for `10 + 20 * 30 - 40 / 5 =`.
            
            // Why -598?
            // 10 + 600 - 8 = 602.
            // -598 is roughly -(600 - 2)? Or 10 - 600 - 8 = -598.
            // If `a` started at 0, and the first operation was subtraction?
            // If `x` was initialized to `-`? No, `x='+'`.
            // If the first term was subtracted? `a = a - b`?
            // In the first iteration: `y` is `+`. `a = 0 + 10 = 10`. `x = '+'`.
            
            // Let's look at `scanf` return values or potential failures.
            // If `scanf` fails to read a char, `y` remains unchanged?
            
            // Actually, there is a subtle bug in `scanf("%d %c", &b, &y)`.
            // If the input is `10 + 20 * 30 - 40 / 5 =`, everything works.
            
            // Consider the input: `1 =`.
            // scanf: b=1, y='='.
            // Loop:
            // y!='*'/'/'.
            // y!='+'/'-'.
            // y=='='.
            // if(x=='+') a=a+b -> 0+1=1. Correct.
            
            // Consider: `1 - 2 =`.
            // scanf: b=1, y='-'.
            // Loop:
            // y=='-'.
            // a = 0+1=1. x='-'.
            // scanf: b=2, y='='.
            // Loop:
            // y=='='.
            // if(x=='-') a=1-2=-1. Correct.
            
            // Where does -598 come from?
            // 10 + 20 * 30 - 40 / 5
            // 10 + 600 - 8 = 602.
            // If the code calculated 10 - 600 - 8 = -598.
            // This implies the first term was subtracted, or the second term was subtracted instead of added.
            // For the second term (600) to be subtracted, `x` must be `-` when `a=a+b` is executed for that term.
            // `x` is set to `y` from the *previous* term's operator.
            // When processing `20 * 30`, `y` becomes `*` then `-`.
            // The block `if(y=='+'||y=='-')` executes.
            // At this point, `a` is 10. `b` is 600.
            // The operator used to add `b` to `a` is determined by `y`?
            // NO! The code says:
            // `if(y=='+') a=a+b; else if(y=='-') a=a-b;`
            // It uses `y` (the operator AFTER the term) to decide how to add the PREVIOUS term?
            // No, wait.
            // Sequence:
            // 1. Read `b` (10), `y` (+).
            // 2. Check `y`. It is `+`.
            // 3. Execute `a=a+b` (0+10). Set `x=y` (+). Read next `b` (20), `y` (*).
            // 4. Check `y`. It is `*`. Process multiplication. `b` becomes 600. `y` becomes `-` (from `z`).
            // 5. Check `y`. It is `-`.
            // 6. Execute `a=a+b` (10+600). Set `x=y` (-). Read next `b` (40), `y` (/).
            
            // WAIT. The logic `if(y=='+') a=a+b` uses the operator `y` which was read *after* the number `b` was read?
            // In step 1, we read `10` and `+`. `y` is `+`.
            // Then we add `b` (10) to `a`. This associates the `+` with the number `10` that preceded it?
            // Standard infix: `10 + 20`. The `+` is between them.
            // Usually, you store the previous operator.
            // Here, `x` stores the previous operator.
            // But the code uses `y` to decide the addition/subtraction in the `if(y=='+'||y=='-')` block?
            // Let's look closely at lines 23-24:
            // `if(y=='+') a=a+b;`
            // `else if(y=='-') a=a-b;`
            // And then `x=y;`
            
            // In Iteration 1:
            // `b`=10, `y`=`+`.
            // `a` = 0 + 10 = 10.
            // `x` = `+`.
            // Read `b`=20, `y`=`*`.
            
            // In Iteration 2:
            // `y`=`*`. Process mult. `b`=600. `y` becomes `-`.
            // Now `y` is `-`.
            // `if(y=='-') a=a-b` -> `a` = 10 - 600 = -590.  <-- ERROR HERE
            // The operator `y` (`-`) is the one FOLLOWING the term `600`.
            // But the code applies it to ADD/SUBTRACT the term `600` itself.
            // The term `600` should be ADDED because the operator BEFORE it was `+`.
            // The operator BEFORE it is stored in `x`.
            // The code SHOULD use `x` to determine whether to add or subtract `b`.
            // Instead, it uses `y` (the upcoming operator).
            // This shifts the sign association.
            // `10 + 20 ...` -> `y` is `+`. Adds 10. Correct.
            // `... 20 * 30 - ...` -> Term is 600. Upcoming op is `-`. Code subtracts 600. Incorrect. Should add 600 (because prev op was `+`).
            // `... 40 / 5 =` -> Term is 8. Upcoming op is `=`. Code doesn't enter `if(y=='+'||'-')`.
            // Then `if(y=='=')` uses `x` (which is `-`) to subtract 8.
            // So calculation: `10 - 600 - 8 = -598`.
            // This matches the Buggy Output!
            
            // So the error is in lines 23-24. It should use `x` instead of `y` to decide the operation on `b`.
            // And `x` should be updated to `y` AFTER the addition/subtraction.
            
            else if(x=='-') a=a-b;
            
            printf("%d\n",a);
            break;
        }
    }
    return 0;
}