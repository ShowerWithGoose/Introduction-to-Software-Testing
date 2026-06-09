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
} // @@ [The function 'factorial' is defined but never called in main(), so shuzu[N] remains uninitialized when used in the loop condition, leading to undefined behavior.]

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
    } // @@ [If k1 is -1 (i.e., no such i found), then temp_low = 0, and accessing output[temp_low] may be invalid. Also, when k1 == N-2, temp_low starts at N-1, but the loop may not run, leaving temp_low as N-1 which might be okay, but the logic for finding the smallest larger element is flawed because it assumes temp_low is always valid and initialized correctly even when k1 is -1.]

    int temp;
    temp = output[k1];
    output[k1] = output[temp_low];
    output[temp_low] = temp; // @@ [If k1 is -1 (which happens when the permutation is the last one in lex order), this accesses output[-1], causing undefined behavior.]

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
    for (i = 1; i < shuzu[N]; i++) { // @@ [shuzu[N] is used without initializing the 'shuzu' array via calling factorial(), so it contains garbage values, leading to incorrect loop count or infinite/zero iterations.]
        find();
        print();
    }
}