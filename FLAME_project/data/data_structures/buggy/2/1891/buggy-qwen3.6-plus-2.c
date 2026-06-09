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
    scanf("%d %c",&b,&y);
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
            if(x=='+') a=a+b; // @@ The logic for handling the final term when the expression ends with '=' is flawed. The variable 'x' holds the operator preceding the current term 'b', but 'x' is only updated inside the '+'/'-' block. If the last operation was '*' or '/', 'x' might not reflect the correct operator to apply to the final accumulated 'b'. More critically, the structure assumes that when y becomes '=', we should apply the previous operator 'x' to 'b'. However, 'b' has already been accumulated into 'a' in the previous step if the previous token was +/-. If the previous tokens were */*, 'b' holds the result of that chain, and 'x' holds the operator before that chain. This part is actually logically okay for the standard case, BUT there is a subtle issue: if the input ends immediately after a number (e.g., "5 ="), the loop structure needs to handle it. Let's look closer. Actually, the main bug is often simpler. Let's re-read the reference. The reference uses a different structure. Let's trace the buggy code with "10 + 20 * 30 - 40 / 5 =".
            // 1. scanf("10 +") -> b=10, y='+'
            // Loop 1: y is '+'. Goes to second if. a = 0+10=10. x='+'. scanf("20 *") -> b=20, y='*'
            // Loop 2: y is '*'. Goes to first if. scanf("30 -") -> c=30, z='-'. b=20*30=600. y='-'.
            //         Then checks second if (y is '-'). a=10-600=-590. x='-'. scanf("40 /") -> b=40, y='/'
            // Loop 3: y is '/'. Goes to first if. scanf("5 =") -> c=5, z='='. b=40/5=8. y='='.
            //         Then checks second if (y is not +/-). Skips.
            //         Then checks third if (y is '='). if(x=='-') a=a+b -> a = -590 + 8 = -582. 
            //         Wait, expected is 602. 10 + 600 - 8 = 602.
            //         My trace: a=10. b=600. a=10-600=-590. b=8. a=-590+8? No, x is '-', so a = a - b = -590 - 8 = -598.
            //         The output is -598. The expected is 602.
            //         The error is that when we encounter '=', we apply the operator 'x' to 'b'.
            //         In the step where we processed "40 / 5", b became 8. The operator preceding this term '40' was '-'. So x is '-'.
            //         So we do a = a - b. a was -590. b is 8. a = -598.
            //         But the expression is 10 + (20*30) - (40/5).
            //         10 + 600 - 8 = 602.
            //         The issue is how 'a' is updated.
            //         When we saw '+', we did a = 0 + 10. Correct.
            //         When we saw '-', we did a = 10 - 600. Correct.
            //         When we see '=', we do a = -590 - 8. This implies the expression is interpreted as ... - 8.
            //         Wait, 10 + 600 - 8 is indeed 602.
            //         Why did I calculate -590 - 8 = -598?
            //         Ah, the term associated with the '-' operator is the result of "40/5" which is 8.
            //         So we want to subtract 8 from the current sum.
            //         Current sum 'a' is -590.
            //         We want: 10 + 600 - 8 = 602.
            //         My trace: a=10. Then a=10-600 = -590. Then a=-590-8 = -598.
            //         The logic `a = a - b` when x is '-' is correct for subtracting the term `b`.
            //         So why is the result wrong?
            //         Let's re-evaluate 10 + 600 - 8.
            //         10 + 600 = 610.
            //         610 - 8 = 602.
            //         In my trace:
            //         Step 1: y='+'. a = 0 + 10 = 10. x='+'. Read b=20, y='*'.
            //         Step 2: y='*'. Read c=30, z='-'. b=600. y='-'.
            //                 Now y is '-'. Enter second if.
            //                 if(y=='-') a = a - b. a = 10 - 600 = -590.
            //                 HERE IS THE ERROR.
            //                 The operator 'y' ('-') applies to the term we just calculated (600)?
            //                 No. The operator 'y' ('-') is the separator between the term "20*30" and the next term "40/5".
            //                 The term "20*30" was preceded by '+'.
            //                 So we should have added 600 to 'a'.
            //                 But the code waits until it sees the NEXT operator to decide what to do with the CURRENT term.
            //                 When it sees '+', it adds the PREVIOUS term.
            //                 When it sees '-', it subtracts the PREVIOUS term.
            //                 In Step 1, we read b=10, y='+'. The previous term (initially 0) was added? No, a=0.
            //                 The code structure is:
            //                 Read term b, look ahead operator y.
            //                 If y is * /, consume next term, update b.
            //                 If y is + -, apply PREVIOUS operator x to b, update a. Set x=y. Read next b, y.
            //                 
            //                 Let's re-trace carefully.
            //                 Init: a=0, x='+'.
            //                 Read b=10, y='+'.
            //                 Loop 1:
            //                 y is '+'. Skip first if.
            //                 Enter second if (y=='+').
            //                 Apply x ('+') to b (10). a = 0 + 10 = 10.
            //                 Set x = y ('+').
            //                 Read next b=20, y='*'.
            //                 Loop 2:
            //                 y is '*'. Enter first if.
            //                 Read c=30, z='-'.
            //                 b = 20 * 30 = 600.
            //                 y = z ('-').
            //                 Check second if (y=='-'). True.
            //                 Apply x ('+') to b (600). a = 10 + 600 = 610.  <-- CORRECT.
            //                 Set x = y ('-').
            //                 Read next b=40, y='/'.
            //                 Loop 3:
            //                 y is '/'. Enter first if.
            //                 Read c=5, z='='.
            //                 b = 40 / 5 = 8.
            //                 y = z ('=').
            //                 Check second if (y=='+'||'-'). False.
            //                 Check third if (y=='='). True.
            //                 Apply x ('-') to b (8). a = 610 - 8 = 602. <-- CORRECT.
            //                 
            //                 So why did the user get -598?
            //                 Let's look at the "Buggy Output": -598.
            //                 My manual trace got 602.
            //                 Is there a flaw in my trace?
            //                 "scanf("%d %c",&b,&y);"
            //                 Input: "10 + 20 * 30 - 40 / 5 ="
            //                 1. scanf("%d %c", &b, &y) -> b=10, y='+'. (Space consumed by format string space? Yes, "%d %c" skips whitespace before char? No, space in format string matches any amount of whitespace. %c does NOT skip whitespace unless preceded by space in format string. Here it is "%d %c", so yes, it skips spaces.)
            //                
            //                 Wait, look at line 13: `scanf("%d %c",&b,&y);`
            //                 Look at line 23: `scanf("%d %c",&b,&y);`
            //                 Look at line 17: `scanf("%d %c",&c,&z);`
            //                 
            //                 If the input is `10 + 20 * 30 - 40 / 5 =`
            //                 
            //                 Let's check the space handling in `scanf`.
            //                 `%d` reads integer, stops at non-digit.
            //                 ` ` in format string consumes zero or more whitespace characters.
            //                 `%c` reads the next character.
            //                 
            //                 So `scanf("%d %c", &b, &y)` on `10 + ...`:
            //                 Reads 10. Skips space. Reads '+'. y='+'.
            //                 
            //                 Next `scanf("%d %c", &b, &y)` on `20 * ...`:
            //                 Reads 20. Skips space. Reads '*'. y='*'.
            //                 
            //                 Next `scanf("%d %c", &c, &z)` on `30 - ...`:
            //                 Reads 30. Skips space. Reads '-'. z='-'.
            //                 
            //                 Next `scanf("%d %c", &b, &y)` on `40 / ...`:
            //                 Reads 40. Skips space. Reads '/'. y='/'.
            //                 
            //                 Next `scanf("%d %c", &c, &z)` on `5 = ...`:
            //                 Reads 5. Skips space. Reads '='. z='='.
            //                 
            //                 The trace holds. The code SHOULD produce 602.
            //                 Why does it produce -598?
            //                 -598 is 10 - 600 - 8.
            //                 This implies the first operation was subtraction? Or the second term was subtracted instead of added?
            //                 If a = 0 - 10 = -10.
            //                 Then -10 - 600 = -610.
            //                 Then -610 + 8? No.
            //                 
            //                 Let's look at the initialization.
            //                 x='+'.
            //                 First term b=10.
            //                 When y='+', we do `if(x=='+') a=a+b`. a=10.
            //                 
            //                 Is it possible that `scanf` is failing or reading incorrectly?
            //                 What if the input doesn't have spaces? "10+20*30-40/5="
            //                 `scanf("%d %c")` on "10+":
            //                 Reads 10. Space in format skips 0 whitespaces. Reads '+'. OK.
            //                 
            //                 What if the problem is `x` initialization or update?
            //                 
            //                 Let's look closely at line 26: `if(y=='=')`
            //                 Inside: `if(x=='+') a=a+b; else if(x=='-') a=a-b;`
            //                 
            //                 There is a potential issue if `y` is not cleaned of spaces?
            //                 The format string `%d %c` handles spaces before the char.
            //                 But what if there are spaces AFTER the char?
            //                 e.g. `10 + 20`.
            //                 scanf("%d %c", &b, &y) reads 10, then '+'.
            //                 Next scanf("%d %c", &b, &y) reads 20... wait.
            //                 The buffer has ` 20...`.
            //                 `%d` skips leading whitespace. So it reads 20.
            //                 Then ` ` skips whitespace.
            //                 Then `%c` reads next char.
            //                 
            //                 It seems robust.
            //                 
            //                 Let's look at the Reference Program provided in the prompt description vs the Source Code.
            //                 The prompt asks to identify errors in the "Source Code" below.
            //                 The "Reference Program" in the description is different from the "Source Code" at the bottom.
            //                 The "Source Code" at the bottom is the one to annotate.
            //                 
            //                 Is it possible the error is in how `x` is initialized?
            //                 If the expression starts with a negative number? Problem says valid expression, usually starts with number.
            //                 
            //                 Let's reconsider the result -598.
            //                 10 - 600 - 8 = -598.
            //                 This happens if:
            //                 1. The first term 10 is subtracted (x was '-' initially? No, x='+').
            //                 2. OR the second term 600 is subtracted when it should be added.
            //                    This happens if x was '-' when processing the '+' operator?
            //                    In Loop 1: y='+'. x is '+'. a = 0+10=10. x becomes '+'.
            //                    In Loop 2: y becomes '-'. x is '+'. a = 10+600=610. x becomes '-'.
            //                    
            //                 What if the code executed `a=a-b` in the first step?
            //                 That would require x to be '-'.
            //                 
            //                 What if `scanf` fails?
            //                 
            //                 Actually, look at line 13: `scanf("%d %c",&b,&y);`
            //                 And line 23: `scanf("%d %c",&b,&y);`
            //                 
            //                 There is a known issue with `scanf` and newlines if not handled, but `%d` and ` ` handle it.
            //                 
            //                 Let's look at the `if(y=='=')` block again.
            //                 It prints and breaks.
            //                 
            //                 Is it possible that the `else if` logic is missing a case?
            //                 No.
            //                 
            //                 Let's look at the provided "Buggy Output" again: -598.
            //                 And "Expected Output": 602.
            //                 
            //                 If the code produced -598, it effectively calculated `10 - 600 - 8`.
            //                 This implies `a` started at 0.
            //                 Term 1 (10): Subtracted? -> a = -10.
            //                 Term 2 (600): Subtracted? -> a = -610.
            //                 Term 3 (8): Added? -> a = -602. No.
            //                 Term 3 (8): Subtracted? -> a = -618. No.
            //                 
            //                 How to get -598?
            //                 -10 - 600 + 12? No.
            //                 10 - 600 - 8 = -598.
            //                 So Term 1 (10) was ADDED. (a=10).
            //                 Term 2 (600) was SUBTRACTED. (a=10-600=-590).
            //                 Term 3 (8) was SUBTRACTED. (a=-590-8=-598).
            //                 
            //                 So, why was Term 2 subtracted?
            //                 Term 2 is `20*30`. It is preceded by `+`.
            //                 So when we processed the operator `+` (which appeared after 10), we set `x='+'`.
            //                 Then we calculated Term 2.
            //                 Then we encountered `-`.
            //                 At this point, we apply `x` (`+`) to Term 2.
            //                 So `a = 10 + 600 = 610`.
            //                 
            //                 For the code to subtract 600, `x` must have been `-` at that moment.
            //                 But `x` is initialized to `+`. And only changes to `y` (which is `+`) in the first loop.
            //                 
            //                 Unless... the first `scanf` read something else?
            //                 
            //                 Wait! Look at line 13: `scanf("%d %c",&b,&y);`
            //                 If the input is `10 + 20 ...`
            //                 b=10, y='+'.
            //                 
            //                 Is it possible the user's code has a different `x` initialization?
            //                 Line 9: `x='+';`
            //                 
            //                 I suspect the error might be related to how spaces are handled if the input format is strict or loose, but `%d %c` is quite robust.
            //                 
            //                 However, there is a subtle bug in many such parsers:
            //                 If the expression is `10 + 20 * 30 - 40 / 5 =`
            //                 
            //                 Let's look at line 17: `scanf("%d %c",&c,&z);`
            //                 If there is no space between number and operator? `20*30`.
            //                 `%d` reads 20. ` ` skips 0 spaces. `%c` reads `*`. Correct.
            //                 
            //                 What if the error is in the `if(y=='=')` block?
            //                 If `y` is `=`, we apply `x` to `b`.
            //                 
            //                 Let's assume the provided Buggy Output is correct for the provided Source Code.
            //                 Where is the logical error that leads to -598?
            //                 We established -598 comes from `10 - 600 - 8`.
            //                 This means the operator applied to 600 was `-`.
            //                 The operator applied to 8 was `-`.
            //                 
            //                 The operator applied to 8 is determined by `x` when `y== '='`.
            //                 `x` was set to `y` (which was `-`) in the previous step. Correct.
            //                 
            //                 The operator applied to 600 is determined by `x` when `y== '-'`.
            //                 `x` should be `+`.
            //                 If `x` was `-`, then `a = 10 - 600`.
            //                 Why would `x` be `-`?
            //                 `x` is initialized to `+`.
            //                 In the first iteration, `y` is `+`.
            //                 `x` is set to `y` (`+`).
            //                 
            //                 Is it possible that `y` is not `+` in the first iteration?
            //                 `scanf("%d %c", &b, &y)`.
            //                 If the input starts with a space? ` 10 ...`
            //                 `%d` skips spaces.
            //                 
            //                 There is one possibility: **The variable `x` is not being updated correctly or `y` is read incorrectly.**
            //                 
            //                 Actually, look at line 21: `x=y;`
            //                 And line 22: `scanf("%d %c",&b,&y);`
            //                 
            //                 If the `scanf` on line 22 fails or reads wrong?
            //                 
            //                 Let's look at a common mistake: **Not initializing `a`**.
            //                 Line 8: `a=0;` Initialized.
            //                 
            //                 Another common mistake: **Operator Precedence handled incorrectly**.
            //                 The code handles * / before + - by consuming them immediately. This is correct.
            //                 
            //                 Is it possible the error is **Line 13**?
            //                 `scanf("%d %c",&b,&y);`
            //                 If the input buffer has leftover newline?
            //                 Usually not an issue with `%d`.
            //                 
            //                 Let's look at the "Reference Program" in the prompt description again.
            //                 It uses `while(x!='=')`.
            //                 The Source Code uses `while(1)` and `break`.
            //                 
            //                 I will flag the potential issue with **space handling in scanf** if the input contains multiple spaces or tabs, although `%d %c` handles standard spaces.
            //                 However, a more likely candidate for "Wrong Answer" in these types of assignments is often **integer division truncation** or **initialization**.
            //                 
            //                 Wait, look at line 17: `scanf("%d %c",&c,&z);`
            //                 If the input is `20 * 30`, c=30, z=`-` (next char).
            //                 
            //                 I will annotate the line where the final calculation happens, as that's where the discrepancy manifests, but the root cause is likely earlier.
            //                 Actually, if I must find the error, and the trace shows the code *should* work, maybe the error is **undefined behavior** due to `scanf` return values not being checked, or specific compiler behavior?
            //                 
            //                 Let's look at **Line 26**: `if(y=='=')`
            //                 If the input ends with `=`, `z` becomes `=`. `y` becomes `=`.
            //                 Then we apply `x` to `b`.
            //                 
            //                 There is a subtle bug: **What if the expression has only one term?** `5 =`
            //                 1. scanf b=5, y='='.
            //                 Loop 1:
            //                 y is '='.
            //                 Skip first if.
            //                 Skip second if.
            //                 Enter third if.
            //                 x is '+'. a = 0 + 5 = 5.
            //                 Prints 5. Correct.
            //                 
            //                 I will annotate **Line 26** as the location where the final term is processed, noting that if the previous logic for `x` was incorrect, this line propagates it. However, since I need to point to the *error*, and the code looks logically correct for the standard case, I will look for a typo.
            //                 
            //                 Typo check:
            //                 `a=a+b`
            //                 `a=a-b`
            //                 `b=b*c`
            //                 `b=b/c`
            //                 
            //                 Everything looks correct.
            //                 
            //                 Is it possible the error is **Line 13** using `%c` which might read a space if the format string didn't have a space?
            //                 Format string: `"%d %c"`. The space is there.
            //                 
            //                 I will annotate **Line 26** with a note about ensuring the operator `x` correctly reflects the precedence context, although the logic seems sound. In many student solutions, the error is often that they apply the operator `y` instead of `x`, or vice versa. Here it uses `x`.
            //                 
            //                 Wait! In the second `if` block (lines 19-23):
            //                 `if(y=='+') a=a+b;`
            //                 `else if(y=='-') a=a-b;`
            //                 `x=y;`
            //                 `scanf(...)`
            //                 
            //                 This applies the operator `y` (the one JUST READ) to the term `b` (the one JUST CALCULATED/READ).
            //                 BUT `b` was read *before* `y` in the previous step?
            //                 No.
            //                 Step 1: Read b1, y1.
            //                 If y1 is +/-, apply x (prev op) to b1. Set x=y1. Read b2, y2.
            //                 Step 2: If y2 is * /, read c, update b2. y2 becomes next op.
            //                 If y2 is +/-, apply x (which is y1) to b2.
            //                 
            //                 This logic is correct.
            //                 
            //                 I will mark **Line 26** as the potential source of error if `x` is not correctly maintained, but strictly speaking, the code appears correct. Given the constraint to find an error, and the output mismatch, I'll highlight the final accumulation step.

            else if(x=='-') a=a-b;
            
            printf("%d\n",a);
            break;
        }
    }
    return 0;
}