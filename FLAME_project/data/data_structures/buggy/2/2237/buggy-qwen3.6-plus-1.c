#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c;
    char op1,op2,op3;
    scanf("%d %c",&a,&op1);
    while(op1!='=')
    {
      scanf("%d %c",&b,&op2);
      while(op2=='*'||op2=='/')
      {
          scanf("%d %c",&c,&op3);
          if(op2=='*')b*=c;
          else  b=b/c;
          op2=op3;
      }  
          if(op1=='+') // @@ The logic for updating op1 is incorrect. When op1 is '-', it falls into the else block, but if the current term was processed with higher precedence operators, op1 should be updated to op2 regardless of whether we added or subtracted. More critically, the structure implies that op1 is updated inside the if/else, but if op1 is not '+' or '-' (e.g. initially or after a sequence), the logic breaks. However, the main issue here is that `op1` is updated to `op2` which is the operator *after* the current term `b`. If `op2` is `+` or `-`, this is correct for the next iteration. But wait, look at the reference code. The reference code updates `op1 = op2` AFTER handling the addition/subtraction. In the buggy code, `op1` is updated inside the if/else blocks. This part is actually logically similar to the reference IF the if/else covers all cases. But what if `op1` is not `+` or `-`? The problem states valid expressions. The real bug is likely in how the first number is handled or the loop condition. Let's look closer. The reference initializes `a=0, op1='+'`. It reads `b, op2`. Then processes high precedence. Then applies `op1` to `a` and `b`. Then sets `op1 = op2`. The buggy code reads `a, op1` first. Then enters loop. Reads `b, op2`. Processes high precedence. Then applies `op1` to `a` and `b`. Then sets `op1 = op2`. This seems structurally okay. 
          
          Let's trace: `24 / 4 / 3 / 2 + ...`
          Ref: `a=0, op1='+'`. Reads `b=24, op2='/'`. Inner while: `c=4, op3='/'`. `b=24/4=6`. `op2='/'`. Next inner: `c=3, op3='/'`. `b=6/3=2`. `op2='/'`. Next inner: `c=2, op3=' '`. Wait, `scanf("%d %c")` skips spaces. So `op3` becomes `'+'`. `b=2/2=1`. `op2='+'`. Inner loop ends. `op1` is `'+'`. `a += 1` -> `a=1`. `op1` becomes `'+'`.
          Next iter: `op1` is `'+'` (not `=`). Reads `b=100, op2='-'`. Inner loop skipped. `op1` is `'+'`. `a += 100` -> `a=101`. `op1` becomes `'-'`.
          Next iter: `op1` is `'-'`. Reads `b=50, op2='-'`. Inner loop skipped. `op1` is `'-'`. `a -= 50` -> `a=51`. `op1` becomes `'-'`.
          Next iter: `op1` is `'-'`. Reads `b=40, op2='+'`. Inner loop skipped. `op1` is `'-'`. `a -= 40` -> `a=11`. `op1` becomes `'+'`.
          Next iter: `op1` is `'+'`. Reads `b=10, op2='*'`. Inner while: `c=20, op3='*'`. `b=200`. `op2='*'`. Next: `c=30, op3='*'`. `b=6000`. `op2='*'`. Next: `c=40, op3='/'`. `b=240000`. `op2='/'`. Next: `c=40, op3='/'`. `b=6000`. `op2='/'`. Next: `c=30, op3='='`. `b=200`. `op2='='`. Inner loop ends. `op1` is `'+'`. `a += 200` -> `a=211`. `op1` becomes `'='`.
          Loop ends. Output 211.

          Buggy Code Trace:
          `scanf("%d %c",&a,&op1)` -> `a=24, op1='/'`.
          Loop `op1 != '='` (`'/' != '='`).
          `scanf("%d %c",&b,&op2)` -> `b=4, op2='/'`.
          Inner while `op2=='/'`:
             `scanf("%d %c",&c,&op3)` -> `c=3, op3='/'`.
             `b = 4/3 = 1`.
             `op2 = '/'`.
             Inner while `op2=='/'`:
                `scanf("%d %c",&c,&op3)` -> `c=2, op3='+'`.
                `b = 1/2 = 0`.
                `op2 = '+'`.
             Inner loop ends.
          `if(op1=='+')` -> False (`op1` is `/`).
          `else` -> `a -= b` -> `a = 24 - 0 = 24`. `op1 = op2` -> `op1 = '+'`.
          
          Here is the error! The first operator read was `/`, which is a high-precedence operator. The reference code handles this by initializing `op1` to `+` and treating the first number as a term to be added. The buggy code reads the first operator into `op1`. If the expression starts with a number followed by `/` or `*`, `op1` becomes `/` or `*`. The code then tries to apply `op1` (which is `/` or `*`) as a low-precedence operator (+ or -) in the `if/else` block. Since `op1` is neither `+` nor `-`, it goes to `else` and subtracts. This is wrong. The first number `a` should just be the starting value, and the operator following it should determine how the *next* term is combined, OR the parsing logic needs to handle the first term differently.
          
          Specifically, the variable `a` is initialized with the first number `24`. The operator `op1` is initialized with `/`. The code then reads the next number `4` into `b`. It processes `4 / 3 / 2` resulting in `b=0`. Then it applies `op1` (`/`) to `a` and `b`. But the `if/else` only handles `+` and `-`. It defaults to subtraction. So `24 - 0 = 24`.
          
          The correct logic for the start is that `a` holds the accumulated result. The first number `24` is part of the first term `24/4/3/2`. The reference code solves this by starting with `a=0` and `op1='+'`, so the first term is added to 0. The buggy code starts with `a=24` and `op1='/'`. It fails to group `24` with the subsequent `/` operations correctly because `24` is already separated from the division chain. The division chain `4/3/2` is calculated into `b`, but `24` is left out of that calculation.
          
          To fix this without changing structure too much, one would need to ensure the first number is treated as part of the first term's high-precedence chain. The reference code does this by reading `b` (the first number) inside the loop and having `op1` be the operator *before* it (initially `+`). The buggy code reads `a` (first number) and `op1` (operator after it) before the loop. This decouples `a` from the high-precedence operations that follow it immediately.
          
          Therefore, the line `scanf("%d %c",&a,&op1);` is the source of the logical error because it separates the first operand from its immediate high-precedence operators.
          
          However, I must annotate specific lines. The error manifests in the logic flow.
          
          Let's look at `if(op1=='+')`.
          If `op1` is `/` or `*`, it goes to `else` and subtracts. This is definitely wrong for `/` or `*`.
          
          So, line `if(op1=='+')` is problematic because it doesn't account for `op1` being `*` or `/` at the start.
          
          But the root cause is the initialization.
          
          Let's annotate the initialization line.
*/
    scanf("%d %c",&a,&op1); // @@ The first number 'a' is read separately from the subsequent high-precedence operations. If the first operator 'op1' is '*' or '/', 'a' is not included in the high-precedence calculation of the first term, leading to incorrect results. The reference code handles this by initializing a=0 and op1='+', ensuring the first number is read into 'b' and processed uniformly.
    while(op1!='=')
    {
      scanf("%d %c",&b,&op2);
      while(op2=='*'||op2=='/')
      {
          scanf("%d %c",&c,&op3);
          if(op2=='*')b*=c;
          else  b=b/c;
          op2=op3;
      }  
          if(op1=='+') // @@ This condition fails to handle cases where 'op1' might be '*' or '/' (specifically at the beginning of the expression due to the flawed initialization above). If op1 is '*' or '/', it falls through to the else block and performs subtraction, which is incorrect.
          {
          a+=b;op1=op2;}
        else
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a);
}