#include <stdio.h>
struct line{
    int x1,y1,x2,y2;
};
int main(){
    int n;
    scanf("%d",&n);
    struct line l[n];
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    }
    int max=0;
    int hx[400]={0},hy[400]={0},ex[400]={0},ey[400]={0},c=0;
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n;j++){ // @@ The inner loop logic is flawed. It iterates through all segments j to check if segment i's start point connects to any segment j's end point. However, the `flag` check and assignment of `hx`, `hy`, etc., happen inside the loop but depend on `flag` which might be set by a previous iteration of `j`. More critically, if a segment is part of a chain, it might be counted multiple times or incorrectly identified as a start point because the logic doesn't correctly isolate unique starting segments of chains. The primary issue leading to Runtime Error (stack smashing) is likely array out-of-bounds access.
            if(i==j)
            continue;
            if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2){//说明i不是起点
                flag=1;
            }
            if(flag==0){ // @@ This condition is checked in every iteration of j. If flag becomes 1, it stays 1. But if flag is 0, it adds the segment to the list. This means for a segment that IS a start point, it will be added c times (once for each j where i!=j and the condition l[i].x1==l[j].x2... is false or not yet true). This causes `c` to grow much larger than `n`, potentially exceeding 400, leading to buffer overflow on hx, hy, ex, ey arrays.
                hx[c]=l[i].x1;
                hy[c]=l[i].y1;
                ex[c]=l[i].x2;
                ey[c]=l[i].y2;
                c++;
            }
        }
    }
    int tmp[400];
    for(int i=0;i<c;i++){
        tmp[i]=1;
        for(int j=0;j<n;j++){
            if(ex[i]==l[j].x1&&ey[i]==l[j].y1){
                ex[i]=l[j].x2;
                ey[i]=l[j].y2;
                tmp[i]++;
                j=-1;
            }
        }
    }
    int h=0;
    for(int i=0;i<c;i++){
        if(max<tmp[i]){
            max=tmp[i];
            h=i;
        }
    }
    printf("%d %d %d",max,hx[h],hy[h]);
    return 0;
}