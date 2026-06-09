#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int calculate(char s[]){
    int result = 0, cnt = 0, temp = 0, num1 = 0, flag = 1;
    for(int i = 0;s[i] != '\0'; i++){        
        while(s[i] >= '0'&& s[i] <= '9'){
            temp = 10*temp + s[i] - '0';
            i++;
        }
        switch (cnt)
        {
        case 0:
            num1 = temp;
            
            break;
        case 1:
            num1 *= temp;
            cnt = 0;
            break;
        case 2:
            num1 /= temp;
            cnt = 0;
            break;        
        }
        temp = 0;
        switch (s[i]){
        case '+':
            result += flag * num1;
            num1 = 0;
            flag = 1;
            break;
        case '-':
            result += flag * num1;
            num1 = 0;           
            flag = -1;
            break;
        case '*':
            cnt = 1;
            break;
        case '/':
            cnt = 2;
            break;    
        }
    if(s[i] == '=')
        break;    
    }
    result += num1; // @@ Logic error: This adds the last num1 after the loop, but the loop already processes the '=' and breaks, so num1 may not be correctly accumulated for the final term. The algorithm incorrectly handles operator precedence and accumulation, leading to wrong results for expressions with multiple operators.
    return result;
}
int main()
{
    char str1[1000];
    int len = 0;
    fgets(str1, 900, stdin);
    for(int i = 0; str1[i] != '\0'; i++){
        if(str1[i] != ' '){
            str1[len++] = str1[i];
        }
    }
    str1[len] = '\0';
    printf("%d\n", calculate(str1));
    //puts(str1);

    system("pause"); // @@ Logic error: This is not a standard C function and may cause compilation issues on some systems. It should be removed for portability.
    return 0;
}