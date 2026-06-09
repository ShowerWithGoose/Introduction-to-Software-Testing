#include <stdio.h>
struct line{
    int x1;
    int x2;
    int y1;
    int y2;
}dot[1050];
int main(){
    int i,j,l=1,n,m,max,fin=1,num[100]={0},temp;
    int headx,heady,tailx,taily;
    for(int q=1;q<100;q++){
        num[q]=1;
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&dot[i].x1,&dot[i].y1,&dot[i].x2,&dot[i].y2);
    }
    for(i=1;i<=n;i++){
        tailx=dot[i].x2;
        taily=dot[i].y2;
        for(j=1;j<=n;j++){
            if(tailx==dot[j].x1&&taily==dot[j].y1)
            {
                num[i]++;
                tailx=dot[j].x2;
                taily=dot[j].y2;
                j=1; // @@ 应改为 j=0; 以使下一循环从 j=1 开始，否则当前设置 j=1 后循环的 j++ 会使其变成 j=2，从而跳过索引1，导致无法继续搜索后续匹配的线段。
            }
        }
    }
    max=num[1];
    //处理max==num[1]的情况
    for(i=1;i<=n;i++){
        if(max<num[i]){
            max=num[i];
            fin=i;
        }
    }
    printf("%d %d %d",max,dot[fin].x1,dot[fin].y1);
    return 0;
}