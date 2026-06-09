#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ The loop condition checks uninitialized global array 'op' before any input is read. Although global arrays are zero-initialized (so op[0] is '\0'), the logic relies on reading into op[i] inside the loop. The critical error is that `scanf("%d %c", ...)` with the space in format string consumes leading whitespace but might behave unexpectedly if the input format isn't perfectly matched or if the loop termination condition isn't met correctly due to how `=` is handled. However, the primary logical flaw causing Runtime Error or incorrect calculation often stems from how the expression is parsed and evaluated. In this specific code, the first loop reads numbers and operators. If the input is "10 + 20 * 30 - 40 / 5 =", scanf reads 10 into data[0], '+' into op[0]. Then 20 into data[1], '*' into op[1]. Then 30 into data[2], '-' into op[2]. Then 40 into data[3], '/' into op[3]. Then 5 into data[4], '=' into op[4]. The loop terminates when op[i] becomes '='. This part seems okay for valid input. 
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
            data[i+1] = data[i] / data[i+1];
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