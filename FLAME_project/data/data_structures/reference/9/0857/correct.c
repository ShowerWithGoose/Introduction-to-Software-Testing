#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
int cmp(const void*p1,const void*p2){
    struct line *a = (struct line*)p1;
    struct line *b = (struct line*)p2;
    return (a->x1 - b->x1);
}
int main(){
    typedef struct line LINE;
    LINE ap[105];
    int n;
    scanf("%d",&n);
    int i,j;
    for(i = 0;i < n;i++){
        scanf("%d %d %d %d",&ap[i].x1,&ap[i].y1,&ap[i].x2,&ap[i].y2);
    }
    int x,y;
    int sum = 0;
    qsort(ap,n ,sizeof(LINE),cmp);
    for(i = 0;i < n;i++){
        int temp = i;
        int temeach = 0;
        for(j = i+1;j<n;j++) {
            if (ap[temp].x2 == ap[j].x1 && ap[temp].y2 == ap[j].y1) {
                temp = j;
                temeach += 1;
            }
        }
        if(temeach > sum){
            sum = temeach;
            x = ap[i].x1;
            y = ap[i].y1;
        }
    }
    printf("%d %d %d",sum+1,x,y);
    return 0;
}


