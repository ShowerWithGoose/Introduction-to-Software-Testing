#include <stdio.h>

int N;
int i, j;
int shuzu[11];
int output[10];

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
    int k1 = i;@@ // Error: if no break (i becomes -1), k1 is -1, leading to out-of-bounds access later
    int temp_low = i + 1;@@ // Error: if i is -1, temp_low becomes 0, but then output[k1] is out-of-bounds
    for (i = k1 + 1; i < N; i++) {
        if (output[i] > output[k1] && output[i] < output[temp_low])
            temp_low = i;
    }
    int temp;
    temp = output[k1];@@ // Error: if k1 is -1, access out-of-bounds
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
    for (i = 1; i < shuzu[N]; i++) {@@ // Error: shuzu[N] is uninitialized because factorial() is never called; using the global variable i also gets corrupted by find()
        find();
        print();
    }
}