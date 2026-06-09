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
            if(x=='+') a=a+b; // @@ [This uses the previous operator 'x' instead of the current term's sign. However, when '=' is encountered immediately after reading a number (e.g., at the end), the last number 'b' hasn't been applied with its correct preceding operator because the code only applies '+' or '-' when it sees the next '+'/'-' or '='. But in this implementation, the final term is added/subtracted based on 'x', which is the operator before the last term. However, the real issue is that the logic does not correctly handle operator precedence in all cases due to flawed control flow. Specifically, after processing a * or / chain, if the next operator is '=', the code jumps to the '=' block and uses 'x' (which is the operator before the current term 'b'), but 'b' may have been updated by * or / and should be combined with 'a' using the operator that preceded this entire term — which is actually stored in 'x'. So this line seems logically okay. The actual bug lies earlier.]

            else if(x=='-') a=a-b; // @@ [Same as above — this part is actually correct in logic. The real error is that after processing multiplication/division, if the next character is '=', the program doesn't go through the '+'/'-' block, so it never updates 'x' to reflect the operator before the current term. But wait: 'x' is only updated in the '+'/'-' block. So if the expression ends with a term that was preceded by '+' or '-', then 'x' holds that operator. However, consider the input: 10 + 20 * 30 - 40 / 5 =. Let's trace:

Initial: a=0, x='+'
Read b=10, y='+'
Enter loop:
  y is '+', so enter '+'/'-' block:
    since y=='+', a = 0+10 = 10
    x = '+'
    scanf -> b=20, y='*'

Next iteration:
  y='*' → process *: read c=30, z='-', b = 20*30=600, y becomes '-'
  Now y='-', so enter '+'/'-' block:
    since y=='-', a = 10 - 600 = -590
    x = '-'
    scanf -> b=40, y='/'

Next iteration:
  y='/' → process /: read c=5, z='=', b=40/5=8, y becomes '='
  Now check: y is '=', so go to '=' block:
    x is '-', so a = -590 - 8 = -598 → which matches buggy output.

But expected is 10 + (20*30) - (40/5) = 10 + 600 - 8 = 602.

So the error is: when we process "20 * 30", we get b=600, and then y becomes '-', and then we immediately apply a = a - b → which is 10 - 600. But that is wrong! Because the '-' belongs to the next term, not to the result of 20*30.

Wait — no: in "10 + 20 * 30 - 40 / 5", the structure is:
term1: 10 (preceded by implicit '+')
term2: + (20*30)
term3: - (40/5)

So after reading "10 +", we store a=10, then read "20 * 30", compute b=600, and then see that the next operator is '-', which means term2 is +600, and now we are starting term3 with operator '-'.

But in the code, when y becomes '-' (after processing *), it enters the '+'/'-' block and does: a = a - b → which is 10 - 600. That’s wrong! It should be a = a + b (because the operator before term2 was '+'), and then set x='-' for the next term.

The bug is: the code uses the **current** operator y (which is the operator **after** the current term) to decide how to combine the current term into 'a'. But it should use the **previous** operator (stored in 'x') to combine the current term, and then update 'x' to y for the next term.

In the reference program, they do:
- Read a number b and next char y.
- Process any * or / immediately (so b becomes the full term value).
- Then, use the **previous operator x** (which is the operator before this term) to update 'a'.
- Then set x = y (the operator after this term, which will be the previous operator for the next term).

But in the buggy code:
- After processing * or /, if y is '+' or '-', it uses **y** (the upcoming operator) to update 'a', which is incorrect. It should use the **previous operator** (which should be stored separately).

Actually, looking again: in the buggy code, variable 'x' is intended to store the previous operator. But when does it get updated?

Initially: x='+'
Then, when we read "10 +" → y='+', so in the '+'/'-' block:
  it does: if(y=='+') a = a + b → uses y, not x!
  then sets x = y.

So it's using the current operator y to apply to the current term b, which is correct **only if** b is the term that comes after that operator. But in reality, the operator y comes **after** b, so b is the term that should be combined using the **previous** operator.

Wait — standard approach: expressions are of the form: [term0] [op1 term1] [op2 term2] ...
We start with term0, and op1 tells us how to combine term1.

But in left-to-right parsing without parentheses, we can think of it as:
result = term0
then for each (operator, term): result = result operator term

But that ignores precedence.

Correct approach with precedence: treat + and - as separators between terms, where each term is a product/division chain.

So: parse the expression as a sequence of terms separated by + or -, and each term is evaluated with * and /.

Thus, we should:
- Start with first term (which may include * and /)
- Then, for each subsequent + or - followed by a term (with * and /), add or subtract that term.

Therefore, the operator that precedes a term determines whether to add or subtract it.

In the input "10 + 20 * 30 - 40 / 5 =", the terms are:
+10
+ (20*30)
- (40/5)

So when we read the first number 10, we don't know its sign yet — but by convention, it's positive.

