#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coe;
    int index;
} node;
node a[100], b[100], c[10000];
int i, j, k, n, m, p;

int cmp(const void *a, const void *b) {
    node *aa = (node *)a;
    node *bb = (node *)b;
    return (((aa->index)>=(bb->index)) ? -1 : 1);
}
int main() {
    do {
        scanf("%d%d", &a[i].coe, &a[i].index);
        i++;
    } while(getchar()!='\n');
    n = i;

    do {
        scanf("%d%d", &b[j].coe, &b[j].index);
        j++;
    } while(getchar()!='\n');
    m = j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            c[k].coe = a[i].coe*b[j].coe;
            c[k].index = a[i].index + b[j].index;
            k++;
        }
    }
    p = k;

    qsort(c, p-1, sizeof(c[0]), cmp);

    int temp = 0;
    for(k = 0; k < p; k++) {
        temp = c[k].coe;
        while(c[k].index == c[k+1].index) {
            temp += c[k+1].coe;
            k++;
        }
        printf("%d %d ", temp, c[k].index);
    }

    return 0;
}

