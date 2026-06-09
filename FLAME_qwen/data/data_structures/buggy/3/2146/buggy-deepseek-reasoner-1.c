#include <stdio.h> // @@ 缺少 <string.h> 头文件，导致 strlen 未声明，可能引起编译警告或错误

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
    printf("e%d", d - dygsz - 1); // @@ 指数计算公式错误：对于整数输入（无小数点）和小于1的小数（如0.0023），结果不正确。应根据有无小数点及数字大小分别处理。
    return 0;
}