#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char line[500];
int t;
int a[200][2];
int b[200][2];
int c[200][2];
int get_num();
int fill(int s[][2]);
int multi(int a[][2], int n1, int b[][2], int n2, int c[][2]);
int cmp_int(const void* a, const void* b);

int main() {
    int n1, n2, n3, i, xishu, zhishu;
    gets(line);
    n1 = fill(a);
    t = 0;
    gets(line);
    n2 = fill(b);

    n3 = multi(a, n1, b, n2, c);
    qsort(c, n3, sizeof(c[0]), cmp_int);
    for (i = 0; i < n3; i++) {
        xishu = c[i][1];
        zhishu = c[i][0];
        while (c[i][0] == c[i + 1][0]) {
            xishu += c[i + 1][1];
            i++;
        }
        if (xishu) {
            printf("%d %d ", xishu, zhishu);
        }
    }
    return 0;
}

int get_num() {
    int j = 0, number;
    char num[50];
    while (t==0||line[t-1]!=0) {
        for (; line[t] != ' ' && line[t] != '\0'; t++) num[j++] = line[t];
        num[j] = '\0';
        number = atoi(num);
        t++;
        return number;
    }
    return 0;
}
int fill(int s[][2]) {
    int val1, val2, i = 0;
    while ((val1 = get_num()) != 0) {
        val2 = get_num();
        s[i][0] = val1;
        s[i++][1] = val2;
    }
    return i;
}
int multi(int a[][2], int n1, int b[][2], int n2, int c[][2]) {
    int k = 0, i, j, xishu, zhishu;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            xishu = a[i][0] * b[j][0];
            zhishu = a[i][1] + b[j][1];
            c[k][1] = xishu;
            c[k++][0] = zhishu;
        }
    }
    return k;
}
int cmp_int(const void* a, const void* b) {
    //const int* ptr_int_a=(const int*)a;
    //const int* ptr_int_b=(const int*)b;
    return *(int*)b - *(int*)a;
}

