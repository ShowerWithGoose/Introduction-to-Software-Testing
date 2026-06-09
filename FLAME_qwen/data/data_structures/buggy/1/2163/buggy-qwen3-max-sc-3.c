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
        if (output[i] > output[k1] && output[i] < output[temp_low])
            temp_low = i;
    } // @@ [If no element greater than output[k1] exists (which shouldn't happen per algorithm logic), temp_low may be invalid. More critically, when k1 == -1 (i.e., last permutation reached), this loop and subsequent code cause out-of-bounds access or incorrect behavior. However, the primary issue is that 'factorial()' is never called, so the loop count in main() is wrong.]

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
    int i;
    for (i = 0; i < N; i++) {
        output[i] = i + 1;
    }
    print();
    for (i = 1; i < shuzu[N]; i++) { // @@ [The array 'shuzu' was never initialized because factorial() was never called. Thus, shuzu[N] contains garbage, leading to incorrect number of iterations (possibly zero or huge).]
        find();
        print();
    }
}