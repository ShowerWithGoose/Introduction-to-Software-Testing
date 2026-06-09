#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
struct multi {
    int coe;
    int index;
} a[N], b[N], out[N];

int cmp(const void* p1, const void* p2) {
    struct multi* x = (struct multi*)p1;
    struct multi* y = (struct multi*)p2;
    return (x->index > y->index) ? -1 : 1;
};

int i, j, num_a, num_b;
char in[N], in1[N];
int main() {
    gets(in);
    char* pc = in;
    for (num_a = 0; *pc != '\0'; num_a++, *pc++) {
        a[num_a].coe = (int)strtol(pc, &pc, 0);
        *pc++;
        a[num_a].index = (int)strtol(pc, &pc, 0);
        // printf("%d %d\n",a[i].coe,a[i].index);
    }
    gets(in1);
    pc = in1;
    for (num_b = 0; *pc != '\0'; num_b++, *pc++) {
        b[num_b].coe = (int)strtol(pc, &pc, 0);
        *pc++;
        b[num_b].index = (int)strtol(pc, &pc, 0);
        // printf("%d %d\n",b[i].coe,b[i].index);
    }

    int cont = 0;
    for (i = 0; i < num_a; i++) {  //计算多项式
        for (j = 0; j < num_b; j++) {
            out[cont].coe = a[i].coe * b[j].coe;
            out[cont].index = a[i].index + b[j].index;
            cont++;
        }
    }
    qsort(out, cont, sizeof(out[0]), cmp);  // index从大到小排序

    for (i = 0; i < cont - 1; i++) {
        if (out[i].index == out[i + 1].index) {
            out[i + 1].coe += out[i].coe;
            out[i].coe = 0;
        }
    }

    for (i = 0; i < cont; i++) {  //输出
        if (out[i].coe != 0)
            printf("%d %d ", out[i].coe, out[i].index);
    }

    return 0;
}

