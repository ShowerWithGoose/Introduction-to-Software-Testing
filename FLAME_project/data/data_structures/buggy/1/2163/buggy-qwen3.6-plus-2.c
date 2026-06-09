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
    if (k1 < 0) return; // @@ [If k1 is -1, it means the current permutation is the last one (descending order), so we should stop generating. Without this check, accessing output[-1] or proceeding with invalid indices causes undefined behavior or incorrect logic.]
    int temp_low = i + 1;
    for (i = k1 + 1; i < N; i++) {
        if (output[i] > output[k1] && output[i] < output[temp_low])
            temp_low = i;
    }
    int temp;
    temp = output[k1];
    output[k1] = output[temp_low];
    output[temp_low] = temp;
    for (j = k1 + 1, i = N - 1; i > j; i--, j++) {
        temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }
}

int main() {
    scanf("%d", &N);
    factorial(); // @@ [The factorial function must be called AFTER reading N to ensure shuzu[N] is computed correctly before it is used in the loop condition. Although shuzu is precomputed up to 9, calling it here ensures correctness and matches the logical flow. More importantly, in the original buggy code provided in the prompt's "Source Code" section, factorial() was missing entirely from main, leading to uninitialized shuzu values.]
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