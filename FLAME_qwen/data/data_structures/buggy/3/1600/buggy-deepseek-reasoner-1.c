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
            if (i != 1) // @@ Wrong condition: should check if str[i] is the decimal point, not if i==1. This causes incorrect removal of the second character regardless of its value.
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

        int nonzero = dot + 1; // @@ Shadows outer nonzero; exponent calculation below uses this local nonzero, but the outer nonzero remains 0 and is never used. However, the exponent dot - nonzero is off by one (should be dot - nonzero + 1?) for correct exponent.
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
        printf("e%d\n", dot - nonzero ); // @@ Exponent value is wrong: should be dot - nonzero + 1? For "0.001", dot=1, nonzero=3 => dot-nonzero = -2, but correct exponent is -3.
    } else {
        //整数
        // 找到小数点的位置
        while (dot < length && s[dot] != '.') {
            dot++;
        }
        // 输出底数部分
        removeChar(s); // @@ removeChar is called, but it may remove the wrong character (see function). Also, after removal, the string no longer contains a dot, so subsequent logic fails.
        putchar(s[nonzero]); // @@ nonzero is still 0 (outer), prints only the first digit; should print all non-zero digits after the first, but here it only prints the first character.

        // 如果有小数点，输出小数点后的数字
        if (dot < length) { // @@ For an integer input (no dot), dot == length, so this block is skipped, so base is just one digit, missing the rest of the number. For a number with dot, after removeChar the dot is removed, so the while loop printing '.' and following digits may still work but depends on removeChar correctness.
            putchar('.');
            int i = nonzero + 1;
            while (i < length && s[i] != '\0') { // @@ s has been modified by removeChar; length still refers to original length, but the modified string may be shorter; also the loop condition uses length but s might have been truncated, causing potential out-of-bounds or printing extra characters.
                putchar(s[i]);
                i++;
            }
        }

        printf("e%d\n", dot - 1); // @@ For integer input, dot == length, so exponent is length-1, which is correct, but the base is incomplete. For numbers with decimal, exponent may be correct, but base is flawed.
    }
}



int main() {
    char s[105];
    scanf("%s", s);
    notation(s);
    return 0;
}