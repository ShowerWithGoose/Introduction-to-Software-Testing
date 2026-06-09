#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ @@ // The array `op` is uninitialized, so `op[i]` may not be '=' initially, leading to undefined behavior. Also, the loop condition checks `op[i]` before it's read from input.
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1]; @@ // This incorrectly uses `data[i]` which might have been zeroed out in a previous operation (e.g., if `op[i-1]` was '*' or '/'), breaking operator precedence handling.
            data[i]=0;
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1]; @@ // Same issue as above: `data[i]` may already be zero due to prior operations, leading to incorrect division result.
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