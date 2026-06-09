#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]);
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]);
    }
    for(i=0;op[i]!='=';i++){//µÚÒ»±éÉ¨Ãè 
        if(op[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=0;
            if(i>0){//´«µÝ¼õºÅ 
                op[i]=op[i-1];
            }else{
                op[i]='+';
            } 
        }else if(op[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=0;
            if(i>0){//´«µÝ¼õºÅ 
                op[i]=op[i-1];
            }else{
                op[i]='+';
            }
        }
    }
    for(i=0;op[i]!='=';i++){
        if(op[i]=='+'){
            num[i+1]=num[i]+num[i+1];
        }else if(op[i]=='-'){
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[i-1]); // @@ The loop terminates when op[i] is '=', so i points to the position of '='. The final result is accumulated in num[i], but since the previous step sets num[i+1] (which is num[i] relative to the previous operator), the result is actually in num[i]. However, looking at the logic: if we have 1 + 2 =, i goes 0 ('+'), num[1]=3. Then i becomes 1, op[1] is '=', loop ends. We print num[0] (i-1 = 0). This is wrong. The result is in num[i] (which is num[1]). Wait, let's trace carefully.
    // Trace: 10 + 20 * 30 - 40 / 5 =
    // Initial: num=[10, 20, 30, 40, 5], op=['+', '*', '-', '/', '=']
    // Pass 1 (* and /):
    // i=0: op[0]='+'. Skip.
    // i=1: op[1]='*'. num[2] = 20*30 = 600. num[1]=0. op[1] becomes op[0] which is '+'.
    // State: num=[10, 0, 600, 40, 5], op=['+', '+', '-', '/', '=']
    // i=2: op[2]='-'. Skip.
    // i=3: op[3]='/'. num[4] = 40/5 = 8. num[3]=0. op[3] becomes op[2] which is '-'.
    // State: num=[10, 0, 600, 0, 8], op=['+', '+', '-', '-', '=']
    // Pass 2 (+ and -):
    // i=0: op[0]='+'. num[1] = 10 + 0 = 10.
    // i=1: op[1]='+'. num[2] = 0 + 600 = 600.
    // i=2: op[2]='-'. num[3] = 600 - 0 = 600.
    // i=3: op[3]='-'. num[4] = 0 - 8 = -8.  <-- ERROR HERE. The operand for the last subtraction should be 8 (from num[4]), but num[3] was set to 0 in pass 1. The accumulation logic `num[i+1] = num[i] +/- num[i+1]` relies on `num[i]` holding the running total. 
    // Let's re-evaluate standard accumulator pattern.
    // Usually: result = num[0]; for i... result +=/-= num[i+1].
    // Here it modifies num[i+1].
    // At i=2: num[3] becomes num[2] - num[3] => 600 - 0 = 600.
    // At i=3: num[4] becomes num[3] - num[4] => 600 - 8 = 592.
    // Loop ends when i=4 (op[4]=='=').
    // Prints num[i-1] => num[3] => 600.
    // Expected: 10 + 600 - 8 = 602.
    // The issue is that `num[i]` is zeroed out during multiplication/division, breaking the chain for subsequent additions/subtractions if they rely on the previous number being present.
    // Specifically, when we do `num[i+1] = num[i] + num[i+1]`, if `num[i]` was zeroed out by a previous * or / operation (and not updated by an intermediate + or -), we lose the left operand's value if it wasn't propagated correctly.
    // In the trace:
    // i=0: num[1] = 10 + 0 = 10. Correct.
    // i=1: num[2] = 0 + 600 = 600. Correct (accumulates 10+0 into 10? No, num[1] is 10. But we use num[i] which is num[1]=10? No, i=1. num[1] is 0. num[2] is 600. num[2]=0+600=600. The 10 from num[1] is ignored!
    // The logic `num[i+1] = num[i] + num[i+1]` assumes `num[i]` holds the cumulative sum up to that point. But `num[i]` might have been zeroed out.
    // The correct approach for this specific "zeroing" strategy is usually to only zero out the left operand if it's not needed, or better, just use a separate accumulator variable.
    // However, fixing the print statement is the immediate syntax/logic mismatch for the final result location.
    // If the logic was correct, the result would be in num[i] (the last updated position).
    // Let's look at i=3. num[4] = 600 - 8 = 592? No.
    // Let's re-trace carefully.
    // num=[10, 0, 600, 0, 8], op=['+', '+', '-', '-', '=']
    // i=0: op[0]='+'. num[1] = num[0] + num[1] = 10 + 0 = 10.
    // i=1: op[1]='+'. num[2] = num[1] + num[2] = 10 + 600 = 610.  <-- Here num[1] is 10. So 610 is correct so far.
    // i=2: op[2]='-'. num[3] = num[2] - num[3] = 610 - 0 = 610.
    // i=3: op[3]='-'. num[4] = num[3] - num[4] = 610 - 8 = 602.
    // Loop ends. i=4.
    // Print num[i-1] = num[3] = 610.
    // The result is in num[4] (which is num[i]).
    // So the error is printing num[i-1] instead of num[i].
    return 0;
}