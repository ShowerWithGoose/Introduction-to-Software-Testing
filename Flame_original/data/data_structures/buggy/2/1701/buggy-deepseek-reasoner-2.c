#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(){
    int num = 0, num1, num2;
    char flag1 = '+', flag2;

    scanf("%d", &num1);//œ»∏≥÷µnum1
    while(1){
        scanf("%c", &flag2); // @@ [Error: This line reads the next character without skipping any whitespace. After scanf("%d") reads a number, a space or newline may be left in the input buffer. The program will then incorrectly treat that whitespace as an operator (flag2). This leads to misinterpreting the expression, especially when spaces are present. The correct approach is to ignore leading whitespace before reading the operator, e.g., using scanf(" %c", &flag2).]
        if(flag2 == '='){
            if(flag1 == '+'){
                num += num1;
            }
            else{
                num -= num1;
            }
            break;
        }
        scanf("%d", &num2);
        if(flag2 == '+' || flag2 =='-'){
            if(flag1 == '+'){
                num += num1;
            }
            else{
                num -= num1;
            }
            num1 = num2;
            flag1 = flag2;
        }
        else{
            if(flag2 == '*'){
                num1 *= num2;
            }
            else{
                if(num2 != 0)
                    num1 /= num2;
            }
        }
    } 
    printf("%d\n", num);
    return 0;
}