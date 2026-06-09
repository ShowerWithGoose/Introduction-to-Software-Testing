#include <stdio.h>
#include <string.h>

void expand_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i+1] != '\0') { // @@ Missing `i > 0` check to prevent out-of-bounds access to `str[i-1]`.
            
            if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')) // @@ Missing condition `str[i+1] > str[i-1]` to ensure expansion only when the latter character is strictly greater.
            
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ Loop condition should be `j < str[i+1]` to avoid printing `str[i+1]` twice (once here and once in the next iteration).
                printf("%c", j);
            }
        }//数字部分 
            
            if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')) // @@ Missing condition `str[i+1] > str[i-1]`.
                {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ Loop condition should be `j < str[i+1]`.
                printf("%c", j);
            }
        }//字母部分
        
        
         
        
        if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')) // @@ Missing condition `str[i+1] > str[i-1]`.
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) { // @@ Loop condition should be `j < str[i+1]`.
                printf("%c", j);
            }
        } 
         i++; // 跳过'-'字符 // @@ In a `for` loop, `i` is automatically incremented; this extra increment skips processing `str[i+1]`. Additionally, missing `else` branch to print '-' when expansion conditions fail.
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