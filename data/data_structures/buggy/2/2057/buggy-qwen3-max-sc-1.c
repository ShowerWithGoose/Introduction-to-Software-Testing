#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ [The array `op` is uninitialized, so `op[i]` may not be '=' initially, leading to undefined behavior. Also, the loop condition is checked before reading input, so it may never read the '=' properly.]
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1]; // @@ [This incorrectly uses `data[i]` which may have been zeroed out in a previous iteration, and also processes left-to-right without respecting operator precedence across the whole expression.]
            data[i]=0;
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1]; // @@ [Same issue as multiplication: uses potentially zeroed `data[i]`, and does not correctly handle precedence in all cases.]
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