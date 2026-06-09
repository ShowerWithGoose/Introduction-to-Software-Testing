#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]); // @@ [This scanf expects a number followed by a single non-whitespace character, but the input may have spaces before the operator or after the number. The format "%d %c" skips whitespace before %d and then reads any next non-whitespace char for %c, but if there are multiple spaces or the operator is separated by more than one space, it may consume part of the next token incorrectly. More critically, when the expression ends with '=', this approach reads '=' as op[i], but then in the second loop, it processes operators up to but not including '=', which may cause off-by-one errors or incorrect handling of the last number.]
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]); // @@ [Same issue as above: assumes every number is immediately followed by an operator (including '=') with exactly one space, which may not hold. Also, if the input ends with " =", the space before '=' might cause scanf to wait for another character, leading to undefined behavior or incorrect parsing.]
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
            num[i+1]=num[i]-num[i+1]; // @@ [This left-to-right evaluation for '+' and '-' is correct only if all higher-precedence operators have been fully resolved. However, due to flawed propagation of operators in the first pass (e.g., replacing op[i] with op[i-1] without adjusting subsequent logic), the sequence of operations may be corrupted. Additionally, setting num[i]=0 for * and / breaks the accumulation in the second pass because 0 + x = x, but if a prior term was zeroed incorrectly, it may drop needed values.]
        }
    }
    printf("%d",num[i-1]); // @@ [After the loop, i equals the index of '=', so num[i-1] is the last computed value. However, due to incorrect handling in the first pass (e.g., overwriting num[i] with 0 and shifting values improperly), the final result may be wrong. Also, if the expression has only one number (e.g., "5 ="), the initial scanf reads '5' and '=', so i=0, the while loop doesn't run, the for loops don't run, and it prints num[-1] → undefined behavior.]
    return 0;
}