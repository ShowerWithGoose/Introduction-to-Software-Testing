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
            if(xd[i].x2==xd[num].x1&&xd[i].y2==xd[num].y1){ // @@ The condition checks for connection in the wrong direction; should be xd[i].x1==xd[num].x2 && xd[i].y1==xd[num].y2 to match the forward direction (x1 < x2).
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
            if(xd[i].x1==xd[num].x2&&xd[i].y1==xd[num].y2){ // @@ This condition is correct for forward connection, but the function name "hou" suggests it should handle backward connections; however, the loop only goes forward (i=num+1), so it may miss segments that connect from the left.
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
            combo+=qian(xd,i);
            bcombo=0;
            combo+=hou(xd,i);
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
        if(xd[i].x2==xd[ree].x1&&xd[i].y2==xd[ree].y1){ // @@ This loop attempts to find the starting point by tracing backward, but it may get stuck in an infinite loop if multiple segments match or if ree is not updated correctly; also, it does not handle the case where no backward connection exists.
            ree=i;
            goto A;
        }
    }
    rex1=xd[ree].x1,rey1=xd[ree].y1;
    printf("%d %d %d",maxcombo+1,rex1,rey1);

    return 0;
}