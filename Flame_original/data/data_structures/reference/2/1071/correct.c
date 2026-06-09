#include <stdio.h>
#include <string.h>
int Number[56];
int Result;
char c;//判断读入的内容
int Compute(int s[],int t);
int flag[10];
int main(){
    int i = 0;
    int value = 0,valueLeft = 0,valueRight = 0;
    while((scanf("%c",&c))!='='){
        if (c >='0'&&c <='9'){
            Number[i++]=c-48;
        }
        else if (c == '+'){
            valueRight = Compute(Number,i-1);
            value = Compute(Number,i-1);
            if (flag[3] == 1){
                value = valueLeft * valueRight;
                flag[3] = 0;
            }
            else if (flag[4] == 1){
                value = valueLeft / valueRight;
                flag[4] = 0;
            }
            if (flag[1] == 1){
                Result += value;
            }
            else if (flag[2] == 1){
                Result -= value;
                flag[2] = 0;
                flag[1] = 1;
            }
            else {
                Result += value;
                flag[1] = 1;
            }
            i = 0;
        }
        else if (c == '-'){
            valueRight = Compute(Number,i-1);
            value = Compute(Number,i-1);
            if (flag[3] == 1){
                value = valueLeft * valueRight;
                flag[3] = 0;
            }
            else if (flag[4] == 1){
                value = valueLeft / valueRight;
                flag[4] = 0;
            }
            if (flag[1] == 1){
                Result += value;
                flag[1] = 0;
                flag[2] = 1;
            }
            else if (flag[2] == 1){
                Result -= value;
            }
            else {
                Result += value;
                flag[2] = 1;
            }
            i = 0;
        }
        else if (c == '*'){
            if (flag[3] == 1){
                valueRight = Compute(Number,i-1);
                valueLeft *= valueRight;
            }
            else if (flag[4] == 1){
                valueRight = Compute(Number,i-1);
                valueLeft /= valueRight;
                flag[4] = 0;
                flag[3] = 1;
            }
            else{
                valueLeft = Compute(Number,i-1);
                flag[3] = 1;
            }  
            i=0;
        }
        else if (c == '/'){
           if (flag[3] == 1){
                valueRight = Compute(Number,i-1);
                valueLeft *= valueRight;
                flag[3] = 0;
                flag[4] = 1;
            }
            else if (flag[4] == 1){
                valueRight = Compute(Number,i-1);
                valueLeft /= valueRight;
            }
            else{
                valueLeft = Compute(Number,i-1);
                flag[4] = 1;
            }  
            i=0;
        }
        else if (c == ' '){
            continue;
        }
        else if (c == '='){
            if (flag[1] == 0 && flag[2] == 0 && flag[3] == 0 && flag[4] == 0){
                Result = Compute(Number,i-1);
            }
            break;
        }
    }
    
    if (flag[3] == 1){
        valueRight = Compute(Number,i-1);
        valueLeft *= valueRight;
        flag[3] = 0;
        if (flag[1] == 1){
            Result += valueLeft;
            flag[1] = 0;
        }
        else if (flag[2] == 1){
            Result -= valueLeft;
            flag[2] = 0;
        }
        else {
            Result += valueLeft;
        }
    }
    else if (flag[4] == 1){
        valueRight = Compute(Number,i-1);
        valueLeft /= valueRight;
        flag[4] = 0;
        if (flag[1] == 1){
            Result += valueLeft;
            flag[1] = 0;
        }
        else if (flag[2] == 1){
            Result -= valueLeft;
            flag[2] = 0;
        }
        else {
            Result += valueLeft;
        }
    }
    else if (flag[1] == 1){
        valueLeft = Compute(Number,i-1);
        Result += valueLeft;
        flag[1] = 0;
    }
    else if (flag[2] == 1){
        valueLeft = Compute(Number,i-1);
        Result -= valueLeft;
        flag[2] = 0;
    }
    printf("%d\n",Result);
    return 0;
}
int Compute(int s[],int t){
    int mult =1,result =0;
    for ( ; t>=0 ; t-- ){
        result += s[t] * mult;
        mult *= 10;
    }
    return result;
}
