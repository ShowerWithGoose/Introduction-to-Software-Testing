#include <stdio.h>

void remove_spaces(char str[]){
    int i=0;
    int j=0;
    while(str[i]!='\0'){
        if(str[i]!=' '){
            str[j]=str[i];
            j++;
        }
        i++;
    }
    str[j]='\0';
}

int calculate( int left, int right, char op){
    if(op=='+'){
        return left+right;
    }
    if(op=='-'){
        return left-right;
    }
    if(op=='*'){
        return left*right;
    }
    if(op=='/'){
        return left/right;
    }
    return 0;
}

int main(){
    char str[10000];
    gets(str);

    remove_spaces(str);

    int cnt=0;
    int left,right,temp;
    char formerOp;

    sscanf(str,"%d",&left);

    for(int i=0;str[i]!='=';i++){

        if(cnt==0){
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right);
                left=calculate(left,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){ // @@ The logic fails to correctly handle operator precedence when switching from high precedence (*, /) to low precedence (+, -). Specifically, `temp` is not initialized with the current `left` value before starting a new low-precedence term, and the state transition doesn't correctly isolate the term being built. When encountering + or -, it should start accumulating a new term into `temp`, but `temp` currently holds garbage or old data, and `left` isn't updated correctly relative to the previous term if there was one. More critically, the variable `temp` is used uninitialized in the `else` block if the first operator encountered is + or -, because `temp` is only assigned in the `else` branch or implicitly expected to hold the second operand of the low-prec operation, but the initialization `sscanf(... &temp)` happens *after* setting `formerOp`. Wait, looking closer: if cnt==0 and we hit +, we sscanf into temp. That part is okay for the first term. However, the major issue is how `left` is updated. In standard evaluation, `left` accumulates the result of previous low-prec operations. When we see a + or -, we should finalize the previous term. Here, `left` is just the running total. If we have `10 + 20 * 30`, `left` becomes 10. We see `+`, set `formerOp='+'`, `cnt=1`, `temp=20`. Then we see `*`, `temp` becomes `20*30=600`. Then we hit `-` (or end). If we hit `-`, we do `left = calculate(left, temp, formerOp)` -> `10 + 600 = 610`. Then `sscanf` next number `40`. `left = calculate(610, 40, '-')` -> `570`. This seems logically close but flawed because `left` is being overwritten by the result of the low-prec op immediately, losing the structure for the next term. Actually, the bug is simpler: when `cnt==0` and we encounter `+` or `-`, we read `temp`. But `temp` is not initialized to the *current* number if the expression starts with a number. `sscanf(str+i+1, "%d", &temp)` reads the number *after* the operator. This is correct for the second operand. But what about the first operand? `left` holds the first number. So `left` is the first term. `temp` becomes the start of the second term. This works for `A + B ...`. But if we have `A * B + C`, `left` becomes `A*B`. Then we hit `+`. `cnt` is 0. We read `C` into `temp`. `formerOp` is `+`. `cnt` becomes 1. Then if we hit `*` again, `temp` is updated. Finally, if we hit `-` or end, `left = calculate(left, temp, formerOp)`. This logic actually handles `A*B+C` correctly? Let's trace `10 + 20 * 30 - 40 / 5 =`.
1. `left`=10.
2. i points to `+`. cnt=0. Op is `+`. sscanf `20` into `temp`. formerOp=`+`. cnt=1.
3. i points to `2`. Skip.
4. i points to `0`. Skip.
5. i points to `*`. cnt=1. Op is `*`. sscanf `30` into `right`. `temp` = `calculate(20, 30, '*')` = 600.
6. i points to `3`. Skip.
7. i points to `0`. Skip.
8. i points to `-`. cnt=1. Op is `-`. `left` = `calculate(10, 600, '+')` = 610. sscanf `40` into `right`. `left` = `calculate(610, 40, '-')` = 570. cnt=0. **ERROR**: Here, `left` is updated to 570. But the term `40` might be part of a division. By setting `cnt=0`, we treat `40` as the new `left` effectively? No, `left` is now 570. The next number `40` was read into `right` and consumed into `left`. But `40 / 5` needs to be evaluated first. The code reads `40` into `right` and immediately does `left - right`. It ignores that `40` might be followed by `/`. The `sscanf` consumes the number, but the loop index `i` is still at `-`. The next iterations will scan past `40`. When it hits `/`, `cnt` is 0. It will try to do `left * / right`? No, `left` is 570. It will do `570 / 5`? No, `sscanf(str+i+1)` where `i` is at `/` will read `5`. So it calculates `570 / 5 = 114`. This matches the buggy output. The error is that when transitioning from a low-precedence operator (`-`), the code immediately consumes the next number and applies the low-precedence operator, failing to check if that next number is the start of a high-precedence term (like `40 / 5`). It should have started a new term `temp=40` and waited to see if `*` or `/` follows.
            left=calculate(left,right,str[i]);
            cnt=0;
            }
        }

    }

    if(cnt!=0){
        left=calculate(left,temp,formerOp);
    }

    printf("%d\n",left);
    return 0;
}