Then we read '+', which means the next term is positive.
Then we read '20', then see '*', so we compute the whole term: 20*30=600, then see '-', which means this term (600) is positive (because preceded by '+'), so we add it. Then '-' means next term is negative.

So the algorithm should:
- Have a running total 'a'
- Have a current term 'b'
- Have a current operator for the term (initially '+')
- Read a number into b
- While next operator is * or /, fold it into b
- Then, apply the current term operator (stored in 'x') to add/subtract b to 'a'
- Then, read the next operator (which will be the operator for the next term) into 'x'

This is exactly what the reference program does.

Now, in the buggy code:

It reads first number b=10, y='+'
Then, since y is '+', it enters the '+'/'-' block and does: a = a + b → a=10, then sets x='+', then reads next number: b=20, y='*'

Then, since y='*', it processes: reads c=30, z='-', b=600, y='-'

Now, y='-', so it enters '+'/'-' block: does a = a - b → 10 - 600 = -590, sets x='-', reads next: b=40, y='/'

Then, y='/', processes: reads c=5, z='=', b=8, y='='

Then, since y='=', it does: if(x=='-') a = a - b → -590 -8 = -598.

The mistake is: when it processed the term "20*30" and got b=600, and saw that the next operator is '-', it should have **added** 600 to 'a' (because the operator before this term was '+'), and then remembered that the next term will be subtracted.

But in the buggy code, when it sees y='-', it assumes that the current term b=600 should be subtracted, which is wrong — the '-' applies to the **next** term, not the current one.

So the error is in the logic of when to apply the operator.

Specifically, in the buggy code, the '+'/'-' block is entered when y is '+' or '-', and it uses **y** to decide how to combine b into a. But **y** is the operator that comes **after** b, so b should be combined using the **previous** operator (which should be stored in 'x'), not y.

But in the buggy code, 'x' is only updated **after** applying y. And initially, 'x' is '+', but the first application uses y, not x.

So the core error is: the code uses the **next** operator (y) to apply to the current term (b), instead of using the **previous** operator (which should be stored in x).

Therefore, the fix would be to use 'x' to apply the current term, then set x = y for the next term.

But in the current buggy code, look at the first application:

After reading b=10, y='+', it does:
  if(y=='+') a = a + b → uses y

But it should use x (which is '+') to apply b, then set x = y.

So the error is in the '+'/'-' block: it should use 'x', not 'y'.

But wait — at the very beginning, x is '+', and the first term is 10, so we want to do a = 0 + 10. So if we used x, that would be correct.

Then, after that, we set x = y (which is '+'), and read next b and y.

Then, when we process the next term (20*30=600), and then see y='-', we should use x (which is '+') to add 600, then set x = '-'.

But in the buggy code, when y='-', it uses y to subtract, which is wrong.

So the error is in these lines:

In the '+'/'-' block:
            if(y=='+') a=a+b;
            else if(y=='-') a=a-b;

It should be:
            if(x=='+') a=a+b;
            else if(x=='-') a=a-b;

Similarly, in the '=' block, it correctly uses 'x'.

But in the '+'/'-' block, it incorrectly uses 'y'.

Therefore, the errors are on these two lines:

            if(y=='+') a=a+b; // @@ [Should use 'x' (the operator before the current term) instead of 'y' (the operator after the current term). Using 'y' causes the current term to be combined with the wrong sign.]

            else if(y=='-') a=a-b; // @@ [Same error: should use 'x' instead of 'y'.]

Additionally, note that after processing * or /, if the next character is '+' or '-', the code enters the '+'/'-' block and uses y, which is incorrect.

Also, there's another subtle issue: what if after processing * or /, the next character is '='? Then it goes to the '=' block and uses 'x', which is correct. But the problem is that 'x' was never updated to reflect the operator before the current term.

How is 'x' updated? Only in the '+'/'-' block: x = y.

But the operator before the current term is actually the last '+' or '-' that was encountered **before** this term.

In the reference program, they always use the previous operator (x) to apply the current term (b), then set x to the next operator (y).

In the buggy code, the first term is handled by reading b and y, then if y is '+' or '-', it uses y to apply b — which is wrong because y is after b.

So to align with the reference, the buggy code should:

- Use 'x' to apply the current term b (after processing * and /)
- Then, if y is '+' or '-', set x = y and read next b and y
- If y is '=', apply using x and break

But in the current structure, the first term is read outside the loop, and then inside the loop, it checks y.

The fundamental flaw is using 'y' instead of 'x' in the '+'/'-' block.

Therefore, the two lines in the '+'/'-' block that use 'y' are erroneous.

Let's annotate them.
            
            x=y;
            scanf("%d %c",&b,&y);
        }
        if(y=='=')
        {
            if(x=='+') a=a+b;
            else if(x=='-') a=a-b;
            
            printf("%d\n",a);
            break;
        }
    }
    return 0;
}