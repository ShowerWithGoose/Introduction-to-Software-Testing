#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include <ctype.h> 
int count;int sign[105]={0};int bcombo;
typedef struct{
    int x1,y1,x2,y2;
}XD;
int qian(XD xd[105],int num){
    sign[num]=1;
    for(int i=num+1;i<count;i++){
        if(sign[i]==0){
            if(xd[i].x2==xd[num].x1&&xd[i].y2==xd[num].y1){
                sign[i]=1;
                bcombo++;
                qian(xd,i);
            }
        }
    }
    return bcombo;
}
int hou(XD xd[105],int num){
    sign[num]=1;
    for(int i=num+1;i<count;i++){
        if(sign[i]==0){
            if(xd[i].x1==xd[num].x2&&xd[i].y1==xd[num].y2){
                sign[i]=1;
                bcombo++;
                hou(xd,i);
            }
        }
    }
    return bcombo;
}
int main()
{
    XD xd[105];
    int n,re;
    int combo=0,maxcombo=0;
    scanf("%d",&n);
    
    for(count=0;count<n;count++){
        scanf("%d%d%d%d",&xd[count].x1,&xd[count].y1,&xd[count].x2,&xd[count].y2);
    }
    for(int i=0;i<count;i++){
        if(sign[i]==0){
            bcombo=0;
            combo+=qian(xd,i); // @@ The logic for finding the longest chain is flawed. It attempts to traverse backwards and forwards from each unvisited node, but `sign` array prevents revisiting nodes across different iterations of the outer loop, effectively breaking the graph into disconnected components based on visitation order rather than true connectivity. Also, `combo` accumulates incorrectly across different starting nodes if `sign` wasn't reset, but here `sign` is global and never reset, so once a node is visited in one chain, it's ignored in others. This prevents finding the true maximum chain if the optimal chain shares nodes with a previously explored (but shorter or different) path, or if the traversal order misses connections. More critically, the `qian` and `hou` functions only look at indices `num+1` to `count`, missing connections to segments with lower indices that might be part of the same chain.
            bcombo=0;
            combo+=hou(xd,i); // @@ Same issue as above: `hou` only looks forward in the array index, missing potential connections to segments earlier in the array that extend the chain.
            if(combo>maxcombo){
                re=i;
                maxcombo=combo;
            }
            combo=0;
        }
    }
    int rex1,rey1;
    int ree=re;
    A:for(int i=0;i<count;i++){
        if(xd[i].x2==xd[ree].x1&&xd[i].y2==xd[ree].y1){
            ree=i;
            goto A;
        }
    }
    rex1=xd[ree].x1,rey1=xd[ree].y1;
    printf("%d %d %d",maxcombo+1,rex1,rey1);

    return 0;
}