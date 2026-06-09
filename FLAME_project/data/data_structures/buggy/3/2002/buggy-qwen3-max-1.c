#include <stdio.h>  
#include <string.h>  

int main() {
    char shu_ru[105]; // 存储输入的字符串
    int xiao_shu_dian = 0; // 小数点位置  
    int xiao_shu_wei_shu = 0; // 小数位数  
    int zhi_shu = 0; // 指数部分  

    // 读取输入  
    gets(shu_ru);
    int len = strlen(shu_ru);

    // 找到小数点位置  
    for (int i = 0; shu_ru[i] != '\0'; i++) {
        if (shu_ru[i] == '.') {
            xiao_shu_dian = i;
            break;
        }
    }

    // 计算小数位数  
    int i = xiao_shu_dian + 1;
    while (shu_ru[i] != '\0') {
        xiao_shu_wei_shu++;
        i++;
    }

    if (xiao_shu_dian == 1) //小于1的数@@ [This condition incorrectly assumes that any number with the decimal point at index 1 (i.e., "0.x...") is less than 1, but it fails to check whether the first digit is actually '0'. For input like "9.99", xiao_shu_dian=1, so it wrongly enters this branch.]
    {
        int flag = 0;//找到出现的第一个非零位flag
        for (int j = 2; j < len; j++)
        {
            if (shu_ru[j] > '0') {
                flag = j;
                break;
            }
        }
        printf("%c", shu_ru[flag]);//打印底数
        if (shu_ru[flag + 1] != 0) {
            printf(".");
            for (int j = flag + 1; j < len; j++) {
                printf("%c", shu_ru[j]);
            }
        }
        // 计算指数部分  
        zhi_shu = 1 - flag;
        printf("e%d", zhi_shu);
    }

    else //大于1的数
    {
        //打印底数
        printf("%c.", shu_ru[0]);
        for (int j = 1; j < xiao_shu_dian; j++) {
            printf("%c", shu_ru[j]);
        }
        for (int j = xiao_shu_dian + 1; j < len; j++) {
            printf("%c", shu_ru[j]);
        }
        // 计算指数部分  
        zhi_shu = xiao_shu_dian - 1;
        printf("e%d", zhi_shu);
    }

    return 0;
}