#include <stdio.h>
#include <string.h>

void expand_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i+1] != '\0') {
            
            if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')) // @@ The condition checks for same type but misses the requirement that the second character must be greater than the first (str[i-1] < str[i+1]). Also, if this condition is false, it falls through to the next if instead of handling the "no expansion" case correctly.
            
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//数字部分 
            
            if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')) // @@ Same issue: missing check for str[i-1] < str[i+1]. Furthermore, using independent 'if' statements means if the first 'if' (digits) is false, it checks lowercase. If that's false, it checks uppercase. If all are false, it does nothing (doesn't print the '-' or the next char), leading to missing output. It should be an if-else chain or handle the else case explicitly.
                {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//字母部分
        
        
         
        
        if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')) // @@ Same issue: missing check for str[i-1] < str[i+1]. If none of the three conditions are met (e.g., B-e where types differ), no output is generated for the '-' or the following character, causing incorrect output.
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        } 
         i++; // 跳过'-'字符
        } else {
            printf("%c", str[i]);
        }
    }

}

int main() {
    char input_str[1000];

    scanf("%s", input_str);
    expand_string(input_str);
    return 0;
}