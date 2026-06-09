#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*思路：计算两个加减之间乘除的个数，先算乘除再算加减*/
void chu_kong_ge(char* expression, char* result);//除空格
long long ji_suan(long long a, long long b, char op);//计算加减乘除

int main() {
    char expression[1000], temp[1000] = "\0";
    gets(expression);
    chu_kong_ge(expression, temp);//已经除去空格

    int len = strlen(temp);
    long long jishu = 0; char op[1000] = "\0";
    long long jie_guo = 0;
    long long number_before = 0, number_after = 0;//乘除符号左右两边的数

    for (int i = 0; i < len; i++) {
        if (temp[i] == '+' || temp[i] == '-') {
            op[i] = temp[i];
            //设计一个计数器，读取+-之间的乘除个数
            jishu = 0;
            for (int j = i + 1; j < len && temp[j] != '+' && temp[j] != '-'; j++) {
                if (temp[j] == '*' || temp[j] == '/')jishu++;
            }//注意i没变

            if (jishu == 0)//连加或连减
            {
                int j;
                number_before = jie_guo;
                for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '='; j++) {
                    number_after = number_after * 10 + temp[j] - '0';
                }
                jie_guo = ji_suan(number_before, number_after, op[i]);

                i = j - 1;//i在这里变了
                number_after = 0;
            }

            else if (jishu)//中间有乘除
            {
                long long j, count = jishu, cheng_chu_result = 0, k = i;

                while (jishu--) //乘除内运算
                {
                    if (jishu == count - 1) //第一次需要先对num_before赋值
                    {
                        for (j = i + 1; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                            number_before = number_before * 10 + temp[j] - '0';
                        }
                    }
                    i = j;//i在这里变了,为了更新op[i]
                    op[i] = temp[j];
                    for (j++; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                        number_after = number_after * 10 + temp[j] - '0';
                    }
                    cheng_chu_result = ji_suan(number_before, number_after, op[i]);
                    i = j;
                    op[i] = temp[j];

                    number_before = cheng_chu_result;//将前一次运算得到的结果作为下一次的左数
                    number_after = 0;
                }

                jie_guo = ji_suan(jie_guo, number_before, op[k]);
                i = j - 1;
                number_before = 0;

            }
        }

        else if (temp[i] == '*' || temp[i] == '/') {
            //设计一个计数器，读取+-之间的乘除个数
            jishu = 0;
            for (int j = i; j < len && temp[j] != '+' && temp[j] != '-'; j++) {
                if (temp[j] == '*' || temp[j] == '/')jishu++;
            }//注意i没变

            long long j, count = jishu, cheng_chu_result = 0, k = i;

            while (jishu--) //乘除内运算
            {
                if (jishu == count - 1) //第一次需要先对num_before赋值
                {
                    for (j = 0; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                        number_before = number_before * 10 + temp[j] - '0';
                    }
                }
                i = j;//i在这里变了,为了更新op[i]
                op[i] = temp[j];
                for (j++; j < len && temp[j] != '+' && temp[j] != '-' && temp[j] != '*' && temp[j] != '/' && temp[j] != '='; j++) {
                    number_after = number_after * 10 + temp[j] - '0';
                }
                cheng_chu_result = ji_suan(number_before, number_after, op[i]);
                i = j;
                op[i] = temp[j];

                number_before = cheng_chu_result;//将前一次运算得到的结果作为下一次的左数
                number_after = 0;
            }

            jie_guo = number_before;
            i = j - 1;
            number_before = 0;
        }
        else if (temp[i] == '=') {
            printf("%lld", jie_guo);
        }
        else //出现数字
        {
            jie_guo = jie_guo * 10 + temp[i] - '0';
        }
    }
    return 0;
}

void chu_kong_ge(char* expression, char* result) {
    long long i = 0;
    long long j = 0;
    while (expression[i]) {
        if (expression[i] != ' ') {
            result[j++] = expression[i];
        }
        i++;
    }
    result[j] = '\0';
}

long long ji_suan(long long a, long long b, char op) {
    long long result = 0;
    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    return result;
}