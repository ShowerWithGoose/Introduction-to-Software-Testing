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

        int nonzero = dot + 1; // @@ [Variable 'nonzero' is redeclared in the same scope, causing a compilation error in C (shadowing not allowed in C89/C90 and may cause issues in strict modes). Also, this shadows the outer 'nonzero' which remains uninitialized.]
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
        printf("e%d\n", dot - nonzero ); // @@ [The exponent calculation is incorrect: for input like "0.00123", dot=1, nonzero=4, so dot - nonzero = -3, but it prints e-3 as e%d → outputs "e-3" as "e-3"? Actually, %d will print negative correctly, BUT logic is flawed because dot - nonzero is negative, yet format uses %d without sign handling — however main issue is redeclaration above causing compilation failure.]
    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s);
        putchar(s[nonzero]); // @@ ['nonzero' was never initialized in this branch (it's 0 from declaration), so it always prints s[0], which may be okay, but if input has leading zeros (which problem says it won't), but more critically, after removeChar(), the string is modified incorrectly — e.g., "123.45" becomes "1345" because removeChar skips index 1 if i==1, which is wrong.]

        // 如果有小数点，输出小数点后的数字
        if (dot < length) {
            putchar('.');
            int i = nonzero + 1; // @@ ['nonzero' is 0, so starts at index 1, but after removeChar(), the string structure is corrupted, so this indexing is invalid.]
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