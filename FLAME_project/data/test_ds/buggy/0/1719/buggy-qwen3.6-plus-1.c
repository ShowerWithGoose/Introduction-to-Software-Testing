#include <stdio.h>
#include <string.h>

void expand_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i+1] != '\0') {
            
            if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')) // @@ Missing condition 'str[i-1] < str[i+1]' and should be followed by 'else if'; lacks an 'else' branch to output original characters when expansion conditions are not met.
            
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//数字部分 
            
            if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')) // @@ Should be 'else if', missing 'str[i-1] < str[i+1]' condition.
                {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//字母部分
        
        
         
        
        if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')) // @@ Should be 'else if', missing 'str[i-1] < str[i+1]' condition, and missing 'else' block to print '-' and next char when no expansion occurs.
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        } 
         i++; // 跳过'-'字符 // @@ Unconditionally increments i to skip the next character even when expansion fails, causing missing output for invalid ranges like 'B-e'.
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