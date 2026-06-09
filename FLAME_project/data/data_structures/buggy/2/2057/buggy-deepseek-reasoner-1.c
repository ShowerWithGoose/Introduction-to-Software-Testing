#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ line 6: The loop condition uses uninitialized op[0], causing undefined behavior. Should read input first and then check for '='.
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1];
            data[i]=0; // @@ line 13: Setting left operand to 0 loses the original value. This causes later addition/subtraction to incorrectly add/subtract 0 instead of the original number. Should mark as used and skip in later loop.
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1];
            data[i]=0; // @@ line 18: Same issue as line 13 for division.
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
    printf("%d",data[i]); // @@ line 29: Prints data[i] (the last number) instead of the computed result. Should print result.
    return 0;
}