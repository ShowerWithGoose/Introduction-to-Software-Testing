#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct line{
    int x1,y1,x2,y2,cot;
};
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    struct line p[105];
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
        p[i].cot=1;
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            for(k=1;k<=n;k++){
                if(p[j].x2==p[k].x1&&p[j].y2==p[k].y1){
                    p[i].cot++;
                    j=k-1;
                    break;
                }
            }
            if(k==n+1)
                break;
        }
    }
    int max=0;
    for(i=1;i<=n;i++){
        if(p[i].cot>max)
            max=p[i].cot;
    }
    for(i=1;i<=n;i++){
        if(p[i].cot==max){
            printf("%d %d %d",p[i].cot,p[i].x1,p[i].y1);
            break;
        }
    }
    return 0;
}

