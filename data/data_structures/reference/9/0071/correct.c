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
    int n,ANS=0,ans,xt,yt,x,y;
    struct data line[110];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    qsort(line,n,sizeof(struct data),cmp);
    for(int i=0;i<=n;i++) {
        ans=1;xt=line[i].x2;yt=line[i].y2;
        for (int j = i + 1; j <= n; j++) {
            if (xt == line[j].x1&&yt== line[j].y1) {
                ans++;
                xt=line[j].x2;yt=line[j].y2;
            }
        }
        if(ans>ANS){
            ANS=ans;
            x=line[i].x1;
            y=line[i].y1;
        }
    }
    printf("%d %d %d",ANS,x,y);
    return 0;
}
