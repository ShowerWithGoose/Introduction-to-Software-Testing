//
// Created by  on 2022/3/24.
//
#include "stdlib.h"
#include "stdio.h"
typedef struct {
    int x1,y1,x2,y2;
}line;
int cmp(const void *a,const void *b){
    return ((line *)a)->x2-((line *)b)->x2;
}
int n,rec[20000][20000];
int top,x,y;
//rec[x][y]表示点(x,y)后连接的点的个数
line a[100+7];
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        }
    qsort(a+1,n,sizeof(a[0]),cmp);
    //printf("n = %d\n",n);
    //for(int i=n;i>=1;i--) printf("i = %d and a[i].x2 = %d \n",i,a[i].x2);
    for(int i=n;i>=1;i--){
        rec[a[i].x1][a[i].y1]=rec[a[i].x2][a[i].y2]+1;
        if(rec[a[i].x1][a[i].y1]>top) {
            top=rec[a[i].x1][a[i].y1];
            x=a[i].x1;
            y=a[i].y1;
        }
    }

    printf("%d %d %d\n", top, x, y);
    return 0;
}
