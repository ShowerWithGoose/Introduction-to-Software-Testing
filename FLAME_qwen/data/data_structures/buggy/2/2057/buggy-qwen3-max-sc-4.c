#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ @@ // Error: op[i] is uninitialized on the first iteration, leading to undefined behavior when comparing with '='. The loop condition should not rely on uninitialized array values.
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1]; @@ // Error: This modifies data[i+1] but does not handle operator precedence correctly across multiple * or / in sequence (e.g., 2*3*4). Also, setting data[i]=0 and op[i]='+' may interfere with subsequent operations.
            data[i]=0;
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1]; @@ // Error: Same as above; also, integer division is correct per problem, but logic fails for chained divisions like 12/2/2 because it uses updated data[i+1] incorrectly.
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