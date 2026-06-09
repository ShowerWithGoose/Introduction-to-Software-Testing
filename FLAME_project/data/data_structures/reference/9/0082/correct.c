#include <stdio.h>
typedef struct{
    int x;
    int y;
    int x1;
    int y1;
}xiandai;
int ans,ans1,ans2;
xiandai a[150];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].x1,&a[i].y1);
    }
    for(i=0;i<n;i++){
        int tmp=1;
        int tmp1=a[i].x1,tmp2=a[i].y1;
        while(1){
            for(j=0;j<n;j++){
                if(a[j].x==tmp1&&a[j].y==tmp2){
                    tmp1=a[j].x1;
                    tmp2=a[j].y1;
                    tmp++;
                    break;
                }
            }
            if(j==n) break;
        }
        if(tmp>ans){
            ans=tmp;
            ans1=a[i].x;
            ans2=a[i].y;
        }
    }
    printf("%d %d %d",ans,ans1,ans2);


}


