#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
}lines[200];
int cmp(const void*a,const void*b){
	struct line*aa=(struct line*)a;
	struct line*bb=(struct line*)b;
    
    if((aa->x1)-(bb->x1)!=0)
	    return (aa->x1)-(bb->x1);
    else
        return (aa->x2)-(bb->x2);
}
int cmp1(const void*c,const void*d){
    struct line*cc=(struct line*)c;
	struct line*dd=(struct line*)d;
    return dd->num - cc->num;
}
int main(){
    int n, i, j, num;
    scanf("%d", &n);
    num = n;
    for (i = 0; i < n; i++){
        scanf("%d%d%d%d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
        lines[i].num = 1;
    }
    qsort(lines, n, sizeof(struct line), cmp);

    for (i = 0; i < n; i++){
        if(lines[i].num==0)
            continue;
        for (j = i + 1; j < n; j++){
            if(lines[j].num==0)
                continue;
            if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1){
                lines[i].x2 = lines[j].x2;
                lines[i].y2 = lines[j].y2;
                lines[i].num++;
                lines[j].num = 0;
                num--;
            }

        }
    }
    qsort(lines, n, sizeof(struct line), cmp1);
    printf("%d %d %d", lines[0].num, lines[0].x1, lines[0].y1);
    return 0;
}
