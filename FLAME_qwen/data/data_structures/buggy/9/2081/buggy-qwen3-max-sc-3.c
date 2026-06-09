#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
}table[105];
struct group{
    int startx;
    int starty;
    int endx;
    int endy;
    int count;    
}total[105];
int cmp(const void*p,const void*q){
    int e1=((struct line*)p)->x1,e2=((struct line*)q)->x1;
    return (e1-e2);
}
int cmp2(const void*m,const void*n){
    int e1=((struct group*)m)->count,e2=((struct group*)n)->count;
    return (e2-e1);
}

int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&table[i].x1,&table[i].y1,&table[i].x2,&table[i].y2);
    qsort(table,n,sizeof(table[0]),cmp);
    total[0].startx=table[0].x1;
    total[0].starty=table[0].y1;
    total[0].endx=table[0].x2;
    total[0].endy=table[0].y2;
    total[0].count=1;
    int all=1;
    for(i=1;i<n;i++){
        for(j=0;j<all;j++){
            if(total[j].endx==table[i].x1&&total[j].endy==table[i].y1){
                total[j].endx=table[i].x2;
                total[j].endy=table[i].y2;
                total[j].count++;
                break;
            }
        }
        if(j==all){
            all++;
            total[all-1].startx=table[i].x1;
            total[all-1].starty=table[i].y1;
            total[all-1].endx=table[i].x2;
            total[all-1].endy=table[i].y2;
            total[all-1].count=1;
        }
    }
    qsort(total,all-1,sizeof(total[0]),cmp2); // @@ [The second argument to qsort should be 'all', not 'all-1', because 'all' is the number of valid groups in the 'total' array. Using 'all-1' excludes the last group from sorting, which may cause incorrect output when the longest chain is the last one added.]
    printf("%d %d %d\n",total[0].count,total[0].startx,total[0].starty);
    return 0;
}