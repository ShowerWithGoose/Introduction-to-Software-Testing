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
                lines[i].n += lines[flag].n; // @@ After merging two segments, the old segment at lines[flag] is not removed from the array and num is not decremented, leading to duplicate entries and incorrect segment counts.
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
    }else{ // @@ The comparison function does not return 0 when d1->xstart == d2->xstart, violating qsort's requirement for a strict weak ordering and potentially causing undefined behavior or incorrect sorting.
        return 1;
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