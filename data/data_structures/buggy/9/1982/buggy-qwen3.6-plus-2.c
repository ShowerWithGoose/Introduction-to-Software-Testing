#include <stdio.h>
struct line{
    int x1;
    int x2;
    int y1;
    int y2;
}dot[1050];
int main(){
    int i,j,l=1,n,m,max,fin=1,num[100]={0},temp; // @@ Array size 100 is insufficient for n up to 1050, causing out-of-bounds access when n > 99.
    int headx,heady,tailx,taily;
    for(int q=1;q<100;q++){ // @@ Loop bound is fixed at 100 and executes before n is read, failing to initialize num correctly for all segments. Should be moved after scanf and bound set to n.
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
                j=1; // @@ Resetting j to 1 causes the for-loop increment to skip checking index 1 in the next iteration. Should be j=0 to correctly restart the search from the first segment.
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