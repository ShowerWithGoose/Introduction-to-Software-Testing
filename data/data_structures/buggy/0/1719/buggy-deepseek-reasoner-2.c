#include <stdio.h>
#include <string.h>

void expand_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && str[i+1] != '\0') { // @@ Missing check for i > 0, causing out-of-bounds access when dash is at position 0.
            
            if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')) // @@ Missing condition that str[i+1] > str[i-1]; also no handling when expansion should not occur (should print dash).
            
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//数字部分 
            
            if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')) // @@ Missing condition that str[i+1] > str[i-1]; also missing else to print dash when condition fails.
                {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        }//字母部分
        
        
         
        
        if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')) // @@ Missing condition that str[i+1] > str[i-1]; also missing else to print dash when condition fails.
            {
            for (j = str[i-1] + 1; j <= str[i+1]; j++) {
                printf("%c", j);
            }
        } 
         i++; // 跳过'-'字符 // @@ Double increment of loop variable i (also incremented by for loop), causing skipping of characters after dash.
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