#include <stdio.h>
#include <string.h>

void qvan(char *str, int list[10], int length);

int main()
{
    int n, num[10];
    char str[20];
    scanf("%d", &n);

    str[0] = '\0';

    for(int i = 0; i < n; i++)
        num[i] = i + 1;
    qvan(str, num, n);
}

//打印一个数组的全排列，str：待打印的前半段，list：目标数组，length：数组有效长度
void qvan(char str[], int list[10], int length){
    //一位则直接打印
    if(length == 1){
        printf("%s%d\n", str, list[0]);
    }
    else{
        //大于一位，则取数组中数字轮流做第一位做开头
        int newlist[10];
        for(int j = 0; j < length; j++){
            //第一位记录在前半段,带空格
            int l = strlen(str);
            str[l] = list[j] + '0';
            str[l + 1] = ' ';
            str[l + 2] = '\0';

            //删掉打头的数字得到剩余数组
            for(int i = 0, ii = 0; ii < length; ii++){
                if(ii != j){
                    newlist[i] = list[ii];
                    i++;
                }
            }

            //递归
            qvan(str, newlist, length - 1);
            //每个数字打头结束后，str恢复到初始状态
            str[l] = '\0';
        }
    }
}


