#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void removeChar(char str[]) {
    int length = strlen(str);
    int i, j = 0;

    // 遍历原始字符串
    for (i = 0; i < length; i++) {
        // 如果当前字符不是要删除的字符，则将其保留在新字符串中
        if (str[i] != '.') {
            if (i != 1)
                str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void notation(char s[]) {
    int length = strlen(s);
    int i = 0;
    int dot = 0;
    int nonzero = 0;
    if (s[0] == '0') {
        //小数
        while (s[i] != '.') {
            dot++;
            i++;
        }

        int nonzero = dot + 1;
        while (s[nonzero] == '0') {
            nonzero++;
        }
        printf("%c", s[nonzero]);
        i = nonzero + 1;

        putchar('.'); // @@ [This always prints a decimal point even when there are no digits after it, but the expected output for "0.9" is "9e-1", not "9.e-1". The decimal point should only be printed if there are significant digits after it.]
        while (s[i] != '\0') {

            putchar(s[i]);
            i++;
        }
        printf("e%d\n", dot - nonzero );
    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ [This function modifies the original string in a way that may corrupt data needed later. Specifically, it skips copying the character at index 1 if it's not '.', which is incorrect logic for removing just the decimal point.]
        putchar(s[nonzero]); // @@ [After calling removeChar(), the string s is modified, but 'nonzero' is still 0, so this prints s[0]. However, if the original number had leading non-zero digits and a decimal point, this may not correctly represent the first significant digit.]

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1;
            while (i < length && s[i] != '\0') {
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1);
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}