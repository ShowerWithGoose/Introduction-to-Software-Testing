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
} // @@ [The function 'factorial' is defined but never called, so 'shuzu' remains uninitialized when used in main(). This leads to undefined behavior when accessing shuzu[N].]

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
        if (output[i] > output[k1] && output[i] < output[temp_low]) // @@ [If k1 is -1 (i.e., no such i found), then output[k1] is out-of-bounds access. Also, when k1 == N-2, temp_low = N-1, and the loop condition may compare with uninitialized or incorrect values. Moreover, this logic does not correctly find the smallest element greater than output[k1] from the right part.]
            temp_low = i;
    }
    int temp;
    temp = output[k1]; // @@ [If k1 is -1 (which happens when the permutation is the last one in lex order), this accesses output[-1], causing undefined behavior.]
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
    int i;
    for (i = 0; i < N; i++) {
        output[i] = i + 1;
    }
    print();
    for (i = 1; i < shuzu[N]; i++) { // @@ ['shuzu' was never initialized because 'factorial()' was never called, so shuzu[N] contains garbage value, leading to incorrect loop count or infinite loop.]
        find();
        print();
    }
}