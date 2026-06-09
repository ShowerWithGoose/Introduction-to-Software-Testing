#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(){
    int num = 0, num1, num2;
    char flag1 = '+', flag2;

    scanf("%d", &num1);//œ»∏≥÷µnum1
    while(1){
        scanf(" %c", &flag2); // @@ The original code `scanf("%c", &flag2)` reads whitespace characters (like spaces or newlines) left in the buffer by previous inputs. Since the input expression contains spaces (e.g., "10 + 20"), reading a space into `flag2` causes the logic to fail because space is not handled as an operator or terminator. Adding a space before `%c` tells scanf to skip any leading whitespace.
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