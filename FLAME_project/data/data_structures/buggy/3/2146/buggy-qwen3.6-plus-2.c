#include <stdio.h>

int main() {
    char s[101];
    scanf("%s", s);
    int d = 0, dygsz = -1; //d代表小数点位置，dygsz代表第一个数字
    for (int i = 0; i < strlen(s); i++) {
        if (dygsz == -1 && s[i] != '0' && s[i] != '.') {
            dygsz = i; //找到第一个有效数字的位置 
            putchar(s[i]);
            if (i != strlen(s) - 1) //此步判断是否需要输出小数点，如0.02转变为科学计数法不需要小数点 @@ The condition `i != strlen(s) - 1` is incorrect for determining if a decimal point is needed. A decimal point is needed if there are any subsequent digits in the original number (excluding the decimal point itself). For "0.9", the first digit is at index 1. `strlen(s)-1` is 2. `1 != 2` is true, so it prints '.', which is correct for this case, but the logic is flawed for cases like "10" where it might print '.' incorrectly or miss it. More importantly, the exponent calculation below is wrong.
                putchar('.');
            continue;
        }
        if (d == 0&& s[i] == '.')
            d = i; //找到小数点的位置 
        if (dygsz != -1 && s[i] != '.') //输出除第一位有效数字和小数点以外的其他数字
            putchar(s[i]);
    }
    printf("e%d", d - dygsz - 1); @@ The exponent calculation `d - dygsz - 1` is incorrect. The exponent should be `d - dygsz` if `d > dygsz` (decimal point is after the first significant digit) or `d - dygsz + 1` if `d < dygsz` (decimal point is before the first significant digit). Actually, the standard formula for scientific notation exponent is `position_of_decimal_point - position_of_first_significant_digit`. If the decimal point is to the right of the first digit, we move left, so exponent is positive. If to the left, we move right, so exponent is negative. Let's trace "0.9". `dygsz`=1 ('9'), `d`=1 ('.'). Wait, `d` is initialized to 0. The loop finds `dygsz`=1. Then it checks `if (d==0 && s[i]=='.')`. At i=1, s[1]='9', not '.'. At i=0, s[0]='0', not first digit. At i=1, s[1]='9', first digit. `dygsz`=1. `d` remains 0? No, `d` is updated when `s[i]=='.'`. In "0.9", '.' is at index 1? No, "0.9" -> s[0]='0', s[1]='.', s[2]='9'. So `dygsz` will be 2 ('9'). `d` will be 1 ('.'). Exponent should be -1. Formula `d - dygsz` = 1 - 2 = -1. The code uses `d - dygsz - 1` = 1 - 2 - 1 = -2. This is wrong. The correct exponent is `d - dygsz` if we consider the position shift. If the first digit is at `dygsz` and decimal is at `d`, the number is `digit * 10^(d-dygsz)`. So the exponent is `d - dygsz`.
    return 0;
}