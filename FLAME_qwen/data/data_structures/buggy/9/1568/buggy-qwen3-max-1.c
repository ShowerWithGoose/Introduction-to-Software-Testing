#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int index;
    int seq;
    int x1;
    int y1;
    int x2;
    int y2;
}line,*lineptr;

typedef struct {
    int ind;
    int num;
}IND,*INDptr;

IND INDEX[110];
int count = 1;
line input[110];
int n;

int cmp(const INDptr e1, const INDptr e2) {
    return (e2->num) - (e1->num);
} // @@ [qsort expects a comparison function with parameters of type 'const void *', but this function uses 'const INDptr', which is incompatible and causes undefined behavior or compilation error depending on compiler settings]

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &input[i].x1, &input[i].y1, &input[i].x2, &input[i].y2);
        input[i].index = 0;
        input[i].seq = 0;
    }
    for (int j = 0; j < n; j++) {
        if (input[j].index != 0) continue;
        else {
            int SEQ = 1;
            input[j].index = count;
            input[j].seq = SEQ;
            count++;
            SEQ++;
            INDEX[input[j].index - 1].ind = input[j].index;
            INDEX[input[j].index-1].num = 1;
            int buffer = j;
            int k = 0;
            while (k < n) {
                if (input[k].x1 == input[buffer].x2 && input[k].y1 == input[buffer].y2&&k!=buffer) {
                    input[k].index = input[j].index;
                    input[k].seq = SEQ;
                    SEQ++;
                    buffer = k;
                    k = 0;
                    INDEX[input[j].index - 1].num++;
                }
                else {
                    k++;
                }
            }
        }
    }
    qsort(INDEX, count, sizeof(IND), cmp); // @@ [Passing 'cmp' with incorrect signature to qsort leads to undefined behavior or compilation error; qsort requires a function pointer of type 'int (*)(const void *, const void *)']
    int x;
    for (x = 0; input[x].index != INDEX[0].ind || input[x].seq > 1; x++)
        ;
    printf("%d %d %d\n", INDEX[0].num, input[x].x1, input[x].y1);
    for (int y = 0; y < count; y++) {
        printf("%d %d\n", INDEX[y].ind, INDEX[y].num);
    }
    return 0;
}