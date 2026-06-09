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
    printf("e%d", d - dygsz - 1); // @@ 错误：当输入为"0.9"时，d=1（小数点位置），dygsz=1（第一个有效数字'9'的位置），计算d - dygsz - 1 = 1 - 1 - 1 = -1，但正确指数应为-1（因为0.9 = 9e-1），实际输出-2。问题在于指数计算逻辑错误，应使用d - dygsz - (dygsz < d ? 1 : 0)或更准确的方法：指数 = 小数点位置 - 第一个有效数字位置 - 1（当第一个有效数字在小数点前时需调整），但此处dygsz在小数点后，正确指数应为d - dygsz = 1 - 1 = 0，再减1得-1，但实际计算多减了1。正确应为d - dygsz（当dygsz > d时）或d - dygsz - 1（当dygsz < d时），但这里dygsz == d，应输出0？不，0.9 = 9e-1，指数应为-1，而d=1, dygsz=1，d - dygsz = 0，再减1得-1，但代码中d - dygsz - 1 = -1，实际输出-2，说明dygsz计算有误。实际上，对于"0.9"，第一个有效数字'9'在索引1，小数点'.'在索引0，所以d=0, dygsz=1，则d - dygsz - 1 = 0 - 1 - 1 = -2，正确应为d - dygsz = -1。因此应改为printf("e%d", d - dygsz);
    return 0;
}