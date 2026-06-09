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
            if(xd[i].x2==xd[num].x1&&xd[i].y2==xd[num].y1){ // @@ [Error: The condition checks for x2 and y2 matching x1 and y1, which would mean the current segment's start connects to another segment's end, but the logic for "qian" (forward) should check if the current segment's start connects to another segment's end, i.e., xd[i].x2 == xd[num].x1 && xd[i].y2 == xd[num].y1. However, the loop starts from num+1, but the segments are not sorted by x1, so this may miss connections or incorrectly assume order. The reference program sorts by x1 first, but this code does not sort, leading to incorrect traversal.]
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
            if(xd[i].x1==xd[num].x2&&xd[i].y1==xd[num].y2){ // @@ [Error: Similar issue as above; the condition checks for x1 and y1 matching x2 and y2, which is correct for "hou" (backward), but without sorting, the loop may not find all connections in the correct order. Additionally, the logic for "hou" should traverse backward, but the loop only goes forward from num+1, missing segments that might connect before num in the array.]
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
        if(xd[i].x2==xd[ree].x1&&xd[i].y2==xd[ree].y1){ // @@ [Error: This loop attempts to find the starting point by tracing backward, but it uses a goto and may get stuck in an infinite loop if there are cycles or if the condition is never met. Also, it does not handle the case where the starting point is already the first segment in the chain.]
            ree=i;
            goto A;
        }
    }
    rex1=xd[ree].x1,rey1=xd[ree].y1;
    printf("%d %d %d",maxcombo+1,rex1,rey1); // @@ [Error: maxcombo+1 assumes the count includes the starting segment, but the combo calculation in the loop may double-count or miscount segments because qian and hou are called separately and reset bcombo to 0, leading to an incorrect total count.]

    return 0;
}