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
    result += num1;
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

    system("pause"); // @@ [The function 'system' is declared in <stdlib.h>, which is included, but on some systems or strict compilation environments, calling 'system("pause")' may cause runtime issues or be unsupported. However, the actual compilation error reported was "gcc: not found", which is unrelated to the code itself—it indicates a missing compiler in the environment. But since the problem asks to identify errors in the program that lead to incorrect behavior relative to the specification, the real logical errors are elsewhere.]

    return 0;
}