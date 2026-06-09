#include <stdio.h>
int n;
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
int next[105]={};
int head[105]={};
int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    scanf("%d",&n);
    int i,j,k;
    struct line num[100];
    for(i=1;i<=n;i++){
        scanf("%d %d %d %d\n",&num[i].x1,&num[i].y1,&num[i].x2,&num[i].y2);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j&&num[i].x2==num[j].x1&&num[i].y2==num[j].y1){
                next[i]=j;
                head[j]=i;
            }
        }
    }
    int max=0,l,longest=0;
    for(i=1;i<=n;i++){
        if(head[i]==0){
            int tmp=num[i].x1,first=i;
            l=1,k=i;
            while(next[k]!=0){
                k=next[k];
                if(num[k].x1<tmp){
                    tmp=num[k].x1;
                    first=k;
                }
                l++;
            }
            if(l>longest){
                max=first;
                longest=l;
            }
        }
    }
    printf("%d %d %d",longest,num[max].x1,num[max].y1);
    return 0;
}


