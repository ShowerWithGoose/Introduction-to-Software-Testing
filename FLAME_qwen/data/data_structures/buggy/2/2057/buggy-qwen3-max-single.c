#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ [The array `op` is uninitialized, so `op[i]` has undefined value on first iteration; condition may never be true or cause undefined behavior. Also, the loop reads one extra token after '=', because it checks `op[i]` only at start of loop, not after reading.]
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1]; // @@ [Incorrect operand order: should use current accumulated value, but logic overwrites data[i+1] using data[i] which may have been zeroed in prior pass. Also, this approach fails when multiple * or / are consecutive due to left-to-right evaluation not being respected across passes.]
            data[i]=0;
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1]; // @@ [Same issue as multiplication: operand order and handling of sequential operators is flawed. Additionally, integer division is used correctly per problem, but logic breaks expression evaluation precedence across full expression.]
            data[i]=0;
            op[i]='+';
        }
    }
    result=data[0];
    for(i=0;i<n-1;i++){
        if(op[i]=='-')
        result=result - data[i+1];
        if(op[i]=='+')
        result=result + data[i+1];
    }
    printf("%d",result);
}