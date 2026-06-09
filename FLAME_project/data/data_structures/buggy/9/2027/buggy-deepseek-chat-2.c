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
        for(int j=0;j<n;j++){
            if(i==j)
            continue;
            if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2){//说明i不是起点
                flag=1;
            }
            if(flag==0){
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