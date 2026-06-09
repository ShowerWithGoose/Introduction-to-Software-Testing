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
                sscanf(str+i+1,"%d",&right); // @@ The logic fails to skip the digits of the parsed number in the loop index `i`. After processing `20 * 30`, `i` continues character by character. When it hits `+`, it enters the `else` block (since cnt is still 0? No, cnt is 0). Wait, if cnt==0 and it sees `+`, it goes to the second if. It sets cnt=1. Then loop continues. `i` increments. It will eventually hit `-`. Since cnt!=0, it goes to else. It checks if str[i] is * or /. It is not. Then checks if + or -. It is `-`. So it calculates `left = calculate(left, temp, formerOp)`. Here `temp` was set to 30? No. 
                // Let's trace: `10+20*30-40/5=`
                // i=0..1: '1','0'. 
                // i=2: '+'. cnt==0. str[i] is +. sscanf reads 20 into temp. formerOp='+'. cnt=1.
                // i=3..4: '2','0'.
                // i=5: '*'. cnt!=0. str[i] is *. sscanf reads 30 into right. temp = calculate(20, 30, '*') -> 600.
                // i=6..7: '3','0'.
                // i=8: '-'. cnt!=0. str[i] is -. 
                //   First if (* or /) is false.
                //   Second if (+ or -) is true.
                //   left = calculate(left, temp, formerOp) -> calculate(10, 600, '+') -> 610.
                //   sscanf reads 40 into right.
                //   left = calculate(610, 40, '-') -> 570.
                //   cnt=0.
                // i=9..10: '4','0'.
                // i=11: '/'. cnt==0. str[i] is /. sscanf reads 5 into right. left = calculate(570, 5, '/') -> 114.
                // i=12: '5'.
                // i=13: '='. Loop ends.
                // Output 114.
                // Expected 602.
                // The issue is that when we perform an operation immediately (like 10 + ... or result / ...), we update `left`.
                // However, standard precedence means `+` and `-` are lower priority.
                // The algorithm attempts to handle precedence by deferring +/- using `temp` and `cnt`.
                // When `cnt==0`, `left` holds the current accumulated value.
                // If we encounter `*` or `/`, we should combine the *current operand* with the next one.
                // But `left` might be the result of a previous addition.
                // In `10+20*30`, `left` is 10. We see `+`. We store `temp`=20, `formerOp`=`+`.
                // Then we see `*`. We update `temp` to `20*30`=600. This is correct so far.
                // Then we see `-`. We finalize the previous pending operation: `left = 10 + 600 = 610`.
                // Then we start a new pending operation? No, the code does:
                // `sscanf(str+i+1,"%d",&right);` -> reads 40.
                // `left=calculate(left,right,str[i]);` -> `left = 610 - 40 = 570`.
                // `cnt=0`.
                // This effectively treats the `-` as immediate, which is correct for left-associativity IF the next term doesn't have higher precedence operators attached that should bind tighter to the 40.
                // But wait, `40/5`.
                // Now `left` is 570. `cnt` is 0.
                // We continue loop. i moves to `/`.
                // `cnt==0`. `str[i]` is `/`.
                // `sscanf` reads 5 into `right`.
                // `left = calculate(left, right, '/')` -> `570 / 5 = 114`.
                // This is wrong. The expression is `... - 40 / 5`.
                // The subtraction should happen AFTER the division.
                // The code performed the subtraction immediately when it saw `-`, consuming `40` as the right operand.
                // It should have recognized that `40` is the left operand of `/`, so the subtraction should be deferred.
                // The logic `if(str[i]=='+'||str[i]=='-')` inside `cnt!=0` block executes the previous pending op AND the current op immediately.
                // It should only execute the previous pending op, and then set up the current `-` as a new pending op.
                
                left=calculate(left,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                sscanf(str+i+1,"%d",&temp);
                formerOp=str[i];
                cnt++;
            }
        }else{
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right);
                temp=calculate(temp,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                left=calculate(left,temp,formerOp);
                sscanf(str+i+1,"%d",&right); // @@ This line incorrectly consumes the next number and applies the current operator immediately, violating operator precedence if the next operator is * or /. It should instead set up the current operator as the new pending operation.
                left=calculate(left,right,str[i]); // @@ This line applies the current +/- immediately, which is incorrect for precedence. It should store the current operator and the next number (or just the operator, and let the next iteration handle the number) as the new pending state.
                cnt=0; // @@ Resetting cnt here is also part of the flawed logic that prevents deferring the current operator.
            }
        }

    }

    if(cnt!=0){
        left=calculate(left,temp,formerOp);
    }

    printf("%d\n",left);
    return 0;
}