#include <stdio.h>
#include <string.h>

void expand_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i+1] != '\0') { // @@ Missing check for i > 0, accessing str[i-1] when i=0 causes out-of-bounds error

            if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')) // @@ Missing condition str[i+1] > str[i-1] as required by the problem; should use else if to prevent multiple expansions

            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ Loop condition j <= str[i+1] causes the end character to be printed twice (once here and once in the next iteration); should be j < str[i+1]
                printf("%c", j);
            }
        }//数字部分 
            
            if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')) // @@ Missing condition str[i+1] > str[i-1]; should use else if
                {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ Loop condition j <= str[i+1] causes duplicate printing of the end character; should be j < str[i+1]
                printf("%c", j);
            }
        }//字母部分
        
        
         
        
        if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')) // @@ Missing condition str[i+1] > str[i-1]; should use else if
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ Loop condition j <= str[i+1] causes duplicate printing of the end character; should be j < str[i+1]
                printf("%c", j);
            }
        } 
         i++; // 跳过'-'字符 // @@ Unnecessary increment causes skipping the character after '-' due to double increment with the for loop, and fails to print '-' when expansion conditions are not met
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