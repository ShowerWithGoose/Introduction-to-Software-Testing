#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ [The array 'op' is uninitialized, so op[0] may not be '=' initially, but more critically, the loop condition reads op[i] before it's assigned. Also, the input format expects a space before '=', but this loop assumes every token is a number followed by an operator, which fails when the last token is just '=' without a preceding number. This leads to undefined behavior and incorrect parsing.]
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
            data[i+1] = data[i] / data[i+1]; // @@ [This performs division as data[i] / data[i+1], but due to left-to-right processing without considering operator precedence correctly across the whole expression, and because earlier multiplications/divisions may have zeroed out data[i], this can lead to division by zero or incorrect operand order. Also, integer division is required, which is okay here, but logic is flawed.]
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