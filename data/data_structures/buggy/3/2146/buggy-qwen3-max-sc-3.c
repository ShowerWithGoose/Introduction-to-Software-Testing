#include <stdio.h>

int main() {
    char s[101];
    scanf("%s", s);
    int d = 0, dygsz = -1; //d代表小数点位置，dygsz代表第一个数字
    for (int i = 0; i < strlen(s); i++) { @@ [Missing #include <string.h> for strlen()]
        if (dygsz == -1 && s[i] != '0' && s[i] != '.') {
            dygsz = i; //找到第一个有效数字的位置 
            putchar(s[i]);
            if (i != strlen(s) - 1) //此步判断是否需要输出小数点，如0.02转变为科学计数法不需要小数点 @@ [Incorrect condition: should check if there are more significant digits after this one, not just any character]
                putchar('.');
            continue;
        }
        if (d == 0&& s[i] == '.') @@ [Logic error: d is set to index of '.', but condition 'd == 0' fails if '.' is at index 0 (e.g., ".5"), though input guarantees digits before decimal, so maybe safe, but still poor practice]
            d = i; //找到小数点的位置 
        if (dygsz != -1 && s[i] != '.') //输出除第一位有效数字和小数点以外的其他数字
            putchar(s[i]);
    }
    printf("e%d", d - dygsz - 1); @@ [Incorrect exponent calculation: for numbers >=1 (e.g., "123.45"), d=3, dygsz=0 → exponent=2, which is correct; but for "0.00123", d=1, dygsz=3 → exponent=1-3-1=-3, which is correct. However, if input has no decimal point (e.g., "123"), d remains 0, then exponent = 0 - 0 -1 = -1, which is wrong. Also, d is never set if there's no '.', leading to wrong exponent.]
    return 0;
}