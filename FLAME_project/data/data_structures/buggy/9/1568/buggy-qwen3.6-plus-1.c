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
    qsort(INDEX, count, sizeof(IND), cmp);
    int x;
    for (x = 0; input[x].index != INDEX[0].ind || input[x].seq > 1; x++) // @@ The loop condition logic is flawed for finding the start of the chain. It stops at the first segment belonging to the max chain with seq > 1, but it should find the segment with seq == 1. Also, if the chain has only 1 segment, seq is 1, so it might skip it or behave unexpectedly depending on initialization. More critically, the problem states x1 < x2 for segments, and continuous lines have increasing x. The start of the continuous line is the start of the first segment in the chain. The current loop finds a segment in the chain, but not necessarily the first one (start point). It looks for seq > 1 to stop? No, it continues WHILE index matches AND seq > 1. So it stops when seq == 1 OR index doesn't match. This actually finds the segment with seq==1. However, there is a bigger issue: the problem output format requires ONLY the result, but the code prints debug info below.
        ;
    printf("%d %d %d\n", INDEX[0].num, input[x].x1, input[x].y1);
    for (int y = 0; y < count; y++) { // @@ This loop prints extra debug information which violates the output format requirement ("Print the maximum number... followed by coordinates..."). The judge expects only one line of output.
        printf("%d %d\n", INDEX[y].ind, INDEX[y].num);
    }
    return 0;
}