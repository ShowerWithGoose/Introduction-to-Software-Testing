#include <stdio.h>
#include <string.h>

void expand_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i+1] != '\0') { // @@ missing boundary check for i > 0
            
            if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')) // @@ missing condition to ensure str[i+1] > str[i-1]
            
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ should use j < str[i+1] instead of <=
                printf("%c", j);
            }
        }//数字部分 
            
            if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')) // @@ missing condition to ensure str[i+1] > str[i-1]
                {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ should use j < str[i+1] instead of <=
                printf("%c", j);
            }
        }//字母部分
        
        
         
        
        if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')) // @@ missing condition to ensure str[i+1] > str[i-1]
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ should use j < str[i+1] instead of <=
                printf("%c", j);
            }
        } 
         i++; // 跳过'-'字符 // @@ this i++ combined with for loop increment causes double increment and does not handle cases where no expansion occurs (should print '-' and move)
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