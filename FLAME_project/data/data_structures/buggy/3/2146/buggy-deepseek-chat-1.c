#include <stdio.h>

int main() {
    char s[101];
    scanf("%s", s);
    int d = 0, dygsz = -1; //d代表小数点位置，dygsz代表第一个数字
    for (int i = 0; i < strlen(s); i++) {
        if (dygsz == -1 && s[i] != '0' && s[i] != '.') {
            dygsz = i; //找到第一个有效数字的位置 
            putchar(s[i]);
            if (i != strlen(s) - 1) //此步判断是否需要输出小数点，如0.02转变为科学计数法不需要小数点
                putchar('.');
            continue;
        }
        if (d == 0&& s[i] == '.')
            d = i; //找到小数点的位置 
        if (dygsz != -1 && s[i] != '.') //输出除第一位有效数字和小数点以外的其他数字
            putchar(s[i]);
    }
    printf("e%d", d - dygsz - 1); // @@ 错误：对于输入"0.9"，d=1（小数点位置），dygsz=1（第一个有效数字'9'的位置），计算得d-dygsz-1=1-1-1=-1，但正确指数应为-1（因为0.9=9e-1），实际输出-2。问题在于当小数点前有0时，指数计算应基于有效数字相对于小数点的偏移，此处公式错误，应改为d - dygsz（不额外减1），因为dygsz已经包含了小数点前的0的偏移。
    return 0;
}