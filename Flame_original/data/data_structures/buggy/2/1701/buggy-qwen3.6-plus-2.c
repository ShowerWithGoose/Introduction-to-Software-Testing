#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(){
    int num = 0, num1, num2;
    char flag1 = '+', flag2;

    scanf("%d", &num1);//œ»∏≥÷µnum1
    while(1){
        scanf("%c", &flag2); // @@ The %c format specifier does not skip whitespace characters. It will read spaces as operators, causing the subsequent scanf("%d") to fail and leading to incorrect parsing or undefined behavior. It should be " %c" to skip leading spaces.
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