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
        printf("e%d\n", dot - nonzero ); // @@ [The exponent calculation is incorrect. For numbers like "0.00123", dot=1, nonzero=4, so dot - nonzero = -3, but it should be -(nonzero - dot - 1) = -3, which accidentally works here, but logic is flawed and fails for other cases. Also, the sign is missing for negative exponents.]

    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ [This function incorrectly removes the '.' but also has a bug: it skips copying the character at index 1 if it's not '.', which corrupts the number. For example, input "123.45" becomes "1345" instead of "12345".]

        putchar(s[nonzero]); // @@ [nonzero is always 0 here, but after removeChar(), the string is corrupted, and s[0] may not be the correct first digit anymore. Also, if the original number had only one digit before '.', this might work by accident, but generally fails.]

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1;
            while (i < length && s[i] != '\0') { // @@ [After removeChar(), the string length and content changed, but 'length' still holds the original length, leading to reading beyond the modified string or including garbage.]
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1); // @@ [This assumes the number is >= 1.0, but if input is like "1.0", dot=1, exponent=0, which is correct. However, due to earlier corruption in removeChar(), the base part is wrong, making the whole output invalid.]
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}