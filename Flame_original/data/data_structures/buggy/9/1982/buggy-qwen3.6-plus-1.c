#include <stdio.h>
struct line{
    int x1;
    int x2;
    int y1;
    int y2;
}dot[1050];
int main(){
    int i,j,l=1,n,m,max,fin=1,num[100]={0},temp; // @@ The array num has size 100, but n can be up to 1000 (dot is size 1050), leading to out-of-bounds access. It should be at least 1050.
    int headx,heady,tailx,taily;
    for(int q=1;q<100;q++){ // @@ The loop bound 100 should match the corrected size of num (e.g., 1050) to ensure all elements are initialized to 1.
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
                j=1; // @@ Resetting j to 1 causes the for-loop increment to make j=2 in the next iteration, skipping index 1. It should be j=0.
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