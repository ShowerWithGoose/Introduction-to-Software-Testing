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

        putchar('.');
        while (s[i] != '\0') {

            putchar(s[i]);
            i++;
        }
        printf("e%d\n", dot - nonzero ); // @@ [The exponent calculation is incorrect. For numbers like "0.00123", dot=1 (index of '.'), nonzero=4 (index of '1'), so exponent should be -(nonzero - dot) = -3, but this computes 1 - 4 = -3 without the negative sign handling correctly in format. Also, it prints "e-3" as "e-3" only if formatted with '-', but here it's printed as e%d with negative value, which would output "e-3", but the logic dot - nonzero is negative and correct numerically, however the bigger issue is that the code assumes s[0]=='0' implies number < 1, but doesn't handle cases where input is "0.1" vs "10.0". However, the main error causing wrong output is elsewhere.]

    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ [This function incorrectly removes the decimal point but also skips copying the character at index 1 unconditionally if it's not '.', which corrupts the digit string. For example, input "12.34" becomes "134" because when i=1 (character '2'), since i==1, it is skipped due to `if (i != 1)` condition, leading to loss of significant digits.]

        putchar(s[nonzero]); // @@ [nonzero is initialized to 0 but never updated in the 'else' branch, so it always prints s[0]. However, after removeChar(), the string is corrupted, and even if it weren't, this only prints the first digit, but the logic for printing subsequent digits is flawed.]

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