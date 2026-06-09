#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int num1,num2,num3;
    char op1,op2,op3;
    num1=0;op1='+';
    while(op1!='='){
        scanf("%d %c",&num2,&op2);
        while(op2=='*'||op2=='/'){
            scanf("%d %c",&num3,&op3);
            if(op2=='*') num2=num2*num3;
            else if(op2=='/') num2=num2/num3;
            op2=op3;
        }
        if(op1=='+') num1=num1+num2;
        else if(op1=='-') num1=num1-num2;
        op1=op2;
    }
    printf("%d",num1);
    return 0;
}


