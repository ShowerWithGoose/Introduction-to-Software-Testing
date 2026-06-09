#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long

int main() {                            //一个将字符串中出现的形如0-9，a-z这样的片段时，将其连续地补全的程序
    char t[1000], input[1000];
    int i, k, m;
    int len;
    char temp;

    scanf("%s", input);
    len = strlen(input) - 1;
    for (i = 1; i < len; i++) {
        if (input[i] == '-') {              //查找“-”
            temp = (int) input[i + 1] - (int) input[i - 1];         //计算目标片段中，“-”字符两边的字符相差多少大小
            if (0 == (('0' <= input[i - 1] && input[i + 1] <= '9') || ('A' <= input[i - 1] && input[i + 1] <= 'Z') ||
                      ('a' <= input[i - 1] && input[i + 1] <= 'z')))
                break;                      //对不合法的缺少片段的筛选，比如出现t-5，0-a这样的片段，则直接输出
            len += temp;                //为补全目标片段拓宽字符串长度
            strcpy(t, input + i + 1);       //在片段补齐前，把“-”右边的字符串收集存放在临时字符串中
            for (m = 0; m < temp; ++m) {   //此步用于补全目标片段
                input[i + m - 1] = (int) input[i - 1] + m;
            }
            i += temp - 1; //与第26行作用相似
            for (k = 0; input[i + k] != '\0'; ++k) {
                input[i + k] = '\0';  //将补齐后的片段后面的所有字符置0，以接上临时字符串t中储存的原字符串
            }
            strcat(input, t);//接上
        }
    }
    printf("%s", input);

    return 0;
}



