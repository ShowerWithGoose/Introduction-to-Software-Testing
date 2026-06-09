#include <stdio.h>
#include <ctype.h>
int main(void){
    char s1[1000],s[1000],op[1000],op2[1000];
    int num[1000],value,num2[1000];
    gets(s1);
    int k=0;
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]!=' '){
            s[k]=s1[i];
            k++;
        }
    }
    s[k]='\0';
    int m=0,q=0;
    do{
        value=0;
        while(isdigit(s[m])){
            value=value*10+s[m]-'0';
            m++;
        }
        num[q]=value;
        op[q]=s[m];
        m++;
        q++;
    }while(op[q-1]!='=');
    int p=0,h=0;
    num2[0]=num[0]; // @@ The initialization of num2[0] is incorrect for the logic that follows. If the first operator is * or /, num2[0] should be the result of that operation, not just num[0]. Also, p is not incremented here, but used as an index later.
    for(int i=0;i<q-1;i++){
        if((op[i]=='+')||(op[i]=='-')){
            op2[h]=op[i];
            h++;
            if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){
                num2[p]=num[i]; // @@ Logic error: When encountering + or -, if the previous term was a standalone number (not part of a * or / chain), it should be stored. However, the indexing and state management of p and num2 are flawed. Specifically, if i=0 and op[0] is +, num2[0] is overwritten with num[0] (which is correct value but wrong logic flow if mixed with * later). More critically, if the expression starts with a number followed by *, this block doesn't handle the accumulation into num2 correctly relative to the * block.
            }
            p++; // @@ p is incremented here, meaning num2[p] points to the next slot. This implies num2 stores operands for +/-.
        }
        if((op[i]=='*')||(op[i]=='/')){
            if((op[i-1]=='+')||(op[i-1]=='-')||(i==0)){
                if(op[i]=='*'){
                    num2[p]=num[i]*num[i+1]; // @@ Error: If i=0, we calculate num[0]*num[1]. This result is stored in num2[p]. But p was initialized to 0. If the previous block didn't run (because op[0] is *), p is still 0. So num2[0] becomes the product. This seems okay for the first term.
                }else{
                    num2[p]=num[i]/num[i+1];
                }
            }else{
                if(op[i]=='*'){
                    num2[p]=num2[p]*num[i+1]; // @@ Error: This assumes num2[p] holds the accumulated product so far. This logic relies on p not changing between consecutive * or / operations.
                }else{
                    num2[p]=num2[p]/num[i+1];
                }
            }
            // @@ Major Logic Flaw: The variable `p` is only incremented in the `+` or `-` block. It is NOT incremented in the `*` or `/` block. This means that if we have a sequence like `100 * 200 * 0`, `num2[p]` (where p=0 initially) gets updated correctly to 0. However, the subsequent `+` operator will increment `p`. The problem arises in how `num2` indices map to `op2` indices in the final summation loop.
            // In the final loop: `sum=num2[0]`, then for `i=0` to `p-1`, it uses `op2[i]` and `num2[i+1]`.
            // Let's trace `100 * 200 * 0 * 300 ... + 500 ...`
            // i=0 (*): num2[0] = 100*200 = 20000. p=0.
            // i=1 (*): num2[0] = 20000*0 = 0. p=0.
            // i=2 (*): num2[0] = 0*300 = 0. p=0.
            // i=3 (*): num2[0] = 0*400 = 0. p=0.
            // i=4 (*): num2[0] = 0*500 = 0. p=0.
            // i=5 (+): op2[0]='+'. h=1. Condition (op[4]=='*') is false, so else-if for + runs.
            //   Inside + block: if (i==0 || op[i-1]=='+' || op[i-1]=='-'). Here i=5, op[4]='*'. Condition fails.
            //   So `num2[p]=num[i]` is NOT executed.
            //   p++ -> p becomes 1.
            //   Wait, if the condition fails, what happens to the operand for the '+'?
            //   The code assumes that if the previous op was * or /, the result is already in num2[p].
            //   So for `... * 500 + 500 ...`, the `0` is in num2[0]. The `+` is op2[0].
            //   Next number is 500 (num[6]).
            //   i=6 (/): op[6]='/'. Else block. num2[p] (p=1?? No, p was incremented to 1 in the + block).
            //   Let's re-trace carefully.
            //   i=5 (+): op2[0]='+'. h=1. Check: op[4] is '*'. Condition `(i==0)||(op[i-1]=='+')||(op[i-1]=='-')` is FALSE.
            //   So `num2[p]=num[i]` is skipped.
            //   p++ -> p=1.
            //   Now i=6 (/). op[6]='/'. Else block (since op[5] is '+', wait. op[i-1] is op[5] which is '+').
            //   Condition `(op[i-1]=='+')||(op[i-1]=='-')||(i==0)` is TRUE.
            //   So `num2[p] = num[6]/num[7]`. Here p=1. So num2[1] = 500/600 = 0.
            //   i=7 (+). op[7]='+'. op2[1]='+'. h=2.
            //   Check: op[6] is '/'. Condition FALSE.
            //   Skip `num2[p]=num[i]`.
            //   p++ -> p=2.
            //   i=8 (=). Loop ends (i < q-1, q is likely 9 or 10).
            //   Final sum: sum=num2[0] (which is 0).
            //   Loop i=0 to p-1 (0 to 1).
            //   i=0: op2[0]='+'. sum += num2[1] (0). Sum=0.
            //   i=1: op2[1]='+'. sum += num2[2] (Uninitialized/Garbage!).
            //   The term `12000` is completely missed because when `+` is encountered after `/`, the code skips storing the current number `num[i]` into `num2`, assuming it's part of the previous chain, but it's actually the start of a new term for the NEXT operator or the final term.
            //   Specifically, the logic `if((i==0)||(op[i-1]=='+')||(op[i-1]=='-')){ num2[p]=num[i]; }` inside the `+`/`-` block attempts to store the left operand of the `+`/`-`. But `num[i]` is the number *before* the operator `op[i]`.
            //   For `A + B`, when processing `+` at index i, `num[i]` is A.
            //   If previous was `*`, A is already in `num2[p]`. So skipping is correct.
            //   If previous was `+`, A is `num[i]`. We store it. Correct.
            //   BUT, what about the last number? The loop goes up to `q-2` (operator before `=`).
            //   The last number (after the last operator) is never processed in the loop to be added to `num2`.
            //   In `... + 12000 =`, the `+` is at some index j. The number `12000` is `num[j+1]`.
            //   When processing `op[j]` ('+'), we store `num[j]` (the left side) into `num2`.
            //   The right side `num[j+1]` is never stored into `num2` unless there is another operator after it.
            //   Since `=` stops the loop, the last term is lost.
        }
    }
    int sum=num2[0];
    for(int i=0;i<p;i++){
        if(op2[i]=='+'){
            sum+=num2[i+1];
        }else if(op2[i]=='-'){
            sum-=num2[i+1];
        }
    }
    printf("%d",sum);
}