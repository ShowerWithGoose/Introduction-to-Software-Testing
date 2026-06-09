#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[99999999];int a[99999],n[99999];char b[99999],m[99999];
int main()
{int i,j,t,l,sum=0,temp,f=0;

gets(s);
for(i=0,j=0;s[i]!='\0';i++) 
if(s[i]!=' ')s[j++]=s[i];
s[j]='\0';//去空格 

/*for(i=0;i<=j;i++)
{printf("%c",s[i]);
}*/

j=0;
for(i=0;i<=strlen(s)-1;i++)
{if(s[i]<'0'||s[i]>'9') 
{b[j++]=s[i];}
else 
{while(s[i]>='0'&&s[i]<='9')
{a[j]=a[j]*10+s[i]-'0';i++;}
i--;
}
}l=j-1;

/*for(i=0;i<=l;i++)
printf("%d%c",a[i],b[i]);
printf("\n");//提数字与字符 */

j=0;t=0;
for(i=0;i<=l;i++)
{if (b[i]=='*'||b[i]=='/') 
   {n[j]=a[i];
      while(b[i]=='*'||b[i]=='/') 
     {if(b[i]=='*') n[j]=n[j]*a[i+1];
      else  n[j]=n[j]/a[i+1];
      i++;
     }
            i--;j++;
    }
    else  {m[t++]=b[i];n[j++]=a[i];} // @@ The logic for handling '+' and '-' is flawed. When encountering a '+' or '-', it stores the operator in `m` and the current number in `n`. However, if the previous operation was a multiplication or division, `j` was incremented. If the current operation is addition/subtraction, `j` is incremented again. This creates a mismatch in indices when calculating the final sum. Specifically, `n` array indices do not align correctly with `m` array indices for the final accumulation loop because `j` increments for every number, but `t` only increments for +/-. The structure of `n` and `m` becomes inconsistent. For example, in `10 + 20 * 30`, `n` might look like `[10, 600]` and `m` like `['+', ...]`. But in `10 + 20 + 30`, `n` is `[10, 20, 30]` and `m` is `['+', '+']`. The final loop `sum=n[0]; for(i=0;i<t-1;i++) sum+=n[i+1]` assumes `n` contains the terms to be added/subtracted sequentially. The issue is that `n` is populated by both the `if` (mult/div) and `else` (add/sub) branches. In the `if` branch, `n[j]` is set and `j` increments. In the `else` branch, `n[j]` is set and `j` increments. This part is actually okay for populating `n`. The real error is likely in how `a` and `b` are parsed or how the final loop iterates. Let's re-examine the parsing. `b` stores operators, `a` stores numbers. `l` is the last index of operators. Wait, `j` is incremented for every operator AND every number in the first parsing loop? No. `b[j++] = s[i]` happens for operators. `a[j]` is updated for numbers. So `a` and `b` share the same index `j`? No. `j` increments only when an operator is found. When a number is found, `j` does NOT increment inside the `else` block's `while` loop, but `j` is used as the index for `a`. This means `a[0]` corresponds to the first number, `b[0]` to the first operator, `a[1]` to the second number, etc. This alignment is correct.
    
    Let's trace `10 + 20 * 30 - 40 / 5 =`.
    Parsed:
    a[0]=10, b[0]='+'
    a[1]=20, b[1]='*'
    a[2]=30, b[2]='-'
    a[3]=40, b[3]='/'
    a[4]=5, b[4]='='
    l = 4 (index of '=')? No, `j` increments for `=` too. So `l=j-1` is index of `=`.
    
    Processing loop `i=0` to `l`:
    i=0: b[0]='+'. Else branch. m[0]='+', n[0]=a[0]=10. t=1, j=1.
    i=1: b[1]='*'. If branch. n[1]=a[1]=20. While b[1]=='*': n[1] = 20 * a[2] = 600. i becomes 2. Loop checks b[2]='-', stops. i-- makes i=1. j becomes 2.
    i=2: b[2]='-'. Else branch. m[1]='-', n[2]=a[2]=30. WAIT. `a[2]` was already used in the multiplication. The value 30 is still in `a[2]`, but logically it's consumed. The code uses `a[i+1]` in the mult/div step, advancing `i`. So when `i` returns to 1, the next iteration is `i=2`. At `i=2`, `b[2]` is `-`. It executes `else`. `n[2] = a[2]`. But `a[2]` is 30. This is incorrect because 30 was part of the `20*30` term. The term `20*30` resulted in 600, stored in `n[1]`. The next number to be added/subtracted should be the result of the next term. The code effectively skips `a[2]` in the `else` block? No, it reads `a[2]` again. This is double counting or using stale data.
    
    Actually, the standard way to handle this is:
    If `*` or `/`, consume numbers until `+` or `-` or end.
    The current code tries to do this but fails to advance the number index correctly relative to the operator index in the final accumulation.
    
    The specific error here is that when `*` or `/` is processed, `i` advances past the operands. When the loop continues, `i` points to the next operator. The `else` block then picks up `a[i]`? No, `a` is indexed by `j` in the first pass, but here `i` is the operator index.
    In the second pass:
    `n[j]` is used.
    When `b[i]` is `*`, `n[j] = a[i]`. Then `n[j] *= a[i+1]`. `i` increments.
    If `b[i+1]` is also `*` or `/`, it continues.
    Then `i` decrements.
    Next iteration, `i` is the index of the last `*` or `/`.
    Then `i` increments in the for loop.
    So if we had `20 * 30`, `i` starts at 1 (`*`). `n[1] = 20`. `n[1] *= 30`. `i` becomes 2. `b[2]` is `-`. Loop ends. `i` becomes 1. `j` becomes 2.
    Next for loop iteration: `i` becomes 2. `b[2]` is `-`. Else branch. `m[1] = '-'`. `n[2] = a[2]`.
    Here is the bug: `a[2]` is 30. But 30 was already used. The value 30 should not be used again. The term `20*30` is complete. The next term starts with `a[3]` (40).
    The code incorrectly associates `a[2]` with the operator at `b[2]`.
    In the expression `10 + 20 * 30 - 40 ...`, the terms are `10`, `600`, `40...`.
    The operators between terms are `+`, `-`.
    The code stores `n[0]=10`, `n[1]=600`.
    Then at `i=2` (operator `-`), it stores `n[2]=a[2]=30`. This is wrong. It should store `a[3]=40` (or the result of the next term).
    The index `i` in the second loop iterates through operators `b`.
    `a[i]` generally refers to the number *before* operator `b[i]`.
    For `b[0]` (+), number before is `a[0]`.
    For `b[1]` (*), number before is `a[1]`.
    For `b[2]` (-), number before is `a[2]`.
    But `a[2]` was the right operand of `*`.
    When we process `*`, we consume `a[1]` and `a[2]`.
    The next operator is `-` at `b[2]`. The number before it is `a[2]`? No, structurally yes, but logically `a[2]` is consumed.
    The algorithm fails to skip `a[2]` in the subsequent `else` block.
    
    To fix this properly, one usually separates the parsing of terms completely or uses a stack.
    Given the constraint to only annotate errors:
    The logic in the `else` block `n[j++]=a[i]` is incorrect when the previous operator was `*` or `/` because `a[i]` has already been consumed as the right-hand side of that multiplication/division.
    
    However, identifying a single line is tricky. The fundamental flaw is in the state management of `i` and `j` across the `if/else` blocks.
    
    Let's look at the final calculation:
    `sum=n[0]; for(i=0;i<t-1;i++) { if(m[i]=='+') sum+=n[i+1]; else sum-=n[i+1]; }`
    
    In our trace:
    n[0]=10, m[0]='+'
    n[1]=600, m[1]='-'
    n[2]=30 (Wrong, should be related to 40/5=8)
    
    If the code worked correctly:
    n[0]=10
    n[1]=600
    n[2]=8 (from 40/5)
    m[0]='+'
    m[1]='-'
    Sum = 10 + 600 - 8 = 602.
    
    The code produces 580.
    10 + 600 - 30 = 580.
    This confirms `n[2]` is incorrectly set to 30 instead of 8.
    
    The error is that the `else` block blindly takes `a[i]` without checking if `a[i]` was already consumed by a preceding `*` or `/` operation in the `if` block.
    
    Since I must annotate the source code lines:
    The line `else  {m[t++]=b[i];n[j++]=a[i];}` is where the wrong value is picked up.
    
    Also, the loop condition `i<=l` includes the `=` sign.
    When `i` reaches `=`, `b[i]` is `=`. It goes to `else`.
    `m[t++] = '='`. `n[j++] = a[last]`.
    Then the final loop runs `i < t-1`.
    If `m` contains `=`, the final loop might stop early or behave unexpectedly depending on content.
    The reference code handles `=` explicitly.
    
    The primary logical error causing the wrong answer is the reuse of consumed operands.
    
    Line: `else  {m[t++]=b[i];n[j++]=a[i];}` // @@ Logical error: 'a[i]' may have already been consumed as the right operand of a previous '*' or '/' operation handled in the 'if' block, leading to incorrect term values in 'n'.
    
    Another potential issue: `gets` is unsafe, but that's not the logic error.
    
    Let's check if there are other errors.
    The initialization of arrays `a`, `n` etc. is global, so they are zero-initialized.
    
    Is there an error in the `if` block?
    `n[j]=a[i];`
    `while(b[i]=='*'||b[i]=='/')`
    `n[j]=n[j]*a[i+1];`
    `i++;`
    
    This correctly consumes `a[i+1]`.
    But `i` is the loop variable for the `for` loop.
    When the `while` loop finishes, `i` points to the operator that stopped the loop (e.g., `-` or `=`).
    Then `i--` happens.
    Then the `for` loop does `i++`.
    So `i` returns to the operator that stopped the loop.
    The next iteration processes that operator.
    If that operator is `-`, it goes to `else`.
    It executes `n[j++]=a[i]`.
    Here `i` is the index of `-`.
    `a[i]` is the number BEFORE `-`.
    In `20 * 30 - 40`, `b[1]='*', b[2]='-'`.
    `a[1]=20, a[2]=30, a[3]=40`.
    Process `i=1` (`*`):
    `n[1]=20`. `while` sees `*`. `n[1]*=a[2]` (30). `i` becomes 2. `b[2]` is `-`. Loop ends. `i--` (1). `j++` (2).
    For loop `i++` (2).
    Process `i=2` (`-`):
    `else` branch. `m[1]='-'`. `n[2]=a[2]` (30).
    
    The code assumes `a[i]` is the start of a new term. But `a[2]` was the end of the previous term.
    The start of the new term is `a[3]`.
    
    So the code is fundamentally broken in how it maps operators to operands after a high-precedence operation.
    
    I will annotate the line where the incorrect assignment happens.
    
    One more thing: `l=j-1`. `j` counts operators.
    If input is `10+20=`, `b[0]='+', b[1]='='`. `j=2`. `l=1`.
    Loop `i=0` to `1`.
    `i=0`: `+`. Else. `m[0]='+', n[0]=10`.
    `i=1`: `=`. Else. `m[1]='=', n[1]=20`.
    Final loop: `t=2`. `i < 1`.
    `i=0`. `m[0]='+'`. `sum = n[0]+n[1] = 30`. Correct.
    
    If input `10*20=`, `b[0]='*', b[1]='='`. `l=1`.
    `i=0`: `*`. If. `n[0]=10`. `while` `*`. `n[0]*=a[1]` (20). `i` becomes 1. `b[1]` is `=`. Stop. `i--` (0). `j++` (1).
    For loop `i++` (1).
    `i=1`: `=`. Else. `m[0]='='`. `n[1]=a[1]` (20).
    Final loop: `t=1`. `i < 0`. Loop doesn't run.
    `sum=n[0]` (200). Correct.
    
    So the `=` handling is accidentally okay for simple cases because it just dumps the last number into `n`, which isn't used if `t` is small?
    Wait, if `m[0]='='`, the final loop `i<t-1` (0<0) is false. Sum is `n[0]`. Correct.
    
    Back to `10 + 20 * 30 - 40 / 5 =`.
    The error is definitely `n[2]=30` instead of `8`.
    
    I will mark the `else` line.
    
    Also, `gets` is deprecated but not a logic error for the calculation itself.
    
    One subtle thing: `a` and `b` sizes. `99999` is large enough.
    
    Final check on annotations.
    
    Line: `else  {m[t++]=b[i];n[j++]=a[i];}` // @@ Logic Error: When this block executes after a '*' or '/' sequence, 'a[i]' refers to the number that was already consumed as the right operand of the multiplication/division. It should refer to the next unused number, but the index 'i' (derived from operator position) incorrectly points back to the consumed number.

    Are there any other errors?
    The problem states integer division. C performs integer division for ints. Correct.
    
    I will provide the annotated code.