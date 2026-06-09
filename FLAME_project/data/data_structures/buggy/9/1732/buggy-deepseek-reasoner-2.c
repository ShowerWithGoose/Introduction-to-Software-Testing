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
    for(i = 0;i < n;i++){//按起点横坐标从小到大排序  // @@ [should start from 1 because data is stored from index 1; using index 0 accesses uninitialized memory]
        for(j = i;j <n;j++){ // @@ [inner loop should go to j<=n to include the last valid index; starting j from i (which may be 0) also accesses uninitialized a[0]]
            if(a[i].head[0] > a[j].head[0]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    int cnt_max = 1, x = 0, y = 0;
    for(i = 0;i < n;i++){ // @@ [should start from 1; using a[0] which is uninitialized leads to incorrect chain detection]
        int cnt = 1,x2,y2;
        x2 = a[i].tail[0];
        y2 = a[i].tail[1];
        for(j = i+1;j < n;j++){ // @@ [inner loop should go to j<=n to include the last segment; also j starts from i+1 which may be 1, but outer i=0 is invalid]
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
    }
    printf("%d %d %d\n", cnt_max, x, y);
return 0;
}