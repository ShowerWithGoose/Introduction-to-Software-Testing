#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*思路：计算两个加减之间乘除的个数，先算乘除再算加减*/
void chu_kong_ge(char* expression, char* result);//除空格
long long ji_suan(long long a, long long b, char op);//计算加减乘除

int main() {
    char expression[1000], temp[1000] = "\0";
    gets(expression);
    chu_kong_ge(expression, temp);//已经除去空格

    int len = strlen(temp);
    long long jishu = 0; char op[1000] = "\0";
    long long jie_guo = 0;
    long long number_before = 0, number_after = 0;//乘除符号左右两边的数

    for (int i = 0; i < len; i++) {
        if (temp[i] == '+' || temp[i] == '-') {
            op[i] = temp[i];
            //设计一个计数器，读取+-之间的乘除个数
            jishu = 0;
            for (int j = i + 1; j < len && temp[j] != '+' && temp[j] != '-'; j++) {
                if (temp[j] == '*' || temp[j] == '/')jishu++;
            }//注意i没变

            if (jishu == 0)//连加或连减
            {
                int j;
                number_before = jie_guo;
                for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '='; j++) {
                    number_after = number_after * 10 + temp[j] - '0';
                }
                jie_guo = ji_suan(number_before, number_after, op[i]);

                i = j - 1;//i在这里变了
                number_after = 0;
            }

            else if (jishu)//中间有乘除
            {
                long long j, count = jishu, cheng_chu_result = 0, k = i;

                while (jishu--) //乘除内运算
                {
                    if (jishu == count - 1) //第一次需要先对num_before赋值
                    {
                        for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                            number_before = number_before * 10 + temp[j] - '0';
                        }
                    }
                    i = j;//i在这里变了,为了更新op[i]
                    op[i] = temp[j];
                    for (j++; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                        number_after = number_after * 10 + temp[j] - '0';
                    }
                    cheng_chu_result = ji_suan(number_before, number_after, op[i]);
                    i = j;
                    op[i] = temp[j];

                    number_before = cheng_chu_result;//将前一次运算得到的结果作为下一次的左数
                    number_after = 0;
                }

                jie_guo = ji_suan(jie_guo, number_before, op[k]);
                i = j - 1;
                number_before = 0;

            }
        }

        else if (temp[i] == '*' || temp[i] == '/') {
            //设计一个计数器，读取+-之间的乘除个数
            jishu = 0;
            for (int j = i; j < len && temp[j] != '+' && temp[j] != '-'; j++) {
                if (temp[j] == '*' || temp[j] == '/')jishu++;
            }//注意i没变

            long long j, count = jishu, cheng_chu_result = 0, k = i;

            while (jishu--) //乘除内运算
            {
                if (jishu == count - 1) //第一次需要先对num_before赋值
                {
                    for (j = 0; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) { // @@ The starting index for parsing the first number in a leading multiplication/division sequence should be 0, but this logic is flawed because it doesn't reset number_before to 0 before accumulation, and more importantly, if this block is entered, it implies the expression starts with * or /, which is invalid per problem description, OR it handles the case where the first term involves multiplication. However, the main issue is that `number_before` retains its value from previous iterations if not reset. In the specific failing case `24 / 4 ...`, the code enters this block at i=0? No, temp[0] is '2'. It enters the `else` block. Wait. The logic for handling the *first* term of the expression is distributed. If the expression starts with a number, it goes to `else`. If it starts with *, it goes here. The test case starts with `24`. So it goes to `else`. `jie_guo` becomes 24. Then i=1, `else` -> 24*10+4 = 244. This is wrong. The `else` block accumulates digits into `jie_guo` directly, which is incorrect for multi-digit numbers if they are part of a larger expression structure handled later. Actually, the `else` block just builds the current number into `jie_guo`. When it hits `/` at index 2, it enters the `else if (temp[i] == '*' || temp[i] == '/')` block.
                    
                    // The critical error here is that `number_before` is not initialized to 0 before the loop `for (j = 0; ...)` starts accumulating. 
                    // But more fundamentally, the logic `for (j = 0; ...)` scans from the beginning of the string every time? No, `j` is local.
                    // The real issue in this branch: `number_before` is used to store the left operand.
                    // In the test case `24 / 4 ...`, when i=2 ('/'), we enter this block.
                    // `jishu` counts operators.
                    // Inside `while(jishu--)`:
                    // `if (jishu == count - 1)`: True.
                    // `for (j = 0; ...)` parses digits from start. `number_before` becomes 24.
                    // `i = j` (i becomes 2). `op[i] = temp[2]` ('/').
                    // `for (j++; ...)` parses next number. `number_after` becomes 4.
                    // `cheng_chu_result = 24 / 4 = 6`.
                    // `number_before = 6`.
                    // Loop continues for next `/`.
                    // `if (jishu == count - 1)`: False.
                    // `i = j` (i is at index after 4, which is 4? No, j stopped at 4. temp[4] is '/').
                    // `op[i] = temp[4]` ('/').
                    // `for (j++; ...)` parses next number. `number_after` becomes 3.
                    // `cheng_chu_result = 6 / 3 = 2`.
                    // `number_before = 2`.
                    // Loop ends.
                    // `jie_guo = number_before` -> `jie_guo = 2`.
                    // This seems correct for the first part `24/4/3`.
                    
                    // Let's look at the next part: `/ 2 + 100 ...`.
                    // After processing the first block, `i` is updated to `j - 1`.
                    // The outer loop increments `i`.
                    // The next operator is `+`.
                    // It enters `if (temp[i] == '+' || temp[i] == '-')`.
                    // It calculates `jishu` for the segment `100 - 50 - 40 + 10*20*30*40 / 40 / 30`.
                    // Wait, the segment stops at next `+` or `-`.
                    // So for `+ 100`, `jishu` is 0.
                    // It goes to `if (jishu == 0)`.
                    // `number_before = jie_guo` (which is 2).
                    // Parses `100`. `number_after = 100`.
                    // `jie_guo = ji_suan(2, 100, '+')` -> 102.
                    // Correct so far.
                    
                    // Next `- 50`. `jishu` 0.
                    // `number_before = 102`.
                    // Parses `50`.
                    // `jie_guo = 102 - 50 = 52`.
                    
                    // Next `- 40`. `jishu` 0.
                    // `number_before = 52`.
                    // Parses `40`.
                    // `jie_guo = 52 - 40 = 12`.
                    
                    // Next `+ 10*20*30*40 / 40 / 30`.
                    // Enters `if (+/-)`.
                    // `jishu` counts `*` and `/`. There are 3 `*` and 2 `/`. Total 5.
                    // Enters `else if (jishu)`.
                    // `k = i` (index of `+`).
                    // `while (jishu--)`:
                    // 1st iter (`jishu` was 5, now 4, `count-1` is 4? No, `count` is 5. `count-1` is 4. `jishu` is 4. Match.):
                    // Parses first number after `+`. `10`. `number_before = 10`.
                    // `i` updates. `op[i]` is `*`.
                    // Parses `20`. `number_after = 20`.
                    // `result = 200`. `number_before = 200`.
                    // 2nd iter (`jishu` 3):
                    // `i` updates. `op[i]` is `*`.
                    // Parses `30`. `number_after = 30`.
                    // `result = 6000`. `number_before = 6000`.
                    // 3rd iter (`jishu` 2):
                    // `i` updates. `op[i]` is `*`.
                    // Parses `40`. `number_after = 40`.
                    // `result = 240000`. `number_before = 240000`.
                    // 4th iter (`jishu` 1):
                    // `i` updates. `op[i]` is `/`.
                    // Parses `40`. `number_after = 40`.
                    // `result = 6000`. `number_before = 6000`.
                    // 5th iter (`jishu` 0):
                    // `i` updates. `op[i]` is `/`.
                    // Parses `30`. `number_after = 30`.
                    // `result = 200`. `number_before = 200`.
                    // Loop ends.
                    // `jie_guo = ji_suan(jie_guo, number_before, op[k])`.
                    // `jie_guo` was 12. `op[k]` is `+`. `number_before` is 200.
                    // `jie_guo = 12 + 200 = 212`.
                    
                    // Expected output is 211.
                    // Let's re-calculate manually:
                    // 24 / 4 / 3 / 2 = 1
                    // 1 + 100 = 101
                    // 101 - 50 = 51
                    // 51 - 40 = 11
                    // 10 * 20 * 30 * 40 / 40 / 30 = 200
                    // 11 + 200 = 211.
                    
                    // My trace got 212. Where is the off-by-one?
                    // Ah, `24 / 4 / 3 / 2`.
                    // Trace:
                    // `24` parsed in `else` block?
                    // i=0 ('2'): `else` -> `jie_guo = 2`.
                    // i=1 ('4'): `else` -> `jie_guo = 24`.
                    // i=2 ('/'): Enters `else if (* or /)`.
                    // `jishu` counts `/` at 2, `/` at 4, `/` at 6. Count = 3.
                    // `while (jishu--)`:
                    // 1st iter (`jishu` 2, `count-1` 2. Match):
                    // `for (j=0...)` parses `24`. `number_before = 24`.
                    // `i=2`. `op[2]='/'.`
                    // `j++` (3). Parses `4`. `number_after = 4`.
                    // `res = 6`. `number_before = 6`.
                    // 2nd iter (`jishu` 1):
                    // `i=j` (4). `op[4]='/'.`
                    // `j++` (5). Parses `3`. `number_after = 3`.
                    // `res = 2`. `number_before = 2`.
                    // 3rd iter (`jishu` 0):
                    // `i=j` (6). `op[6]='/'.`
                    // `j++` (7). Parses `2`. `number_after = 2`.
                    // `res = 1`. `number_before = 1`.
                    // Loop ends.
                    // `jie_guo = number_before` -> `jie_guo = 1`.
                    // `i = j - 1` -> `i = 7`.
                    // Loop increments `i` to 8.
                    // temp[8] is `+`.
                    // Enters `if (+/-)`.
                    // `number_before = jie_guo` (1).
                    // Parses `100`.
                    // `jie_guo = 1 + 100 = 101`.
                    // ...
                    // `101 - 50 = 51`.
                    // `51 - 40 = 11`.
                    // `11 + 200 = 211`.
                    
                    // So the logic *should* produce 211. Why did it produce 102211?
                    // The provided buggy output is 102211.
                    // Let's look at `number_before` and `number_after` initialization.
                    // They are declared outside the loop.
                    // In the `else if (* or /)` block:
                    // `number_before` is NOT reset to 0 before `for (j=0...)`.
                    // If `number_before` had a value from previous iteration, it would be corrupted.
                    // However, in the first step, `number_before` is 0.
                    // In the `else` block (parsing initial number), `jie_guo` is built up. `number_before` is untouched (0).
                    // So for the first division block, `number_before` starts at 0.
                    // `number_before = 0 * 10 + 2 = 2`.
                    // `number_before = 2 * 10 + 4 = 24`.
                    // This works.
                    
                    // What about `number_after`?
                    // It is reset to 0 inside the `while` loop at the end: `number_after = 0;`.
                    
                    // Is there an issue with `op` array?
                    // `char op[1000] = "\0";`
                    
                    // Let's look at the `else` block again.
                    // `else //出现数字`
                    // `{`
                    // `    jie_guo = jie_guo * 10 + temp[i] - '0';`
                    // `}`
                    // This assumes that if we encounter a digit, it's part of a number that hasn't been processed by an operator yet.
                    // This works for the very first number.
                    
                    // However, consider the case where we have `100` after `+`.
                    // The `+` handler parses `100` explicitly in the `if (jishu == 0)` block.
                    // It sets `i = j - 1`.
                    // The loop increments `i`.
                    // So the digits of `100` are NOT visited by the `else` block in the main loop.
                    
                    // So where does the error come from?
                    // Look at `number_before` in the `else if (* or /)` block.
                    // `number_before` is not reset to 0 at the start of the block.
                    // If this block is entered a second time, `number_before` still holds the value from the previous calculation.
                    // In the trace:
                    // 1. `24/4/3/2`. `number_before` ends as 1. `jie_guo` becomes 1.
                    // 2. `+100`. `jie_guo` becomes 101.
                    // 3. `-50`. `jie_guo` becomes 51.
                    // 4. `-40`. `jie_guo` becomes 11.
                    // 5. `+10*...`. Enters `if (+/-)`. `jishu > 0`.
                    // Inside `else if (jishu)`:
                    // `number_before` is NOT reset to 0. It is still 0?
                    // In step 1, `number_before` was modified.
                    // In step 2, 3, 4 (`jishu==0`), `number_before` is set to `jie_guo` temporarily, but `number_after` is parsed. `number_before` is not explicitly reset to 0 at the end of `jishu==0` block.
                    // Wait, in `jishu==0`:
                    // `number_before = jie_guo;`
                    // ...
                    // `jie_guo = ji_suan(...)`
                    // `number_after = 0;`
                    // `number_before` is NOT reset.
                    // So before step 5, `number_before` holds the value from step 4?
                    // In step 4: `number_before = jie_guo` (51). `number_after = 40`. `jie_guo = 11`.
                    // `number_before` is still 51.
                    
                    // Now step 5: `+10*...`.
                    // Enters `else if (jishu)`.
                    // `while (jishu--)`:
                    // 1st iter: `if (jishu == count - 1)`.
                    // `for (j = i + 1; ...)` parses `10`.
                    // `number_before = number_before * 10 + ...`
                    // `number_before` was 51.
                    // `number_before = 51 * 10 + 1 = 511`.
                    // `number_before = 511 * 10 + 0 = 5110`.
                    // This is the bug! `number_before` is not reset to 0 before parsing the new number.
                    
                    // Same issue in `else if (* or /)` block?
                    // Yes, `number_before` is not reset.
                    
                    // So, `number_before` needs to be reset to 0 before parsing a new number in these blocks.
                    
                    // Specifically:
                    // Line 83: `for (j = i + 1; ...)` uses `number_before`.
                    // Line 109: `for (j = 0; ...)` uses `number_before`.
                    
                    // In the `else if (jishu)` block (line 73), before the `while` loop, or inside the `if` before parsing.
                    // In the `else if (* or /)` block (line 96), before the `while` loop, or inside the `if` before parsing.
                    
                    // Also, in the `jishu == 0` block, `number_after` is reset, but `number_before` is not. It's overwritten by `jie_guo`, so it's fine there.
                    
                    // The fix is to reset `number_before = 0` before parsing it in the multiplication/division blocks.
                    
                    // Line 83 is inside `if (jishu == count - 1)`.
                    // We should add `number_before = 0;` before the loop at line 83.
                    // And line 109 is inside `if (jishu == count - 1)`.
                    // We should add `number_before = 0;` before the loop at line 109.
                    
                    // Are there other places?
                    // `number_after` is reset at the end of the `while` loop.
                    
                    // Let's check the annotated lines.
                    
                    // Line 83:
                    // for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                    //     number_before = number_before * 10 + temp[j] - '0';
                    // }
                    // @@ number_before is not reset to 0 before accumulating digits, causing it to use the stale value from previous calculations.
                    
                    // Line 109:
                    // for (j = 0; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                    //     number_before = number_before * 10 + temp[j] - '0';
                    // }
                    // @@ number_before is not reset to 0 before accumulating digits, causing it to use the stale value from previous calculations.
                    
                    // One more thing: `number_after` might also need resetting if it's not guaranteed to be 0.
                    // In the `while` loop, `number_after = 0;` is at the end.
                    // But what if the loop doesn't run? Or before the first parse?
                    // `number_after` is parsed in the inner `for` loop.
                    // It is reset at the end of `while`.
                    // So for the next iteration, it is 0.
                    // For the first iteration, it is 0 (initialized at start of main).
                    // So `number_after` is fine.
                    
                    // `number_before` is the problem.
                    
                    // Therefore, the errors are at lines 83 and 109 (conceptually, before the accumulation).
                    // Since I must annotate the line itself, I will annotate the `for` loops where `number_before` is accumulated.
                    
                    // Note: The line numbers in the provided source might differ slightly from my analysis if I counted incorrectly, but I will map them to the provided source.
                    
                    // Line 83 in provided source:
                    //                         for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                    
                    // Line 109 in provided source:
                    //                     for (j = 0; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                    
                    // These are the lines.
                }
                i = j;//i在这里变了,为了更新op[i]
                op[i] = temp[j];
                for (j++; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                    number_after = number_after * 10 + temp[j] - '0';
                }
                cheng_chu_result = ji_suan(number_before, number_after, op[i]);
                i = j;
                op[i] = temp[j];

                number_before = cheng_chu_result;//将前一次运算得到的结果作为下一次的左数
                number_after = 0;
            }

            jie_guo = ji_suan(jie_guo, number_before, op[k]);
            i = j - 1;
            number_before = 0;

        }
    }

    else if (temp[i] == '*' || temp[i] == '/') {
        //设计一个计数器，读取+-之间的乘除个数
        jishu = 0;
        for (int j = i; j < len && temp[j] != '+' && temp[j] != '-'; j++) {
            if (temp[j] == '*' || temp[j] == '/')jishu++;
        }//注意i没变

        long long j, count = jishu, cheng_chu_result = 0, k = i;

        while (jishu--) //乘除内运算
        {
            if (jishu == count - 1) //第一次需要先对num_before赋值
            {
                for (j = 0; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) { // @@ number_before is not reset to 0 before accumulating digits, causing it to use the stale value from previous calculations.
                    number_before = number_before * 10 + temp[j] - '0';
                }
            }
            i = j;//i在这里变了,为了更新op[i]
            op[i] = temp[j];
            for (j++; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                number_after = number_after * 10 + temp[j] - '0';
            }
            cheng_chu_result = ji_suan(number_before, number_after, op[i]);
            i = j;
            op[i] = temp[j];

            number_before = cheng_chu_result;//将前一次运算得到的结果作为下一次的左数
            number_after = 0;
        }

        jie_guo = number_before;
        i = j - 1;
        number_before = 0;
    }
    else if (temp[i] == '=') {
        printf("%lld", jie_guo);
    }
    else //出现数字
    {
        jie_guo = jie_guo * 10 + temp[i] - '0';
    }
}
return 0;
}

void chu_kong_ge(char* expression, char* result) {
    long long i = 0;
    long long j = 0;
    while (expression[i]) {
        if (expression[i] != ' ') {
            result[j++] = expression[i];
        }
        i++;
    }
    result[j] = '\0';
}

long long ji_suan(long long a, long long b, char op) {
    long long result = 0;
    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    return result;
}