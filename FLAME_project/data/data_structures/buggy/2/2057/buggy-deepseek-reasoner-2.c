#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ [Loop condition checks op[i] before reading; after reading '=' it increments i causing extra read and potential infinite loop]
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1];
            data[i]=0; // @@ [Setting data[i]=0 breaks the index alignment; subsequent addition/subtraction uses data[i+1] but the correct operand is lost]
            op[i]='+'; // @@ [Changing op[i] to '+' loses original operator and misaligns evaluation]
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1];
            data[i]=0; // @@ [Same issue as above: zeroing data[i] causes misalignment]
            op[i]='+'; // @@ [Changing operator to '+' leads to incorrect addition/subtraction pass]
        }
    }
    result=data[0];
    for(i=0;i<n-1;i++){
        if(op[i]=='-')
        result=result - data[i+1];
        if(op[i]=='+')
        result=result + data[i+1];
    }
    printf("%d",data[i]); // @@ [Prints data[i] instead of result; should print result variable]
}