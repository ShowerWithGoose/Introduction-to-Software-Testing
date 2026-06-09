#include <stdio.h>

int N;
int i, j;
int shuzu[11];
int output[10];

//定义的都是全局变量，函数（）里不用定义变量
int factorial() { //阶乘
    shuzu[0] = 1;
    int i;
    for (i = 1; i < 10; i++) {
        shuzu[i] = i * shuzu[i - 1];
    }
}

void print() {
    int i = 0;
    for (i = 0; i < N - 1; i++) {
        printf("%d ", output[i]);//打印前几位数字
    }
    printf("%d\n", output[i]);//打印最后一位数字并换行
}

void find() {
    for (i = N - 2; i >= 0; i--) {
        if (output[i] < output[i + 1])
            break;
    }
    int k1 = i;
    int temp_low = i + 1;
    for (i = k1 + 1; i < N; i++) {
        if (output[i] > output[k1] && output[i] < output[temp_low])
            temp_low = i;
    } // @@ [When k1 is -1 (i.e., no such index found), temp_low becomes 0, and the subsequent logic fails. Also, the condition assumes temp_low is always valid, but when k1 == -1, the permutation is the last one and should not proceed further.]
    int temp;
    temp = output[k1];
    output[k1] = output[temp_low];
    output[temp_low] = temp; // @@ [If k1 is -1 (which happens when the current permutation is the last in lex order), accessing output[k1] is out-of-bounds (output[-1]), leading to undefined behavior.]
    for (j = k1 + 1, i = N - 1; i > j; i--, j++) {
        temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }
}

int main() {
    factorial(); // @@ [This line is missing in the buggy version! Without calling factorial(), shuzu[N] remains uninitialized, so the loop condition i < shuzu[N] uses garbage value, causing the loop to possibly not run at all (as seen: only first permutation printed).]
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
        output[i] = i + 1;
    }
    print();
    for (i = 1; i < shuzu[N]; i++) {
        find();
        print();
    }
}