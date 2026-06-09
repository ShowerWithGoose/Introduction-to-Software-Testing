#include <stdio.h>
#include <string.h>
char str[120];

int main() {
    int i = 0;
    scanf("%s", str);
    char *p = strchr(str, '.');
    if (str[0] == '0') {
        i = 2;
        while (str[i++] == '0');
        if (str[i] != '\0') {
            printf("%c.%se-%d\n", str[i-1], str+i, i-2);
        }else{
            printf("%ce-%d\n", str[i-1], i-2);
        }
    }else{
        *p = '\0';
        printf("%c.%s%se%d\n", str[0], str+1, p+1, (int)(p-str-1));
    }
    return 0;
}



