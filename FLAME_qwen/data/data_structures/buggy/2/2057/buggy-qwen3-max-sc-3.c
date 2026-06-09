#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ [The array `op` is uninitialized, so `op[i]` has undefined value on first iteration; condition may never be true or cause undefined behavior]
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1]; // @@ [Incorrect operand order: should use current accumulated value, but logic overwrites data[i+1] using data[i] which may have been zeroed in prior pass]
            data[i]=0;
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1]; // @@ [Same issue as multiplication: operand order and zeroing breaks left-to-right evaluation for same-precedence operators]
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