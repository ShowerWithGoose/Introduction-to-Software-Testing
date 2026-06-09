#include <stdio.h>
#include <string.h>

void expand_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i+1] != '\0') {
            
            if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9'))
            
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//数字部分 
            
            if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z'))
                {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//字母部分
        
        
         
        
        if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z'))
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        } 
         i++; // 跳过'-'字符 @@ [The loop increments `i` here, but the `for` loop also increments `i` at the end of each iteration, causing it to skip the next character after processing '-'. This leads to incorrect output when multiple '-' are present or when characters follow a range.]
        } else {
            printf("%c", str[i]);
        }
    }

}

int main() {
    char input_str[1000];

    scanf("%s", input_str); @@ [Using `scanf("%s", ...)` only reads up to the first whitespace, but the problem does not specify that input has no spaces. However, more critically, the program may access `str[i-1]` when `i=0` (i.e., if string starts with '-'), leading to out-of-bounds read.]
    expand_string(input_str);
    return 0;
}