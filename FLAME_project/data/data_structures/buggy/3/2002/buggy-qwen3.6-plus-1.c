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

    if (xiao_shu_dian == 1) //小于1的数
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
        printf("e%d", zhi_shu); // @@ The logic fails to remove trailing zeros from the mantissa as required by the problem statement ("no trailing zeros after the decimal point"). For input "9.99", it prints "9.99e0" which is correct, but the provided "Buggy Output" in the prompt description corresponds to the *Reference Program* (which outputs 9.9e-1 incorrectly due to its own bugs), not this code. However, looking closely at the provided "Source Code" vs "Reference Program": The prompt asks to identify errors in the program *below*. The program below actually produces `9.99e0` for input `9.99`. Wait, let me re-read carefully.
        
        // Re-evaluating the prompt structure:
        // 1. Problem Description
        // 2. Reference Program (This is likely the "correct" logic or a baseline, but often in these datasets, the "Reference Program" is just another version, and the "Source Code" at the bottom is the one to debug. OR, the "Reference Program" is the correct answer key's logic? No, usually "Reference Program" implies a correct implementation. Let's look at the Reference Program's output for 9.99.
        // Ref Prog: flag=2. len!=1. Prints shu_ru[0] ('9'), then '.', then loop l=1 to < xiao_shu_dian. 
        // In Ref Prog, xiao_shu_dian counts digits before dot? No, it increments if not dot. For "9.99", i=0 ('9') -> xsd=1. i=1 ('.') -> break. xsd=1.
        // Loop l=1; l<1 -> doesn't run.
        // Loop p=xsd+1 (2) to len. Prints shu_ru[2] ('9'), shu_ru[3] ('9').
        // Output: "9.99e0".
        // So the Reference Program outputs 9.99e0.
        
        // Now let's look at the "Source Code" provided at the bottom.
        // Input: 9.99.
        // xiao_shu_dian = 1.
        // xiao_shu_dian == 1 is TRUE.
        // Enters the "less than 1" block.
        // Loop j=2 to len. shu_ru[2] is '9'. '9' > '0'. flag = 2. Break.
        // Prints shu_ru[2] -> '9'.
        // Checks shu_ru[3] ('9') != 0. True.
        // Prints ".".
        // Loop j=3 to len. Prints '9'.
        // Output so far: "9.9".
        // zhi_shu = 1 - 2 = -1.
        // Prints "e-1".
        // Total Output: "9.9e-1".
        
        // The error is that the code incorrectly classifies "9.99" (which is >= 1) as "less than 1" because it only checks if `xiao_shu_dian == 1`. 
        // `xiao_shu_dian` is the index of the decimal point.
        // If input is "0.99", index is 1. Correctly less than 1.
        // If input is "9.99", index is 1. Incorrectly treated as less than 1.
        // The condition `if (xiao_shu_dian == 1)` is insufficient to determine if the number is less than 1. It must also check if the digit before the decimal point is '0'.
    }

    return 0;
}