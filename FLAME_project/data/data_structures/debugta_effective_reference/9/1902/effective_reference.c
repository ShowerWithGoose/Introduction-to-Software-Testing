#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct line{
    int x1;
    int y1;
    int x2;
    int y2;
    int line;
    int cnt;
}Line;

Line all[200];
Line begin;

int cmp(const void*a,const void*b){
    Line *c=(Line *)a;
    Line *d=(Line *)b;
    if(c->x1!=d->x1) return c->x1>d->x1?1:-1;
    else return c->y1>d->y1?1:-1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&all[i].x1,&all[i].y1,&all[i].x2,&all[i].y2);
        all[i].line=1;
        all[i].cnt=1;
    }
    qsort(all,n,sizeof(all[0]),cmp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||all[j].line==0) continue;
            if(all[i].x2==all[j].x1&&all[i].y2==all[j].y1){
                all[i].x2=all[j].x2;
                all[i].y2=all[j].y2;
                all[i].cnt+=all[j].cnt;
                all[j].cnt=0;
                all[j].line=0;
            }
        }
    }
    int max=0;
    int id=0;
    for(int i=0;i<n;i++){
        if(all[i].cnt>max&&all[i].line){
            max=all[i].cnt;
            id=i;
        }
    }
    printf("%d %d %d\n",max,all[id].x1,all[id].y1);
    return 0;
}
