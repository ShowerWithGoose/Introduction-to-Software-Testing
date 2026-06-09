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
    for(i = 1;i <= n;i++){ // @@ Array indexing mismatch: C arrays are 0-indexed. Reading into indices 1 to n leaves a[0] uninitialized, causing undefined behavior in subsequent 0-indexed loops. Should be `for(i = 0; i < n; i++)`.
        scanf("%d%d%d%d", &a[i].head[0], &a[i].head[1], &a[i].tail[0], &a[i].tail[1]);
    }
    for(i = 0;i < n;i++){//按起点横坐标从小到大排序  // @@ Loop bounds mismatch with input loop. If input is corrected to 0-based, this is correct. Otherwise, should be `for(i = 1; i <= n; i++)`.
        for(j = i;j <n;j++){
            if(a[i].head[0] > a[j].head[0]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    int cnt_max = 1, x = 0, y = 0;
    for(i = 0;i < n;i++){ // @@ Same indexing mismatch as above. Should align with corrected input loop bounds (0 to n-1).
        int cnt = 1,x2,y2;
        x2 = a[i].tail[0];
        y2 = a[i].tail[1];
        for(j = i+1;j < n;j++){ // @@ Same indexing mismatch. Should be `for(j = i + 1; j < n; j++)` if 0-based, or `j <= n` if 1-based.
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