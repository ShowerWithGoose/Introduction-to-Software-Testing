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
    for(i = 0;i < n;i++){//按起点横坐标从小到大排序 @@ Error: uses uninitialized a[0] and misses a[n]; should start from 1 and go to n
        for(j = i;j <n;j++){ @@ Error: condition j < n misses a[n]; should be j <= n
            if(a[i].head[0] > a[j].head[0]){ @@ Error: due to indexing error, compares uninitialized a[0] and misses a[n]
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    int cnt_max = 1, x = 0, y = 0;
    for(i = 0;i < n;i++){ @@ Error: uses uninitialized a[0] and misses a[n]; should start from 1 to n
        int cnt = 1,x2,y2;
        x2 = a[i].tail[0];
        y2 = a[i].tail[1];
        for(j = i+1;j < n;j++){ @@ Error: condition j < n misses a[n]; should be j <= n
         if(x2==a[j].head[0]&&y2==a[j].head[1]){ @@ Error: due to indexing error, may compare with a[0] or miss a[n]
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