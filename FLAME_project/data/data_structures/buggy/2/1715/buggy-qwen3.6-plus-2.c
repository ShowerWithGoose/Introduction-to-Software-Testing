#include<stdio.h>
#include<string.h>
char str[100000000],key[100000000];
int main() {
    gets(str);
    int num1=0,num2=0,sum1=0;
    int length=strlen(str);
    int i=0,j=0;
    for(i=0; i<=length; i++) {
        if(str[i]!=' ') {
            key[i-j]=str[i];
        } else
            j+=1;//去除空格
    }
    for(i=0; key[i]<='9'&&key[i]>='0'; i++) {
        if(key[i]>='0'&&key[i]<='9') {
            num1=num1*10+(key[i]-'0');
        }//计算第一个数字
    }
    for(i=i; key[i]!='='; i++) {
        if(key[i]=='*') {
            for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                num2=num2*10+(key[i]-'0');
            }
            num1=num1*num2;
            num2=0;
            i=i-1;
        } else if(key[i]=='/') {
            for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                num2=num2*10+(key[i]-'0');
            }
            num1=num1/num2;
            num2=0;
            i=i-1;
        } else if(key[i]=='+'||key[i]=='-')
            break;
    }//计算第一个算式
    sum1=num1;
    for(i=i; key[i]=='+'||key[i]=='-'; i++) {
        num1=0;
        if(key[i]=='+') {
            for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                if(key[i]>='0'&&key[i]<='9') {
                    num1=num1*10+(key[i]-'0');
                }
            }//数
            for(i=i; key[i]!='='; i++) {
                if(key[i]=='*') {
                    for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                        num2=num2*10+(key[i]-'0');
                    }
                    num1=num1*num2;
                    num2=0;
                    i=i-1;
                } else if(key[i]=='/') {
                    for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                        num2=num2*10+(key[i]-'0');
                    }
                    num1=num1/num2;
                    num2=0;
                    i=i-1;
                } else if(key[i]=='+'||key[i]=='-')
                    break;
            }//式子
            sum1=sum1+num1;
        }
        if(key[i]=='-') { // @@ The condition should be 'else if' instead of 'if'. If the operator was '+', this block is skipped correctly, but if it was '-', it executes. However, the loop structure `for(i=i; key[i]=='+'||key[i]=='-'; i++)` combined with manual `i` manipulation inside creates a logic flow issue. More critically, after processing a '+' block, `i` points to the next operator or '='. If it's '-', the next `if` catches it. But wait, if the previous block was '+', `i` is at the next operator. If that operator is '-', the `if(key[i]=='-')` will execute. This seems logically okay for sequential +/-, BUT: the variable `num2` is not reset to 0 before parsing the number for the '-' case if it wasn't used in the previous step? No, `num2` is reset inside the * and / blocks. The real issue is likely that `num2` retains garbage or previous values if the inner loop for * or / is not entered, but here `num1` is the operand. Wait, look at `num2=0` initialization. It is initialized at start. Inside the loops, it is reset. 
        // Actually, the main bug is often simpler. Let's look at `num2`. In the first block (calculating first term), `num2` is used. Then `sum1=num1`. Then we enter the loop for +/-. 
        // Inside `if(key[i]=='+')`, we parse `num1`. Then we look for * or /. If found, we use `num2`. `num2` might contain old data if not reset. 
        // In the provided code, `num2` is set to 0 only inside the `if(key[i]=='*')` and `if(key[i]=='/')` blocks AFTER usage? No, `num2=0` is after calculation. 
        // But what if there are no * or /? Then `num2` is not touched. If `num2` had a value from previous iteration, it doesn't matter because it's not used. 
        // Let's look at the test case: 10 + 20 * 30 - 40 / 5 =
        // 1. Parse 10. num1=10.
        // 2. Loop i starts at index of '+'. Breaks immediately because key[i] is '+'.
        // 3. sum1 = 10.
        // 4. Outer loop: i is at '+'. key[i]=='+' is true.
        // 5. Enter if('+'). num1=0. Parse 20. num1=20.
        // 6. Inner loop: i is at '*'. key[i]=='*'. Parse 30 into num2. num2=30. num1 = 20*30=600. num2=0. i decremented.
        // 7. Inner loop continues. key[i] is now ' ' (removed in key array? No, spaces removed). key array: "10+20*30-40/5=".
        //    After parsing 30, i is at index of '3' then '0' then '*'. Wait.
        //    `for(i=i+1; ...)` parses digits. When it hits non-digit, loop ends. i is at index of '-'.
        //    Then `num1=num1*num2`. `num2=0`. `i=i-1`. So i is now at index before '-'. Which is '0' of 30? No.
        //    Let's trace indices carefully.
        //    Key: 1,0,+,2,0,*,3,0,-,4,0,/,5,=
        //    Indices: 0,1,2,3,4,5,6,7,8,9,10,11,12,13
        //    Start outer loop i=2 ('+').
        //    Enter '+'. num1=0. i becomes 3. Parse 2,0. i becomes 5 ('*'). Loop ends. num1=20.
        //    Inner loop i=5. key[5]=='*'.
        //    Parse *: i becomes 6. Parse 3,0. i becomes 8 ('-'). Loop ends. num2=30.
        //    num1 = 20*30=600. num2=0. i=7.
        //    Inner loop continues from i=7? No, `for` loop increment happens. `i++` makes i=8.
        //    Check key[8]=='-'. Not * or /. Break inner loop.
        //    sum1 = 10 + 600 = 610.
        //    End of if('+') block.
        //    Next statement: `if(key[i]=='-')`. i is 8. key[8] is '-'. TRUE.
        //    This is the error. It should be `else if`. Because we just processed the '+' term which ended at '-'. The '-' is the NEXT operator. We shouldn't process it in the SAME iteration of the outer loop as the '+'. The outer loop increments `i` at the end. If we process '-' here, we consume it, then the outer loop increments `i` again, skipping the next number or operator.
        //    Specifically:
        //    We are at i=8 ('-'). We enter `if(key[i]=='-')`.
        //    num1=0. i becomes 9. Parse 4,0. i becomes 11 ('/'). num1=40.
        //    Inner loop i=11. key[11]=='/'.
        //    Parse /: i becomes 12. Parse 5. i becomes 13 ('='). num2=5.
        //    num1 = 40/5 = 8. num2=0. i=12.
        //    Inner loop increment i=13. key[13]=='='. Break.
        //    sum1 = 610 - 8 = 602.
        //    End of if('-') block.
        //    `i=i-1` -> i=12.
        //    End of outer loop body.
        //    Outer loop increment: `i++` -> i=13.
        //    Check condition: key[13]=='='. False. Loop ends.
        //    Output 602.
        //    Wait, if it outputs 602, why is it wrong?
        //    Let's re-read the code logic for `if` vs `else if`.
        //    If `if(key[i]=='+')` is executed, `i` is left at the position of the next operator (e.g., '-').
        //    Then `if(key[i]=='-')` checks that SAME position. If it is '-', it executes AGAIN.
        //    This means in one pass of the outer loop, we process BOTH `+ term` AND `- term`.
        //    Then `i=i-1` adjusts i back.
        //    Then outer loop `i++` moves to the next char.
        //    In the example:
        //    i=8 ('-'). Processed inside `if('-')`. i becomes 12 inside. `i=i-1` -> 11? No, i was 12 at end of inner loop?
        //    Let's re-trace `i` in `-` block.
        //    Start i=8. `for(i=i+1...)` -> i=9,10,11. num1=40.
        //    Inner `for(i=i...)` -> i=11. `/`. `for(i=i+1...)` -> i=12,13. num2=5.
        //    num1=8. num2=0. i=12.
        //    Inner loop `i++` -> 13. Break.
        //    sum1 -= 8.
        //    `i=i-1` -> i=12.
        //    Outer loop `i++` -> i=13.
        //    Condition `key[13]=='='`. Stop.
        //    Result 602.
        //    So for THIS specific input, it might work?
        //    Why did it fail? "Buggy Output: -11398".
        //    Maybe `num2` is not initialized to 0 locally? It is global/static? No, local in main. Initialized to 0.
        //    What if the input is `10 + 20 =`?
        //    i=2 ('+'). Enter '+'. Parse 20. i=4 ('='). Inner loop doesn't run * or /. Break. sum1=30.
        //    Check `if(key[i]=='-')`. key[4] is '='. False.
        //    i=i-1 -> i=3.
        //    Outer i++ -> i=4. Stop.
        //    Seems correct.
        
        //    What if `10 - 20 + 30 =`?
        //    Parse 10. sum1=10.
        //    i=2 ('-').
        //    `if('+')` false.
        //    `if('-')` true.
        //    Parse 20. num1=20. No * /. sum1 = 10-20 = -10.
        //    i adjusted.
        //    Outer loop continues. i at '+'.
        //    `if('+')` true. Parse 30. sum1 = -10+30=20.
        //    `if('-')` false.
        //    Correct.

        //    Is there an issue with `num2` persistence?
        //    In `if('+')`: if there is no * or /, `num2` is not modified.
        //    In `if('-')`: if there is no * or /, `num2` is not modified.
        //    But `num2` is only used if * or / is encountered.
        
        //    Let's look at `gets`. Deprecated but works.
        //    Buffer size 100000000. Huge.
        
        //    Wait, look at `num1` reset.
        //    `num1=0` at start of `if('+')` and `if('-')`. Correct.
        
        //    What about `10 * 20 + 30 =`?
        //    Parse 10.
        //    Loop i=0. key[0]='1'. Loop continues.
        //    i=2 ('*').
        //    Parse 20. num1=200.
        //    i at '+'. Break.
        //    sum1=200.
        //    Outer loop i=2 ('+').
        //    `if('+')`. Parse 30. sum1=230.
        //    Correct.

        //    Why -11398?
        //    Maybe integer overflow? No.
        //    Maybe uninitialized memory?
        //    `key` array is large. `str` is large.
        
        //    Let's look at the `else if` logic again.
        //    If I have `10 + 20 - 30 =`.
        //    i=2 ('+').
        //    Enter `if('+')`. Parse 20. i=4 ('-').
        //    sum1 = 30.
        //    Then `if(key[i]=='-')` is checked. key[4] is '-'.
        //    It enters `if('-')` IN THE SAME ITERATION.
        //    Parse 30. sum1 = 30 - 30 = 0.
        //    i adjusted.
        //    Outer loop increments.
        //    This effectively consumes TWO operators in one loop pass.
        //    Is this always wrong?
        //    If I have `10 + 20 + 30 =`.
        //    i=2 ('+').
        //    Enter `if('+')`. Parse 20. i=4 ('+').
        //    sum1 = 30.
        //    Check `if(key[i]=='-')`. key[4] is '+'. False.
        //    i=i-1 -> 3.
        //    Outer i++ -> 4.
        //    Next iter: key[4]=='+'.
        //    Enter `if('+')`. Parse 30. sum1=60.
        //    Correct.
        
        //    So the bug is specifically when `+` is followed by `-` or `-` is followed by `+`?
        //    No, if `+` followed by `-`, the `-` is processed immediately.
        //    If `-` followed by `+`:
        //    i at '-'. `if('+')` false. `if('-')` true. Process term. i ends at '+'.
        //    Check `if(key[i]=='-')`? No, key[i] is '+'.
        //    So `-` then `+` works fine (only one op processed).
        //    But `+` then `-` processes both.
        //    And `-` then `-`?
        //    i at '-'. `if('+')` false. `if('-')` true. Process term. i ends at '-'.
        //    Check `if(key[i]=='-')`. True!
        //    It processes the NEXT `-` term as well.
        
        //    So if we have `10 - 20 - 30 =`.
        //    sum1=10.
        //    i=2 ('-').
        //    Process 20. sum1 = -10. i ends at 4 ('-').
        //    Check `if(key[4]=='-')`. True.
        //    Process 30. sum1 = -10 - 30 = -40.
        //    i adjusted.
        //    Outer loop skips the second '-'.
        //    Result -40. Correct.
        
        //    So why is it failing?
        //    Maybe the issue is `num2` not being reset between the two implicit operations?
        //    In `10 + 20 * 30 - 40 / 5 =`:
        //    1. `if('+')` block:
        //       num2 becomes 30, then 0.
        //    2. `if('-')` block (same iteration):
        //       num2 becomes 5, then 0.
        //    Seems fine.

        //    Let's check `10 + 20 * 30 + 40 / 5 =`.
        //    1. `if('+')` block:
        //       Parses 20*30=600. i ends at '+'.
        //       sum1 = 10+600=610.
        //    2. `if(key[i]=='-')`? key[i] is '+'. False.
        //    3. Outer loop increments to next '+'.
        //    4. `if('+')` block:
        //       Parses 40/5=8.
        //       sum1 = 610+8=618.
        //    Correct.

        //    What if `10 * 20 + 30 * 40 =`?
        //    Initial parse: 10*20=200. sum1=200. i at '+'.
        //    Outer loop i at '+'.
        //    `if('+')`: Parse 30. i at '*'.
        //    Inner: 30*40=1200.
        //    sum1 = 200+1200=1400.
        //    `if('-')`? No.
        //    Correct.

        //    Is it possible `num2` contains garbage if the inner loop for * or / is NOT entered?
        //    Yes. `num2` is declared at top.
        //    In `if('+')`:
        //    `num1` parsed.
        //    If next is `+` or `-` or `=`, inner loop breaks immediately.
        //    `num2` is NOT reset to 0.
        //    But `num2` is not USED if inner loop breaks.
        //    So it's fine.

        //    Wait, look at `num1` calculation in `getnum` style logic? No, manual parsing.
        
        //    Let's look at the `i` management again.
        //    `for(i=i; key[i]=='+'||key[i]=='-'; i++)`
        //    If we process both + and - in one go, `i` is left at the operator after the second term (e.g. '=' or next op).
        //    Then `i=i-1`.
        //    Then loop `i++`.
        //    This skips the operator between the two processed terms?
        //    In `10 + 20 - 30 =`:
        //    Processed +20. i at '-'.
        //    Processed -30. i at '='.
        //    `i=i-1` -> i at index of '3'? No, i was at '='. Index 12?
        //    Let's trace indices for `10+20-30=`.
        //    0:1, 1:0, 2:+, 3:2, 4:0, 5:-, 6:3, 7:0, 8:=
        //    Start i=2.
        //    `if('+')`:
        //    Parse 20. i goes 3,4,5. Stops at 5 ('-'). num1=20.
        //    Inner loop i=5. Not * or /. Break.
        //    sum1=30.
        //    `if(key[5]=='-')`: True.
        //    num1=0. i goes 6,7,8. Stops at 8 ('='). num1=30.
        //    Inner loop i=8. Break.
        //    sum1=0.
        //    `i=i-1` -> i=7.
        //    Loop `i++` -> i=8.
        //    Condition key[8]=='='? False.
        //    Output 0. Correct.

        //    So where is the bug?
        //    Maybe `num2` IS used?
        //    No.
        
        //    Ah! `num1` in the second `if` block.
        //    `num1` is reset to 0 at start of `if('+')`.
        //    But `if('-')` does NOT reset `num1` to 0 at its start!
        //    Look at the code:
        //    `if(key[i]=='+') { num1=0; ... }`
        //    `if(key[i]=='-') { ... }` -> Missing `num1=0;`!
        //    If `if('+')` is NOT entered, `num1` retains its value from previous steps?
        //    In the loop `for(i=i; ...)` , `num1` is set to 0 ONLY in the `+` block.
        //    If the first operator is `-`, `num1` is 0 (from initialization).
        //    If we have `10 + 20 - 30`.
        //    Iteration 1: `+` entered. `num1` reset to 0. Parsed 20.
        //    Then `-` entered. `num1` is currently 20.
        //    It does NOT reset `num1`.
        //    Then `for(i=i+1...` parses 30.
        //    `num1 = num1*10 + ...`
        //    So `num1` becomes `20*10 + 3`? No.
        //    The parsing loop: `for(i=i+1; key[i]<='9'...; i++) { num1=num1*10+(key[i]-'0'); }`
        //    If `num1` was 20, and we parse '3', '0':
        //    1. num1 = 20*10 + 3 = 203.
        //    2. num1 = 203*10 + 0 = 2030.
        //    Then `sum1 = sum1 - num1`.
        //    This is definitely wrong. `num1` must be reset to 0 before parsing the new number in the `-` block.
        
        //    Therefore, the error is missing `num1=0;` in the `if(key[i]=='-')` block.
        
        //    Line: `        if(key[i]=='-') {`
        //    Reason: Missing initialization of num1 to 0 before parsing the next number.
        
        //    Also, does `num2` need reset?
        //    `num2` is reset inside * and / blocks. If no * or /, it's not used.
        //    But if `num2` is not reset, and we enter * block, it accumulates?
        //    `num2=num2*10...`
        //    If `num2` was 30 from previous step, and we parse 5:
        //    30*10+5 = 305. Wrong.
        //    So `num2` MUST be reset to 0 before parsing the number for * or /?
        //    Or rather, `num2` should be reset to 0 before the inner parsing loop.
        //    In the code:
        //    `if(key[i]=='*') { for(...) { num2=num2*10... } ... num2=0; }`
        //    It resets AFTER use.
        //    If the next operation is *, `num2` is 0. Correct.
        //    If the next operation is +, `num2` is 0. Correct.
        //    So `num2` handling is OK due to post-reset.
        
        //    But `num1` in `-` block is NOT reset.
        
        //    One more thing: `if(key[i]=='+')` resets `num1=0`.
        //    `if(key[i]=='-')` DOES NOT.
        
        //    So add `num1=0;` after `if(key[i]=='-') {`.
        
        //    Are there other errors?
        //    What if `key[i]` is neither + nor -? The loop condition handles it.
        
        //    So the fix is adding `num1=0;` in the `-` block.
        
        //    Line 55: `        if(key[i]=='-') {`
        //    Annotate this line.
        
        //    Wait, is `num1` used in the `-` block parsing?
        //    Yes: `num1=num1*10+(key[i]-'0');`
        
        //    So, annotate line 55.
        
        //    Also, check line 41: `        if(key[i]=='+') {`
        //    It has `num1=0;`.
        
        //    Line 55 lacks it.
        
        //    Final check on `num2`.
        //    If I have `10 + 2 * 3 + 4 * 5 =`.
        //    1. Parse 10. sum1=10.
        //    2. i at '+'.
        //    3. `if('+')`. num1=0. Parse 2.
        //    4. Inner *. num2=0 (init). Parse 3. num2=3. num1=6. num2=0.
        //    5. sum1=16.
        //    6. `if('-')` false.
        //    7. Next i at '+'.
        //    8. `if('+')`. num1=0. Parse 4.
        //    9. Inner *. num2=0. Parse 5. num2=5. num1=20. num2=0.
        //    10. sum1=36.
        //    Correct.
        
        //    So only `num1` reset in `-` block is missing.