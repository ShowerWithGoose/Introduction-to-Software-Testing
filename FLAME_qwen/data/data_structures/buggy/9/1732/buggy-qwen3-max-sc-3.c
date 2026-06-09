#include<stdio.h>
int cnt[100];
int main(){
    int n;
    scanf("%d", &n);
    struct dot{
        int head[2];
        int tail[2];
    };
    struct dot a[101];
    struct dot tmp;
    int i, j;
    for(i = 1;i <= n;i++){
        scanf("%d%d%d%d", &a[i].head[0], &a[i].head[1], &a[i].tail[0], &a[i].tail[1]);
    }
    for(i = 0;i < n;i++){//按起点横坐标从小到大排序 
        for(j = i;j <n;j++){
            if(a[i].head[0] > a[j].head[0]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    } @@ [The sorting loop uses indices starting from 0 but the input was stored starting from index 1, causing uninitialized data (a[0]) to be used in sorting and processing. This leads to undefined behavior and incorrect results.]
    int cnt_max = 1, x = 0, y = 0;
    for(i = 0;i < n;i++){
        int cnt = 1,x2,y2;
        x2 = a[i].tail[0];
        y2 = a[i].tail[1];
        for(j = i+1;j < n;j++){
         if(x2==a[j].head[0]&&y2==a[j].head[1]){
          cnt++;
          x2 = a[j].tail[0];
          y2 = a[j].tail[1];
        }    
        }
        if(cnt > cnt_max){
            cnt_max = cnt;
            x = a[i].head[0];
            y = a[i].head[1];
        }
    } @@ [The algorithm only extends forward from each segment and does not consider backward extension (i.e., connecting segments that end at the current segment's start). Thus, it fails to find the true longest continuous chain when the maximum chain requires prepending segments.]
    printf("%d %d %d\n", cnt_max, x, y);
return 0;
}