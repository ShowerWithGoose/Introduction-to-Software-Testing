#include <stdio.h>
struct LINE
{
    int x1;
    int y1;
    int x2;
    int y2;
};
int next(struct LINE line[], struct LINE lp, int len)
{
    int i;
    for(i = 0; i < len; i++){
        if((line[i].x1 == lp.x2) && (line[i].y1 == lp.y2)){
            return i;
        }
    }
    return -1;
}
int main()
{
    int n, i, j, np[100] = {0}, index;
    struct LINE line[100], lp, *q = NULL;
    q = line;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
    }
    for(i = 0; i < n; i++){
        np[i] = 1;
        lp = line[i];
        while(next(q, lp, n) != -1){
            j = next(line, lp, n);
            lp = line[j];
            np[i]++;
        }
    }
    index = 0;
    for(i = 0; i < n; i++){
        if(np[i] > np[index]){
            index = i;
        }
    }
    printf("%d %d %d", np[index], line[index].x1, line[index].y1);
    return 0;
}

