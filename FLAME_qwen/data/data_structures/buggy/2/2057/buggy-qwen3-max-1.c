#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ [The array `op` is uninitialized, so `op[i]` has undefined value on first iteration; this leads to undefined behavior and likely infinite loop or crash]
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1];
            data[i]=0;
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1]; // @@ [Division order is incorrect: it should be `data[i] / data[i+1]` but due to left-to-right parsing without precedence handling in this pass, the logic is flawed; however, the main issue is that integer division by zero may occur if `data[i+1]` is zero, but more critically, the algorithm does not correctly handle operator precedence across the entire expression because it modifies data in place assuming left associativity without considering that later terms might be part of a multiplication/division chain]
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