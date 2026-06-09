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
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &input[i].x1, &input[i].y1, &input[i].x2, &input[i].y2);
        input[i].index = 0;
        input[i].seq = 0;
    } // @@ missing sort of input by x1, which is necessary to correctly connect chains from start to end
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
            while (k < n) { // @@ the while loop only searches for successors, not predecessors; without sorting, a chain may be split into multiple groups
                if (input[k].x1 == input[buffer].x2 && input[k].y1 == input[buffer].y2&&k!=buffer) { // @@ does not check if the matched segment is already assigned to another group, which could cause incorrect merging
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
    qsort(INDEX, count, sizeof(IND), cmp); // @@ count should be count-1, because count is one more than the number of groups; this sorts an extra uninitialized element
    int x;
    for (x = 0; input[x].index != INDEX[0].ind || input[x].seq > 1; x++)
        ;
    printf("%d %d %d\n", INDEX[0].num, input[x].x1, input[x].y1);
    for (int y = 0; y < count; y++) { // @@ this loop prints extra output not required by the problem; also iterates over the extra uninitialized element
        printf("%d %d\n", INDEX[y].ind, INDEX[y].num);
    }
    return 0;
}