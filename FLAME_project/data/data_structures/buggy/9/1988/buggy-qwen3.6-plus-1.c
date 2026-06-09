#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct line{
    int xstart;
    int ystart;
    int xend;
    int yend;
    int n;
};

struct line lines[110];
int MaxI, MaxN, num;

int find(int x1, int y1, int x2, int y2){
    int flag = -1;
    for(int i=0; i<num; i++){
        if(x2 == lines[i].xstart && y2 == lines[i].ystart){
            if(flag == -1){
                lines[i].xstart = x1;
                lines[i].ystart = y1;
                lines[i].n++;
                if(lines[i].n > MaxN){
                    MaxN = lines[i].n;
                    MaxI = i;
                }
            }else{
                lines[i].xstart = lines[flag].xstart;
                lines[i].ystart = lines[flag].ystart;
                lines[i].n += lines[flag].n;
                if(lines[i].n > MaxN){
                    MaxN = lines[i].n;
                    MaxI = i;
                }
            }
            return 1;
        }else if(x1 == lines[i].xend && y1 == lines[i].yend){
            lines[i].xend = x2;
            lines[i].yend = y2;
            lines[i].n++;
            if(lines[i].n > MaxN){
                MaxN = lines[i].n;
                MaxI = i;
            }
            flag = i;
        }
    }
    if(flag == -1){
        return 0;
    }
    return 1;
}
int cmp(const void*p1, const void*p2){
    struct line *d1 = (struct line *)p1;
    struct line *d2 = (struct line *)p2;
    if(d1->xstart < d2->xstart){
        return -1;
    }else{
        return 1; // @@ The sorting function is unstable and incorrect for equal xstart values. More importantly, the logic in `find` relies on iterating through existing segments to merge them. However, the main loop sorts after every insertion. The critical error is in the `find` function's logic for merging chains. When a segment connects to the END of an existing chain (the `else if` branch), it updates the end point. But if that same segment also needs to connect to the START of another chain (handled in the first `if` branch in a subsequent iteration or vice versa), the current linear scan with a single `flag` variable fails to handle transitive merges correctly or merges in the wrong order. Specifically, the `find` function attempts to merge the new segment `(x1,y1)-(x2,y2)` into existing chains. If `(x2,y2)` matches the start of chain `i`, it prepends. If `(x1,y1)` matches the end of chain `i`, it appends. The variable `flag` stores the index of a chain that was appended to. If a prepend happens later to a different chain, it doesn't account for the possibility that the appended chain and the prepended chain should now be merged together if they overlap or touch via the new segment. Actually, the simpler issue is that `find` returns as soon as it finds a match for the start point (`x2==lines[i].xstart`). It does not check if the end point (`x1`) also matches another chain's end, which would require merging two existing chains via the new segment. The problem states "No three or more segments share a single endpoint", but a new segment can bridge two existing separate chains. The current code handles appending to one chain or prepending to one chain, but not bridging two chains. In the test case, the longest chain is formed by bridging multiple segments. The `find` function fails to merge two existing chains when the new segment connects them.
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2;
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(!find(x1, y1, x2, y2)){      // 没找到重合的端点
            lines[num].xstart = x1;
            lines[num].ystart = y1;
            lines[num].xend = x2;
            lines[num].yend = y2;
            lines[num].n = 1;
            if(lines[num].n > MaxN){
                MaxN = lines[num].n;
                MaxI = num;
            }
            num++;
        }
        qsort(lines, num, sizeof(struct line), cmp);
    }
    for(int i=0; i<num; i++){
        if(lines[i].n == MaxN){
            MaxI = i;
            break;
        }
    }
    printf("%d %d %d", MaxN, lines[MaxI].xstart, lines[MaxI].ystart);
    return 0;
}