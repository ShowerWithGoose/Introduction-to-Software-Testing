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
    for(i = 0;i < n;i++){ // @@ i starts from 0 but array a is filled from index 1, so a[0] is uninitialized; this causes undefined behavior in sorting.
        for(j = i;j <n;j++){ // @@ inner loop also uses indices from 0 to n-1, but a[0] is garbage; sorting logic is flawed.
            if(a[i].head[0] > a[j].head[0]){ // @@ uses uninitialized a[0] when i=0; leads to incorrect sorting.
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    int cnt_max = 1, x = 0, y = 0;
    for(i = 0;i < n;i++){ // @@ i starts from 0; a[0] is uninitialized, so this loop processes garbage as a segment.
        int cnt = 1,x2,y2;
        x2 = a[i].tail[0]; // @@ when i=0, a[0] is junk, so x2 gets undefined value.
        y2 = a[i].tail[1];
        for(j = i+1;j < n;j++){ // @@ only checks segments after i; misses segments that connect to the current segment's head (backward expansion), which may be before i in the sorted array.
         if(x2==a[j].head[0]&&y2==a[j].head[1]){ // @@ only checks forward connections; does not check backward connections (list[k].x2 == xs && list[k].y2 == ys) as in the reference program.
          cnt++;
          x2 = a[j].tail[0];
          y2 = a[j].tail[1];
        }    
        }
        if(cnt > cnt_max){
            cnt_max = cnt;
            x = a[i].head[0]; // @@ starting point may be incorrect because backward connections were not considered; the true starting point of the chain might have smaller x1.
            y = a[i].head[1];
        }
    }
    printf("%d %d %d\n", cnt_max, x, y);
return 0;
}