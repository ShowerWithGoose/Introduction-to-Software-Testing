#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ [The array `op` is uninitialized, so `op[i]` contains garbage values. The loop condition `op[i] != '='` may never be true initially, leading to undefined behavior or infinite loop. Also, the input reading happens inside the loop but the termination condition depends on unread data.]
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
            data[i+1] = data[i] / data[i+1]; // @@ [This performs division as `data[i] / data[i+1]`, but due to left-to-right processing without proper precedence handling across the whole expression, and because earlier terms may have been zeroed out, this can lead to incorrect results. Additionally, if `data[i+1]` is zero, it causes division by zero, though problem states expression is valid. More critically, the algorithm incorrectly modifies the array in a single forward pass, failing to handle operator precedence correctly in all cases (e.g., chained multiplications/divisions).]
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