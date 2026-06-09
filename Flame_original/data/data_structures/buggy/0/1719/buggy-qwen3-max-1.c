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
         i++; // 跳过'-'字符@@ [This increment causes the loop to skip the character after '-', which may be part of another pattern or needed for output. Also, when multiple conditions match (e.g., overlapping ranges), multiple expansions may occur incorrectly. More critically, accessing str[i-1] when i=0 leads to out-of-bounds read.]
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