# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
struct data{
    int x1,x2,y1,y2;
};
int cmp(const void * a, const void * b){
    struct data*c=(struct data*)a;
    struct data*d=(struct data*)b;
    return c->x1-d->x1;
}
int main() {
    int n,cnt=0,ans,xt,yt,x,y;
    struct data data[110];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);
    qsort(data,n,sizeof(struct data),cmp);
    for(int i=0;i<=n;i++) {
        ans=1;xt=data[i].x2;yt=data[i].y2;
        for (int j = i + 1; j <= n; j++) {
            if (xt == data[j].x1&&yt== data[j].y1) {
                ans++;
                xt=data[j].x2;yt=data[j].y2;
            }
        }
        if(ans>cnt){
            cnt=ans;
            x=data[i].x1;
            y=data[i].y1;
        }
    }
    printf("%d %d %d",cnt,x,y);
    return 0;
}
