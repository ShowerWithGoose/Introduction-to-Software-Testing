#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){
        scanf("%d %c",&data[i],&op[i]);
        n++;
    } // @@ [The loop condition checks op[i] before it's read on the first iteration, leading to undefined behavior. Also, spaces in input may cause scanf to fail or skip values incorrectly.]
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
    } // @@ [This pass processes * and / left-to-right but does not respect operator precedence correctly when multiple * and / are adjacent, because it modifies data[i] to 0 and op[i] to '+', which interferes with subsequent operations in the same pass. Also, it doesn't handle the fact that after processing a * or /, the next operation might also be * or / involving the updated value.]
    result=data[0];
    for(i=0;i<n-1;i++){
        if(op[i]=='-')
        result=result - data[i+1];
        if(op[i]=='+')
        result=result + data[i+1];
    } // @@ [Because earlier passes set some data[i] to 0 and changed operators to '+', the final accumulation uses incorrect operands. For example, in "10 + 20 * 30", after processing *, data[1] becomes 600 and data[0] becomes 0, then result = 0 + 600 + ... which misses the original structure. The algorithm fails to collapse the expression properly.]
    printf("%d",result);
}