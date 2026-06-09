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
            combo+=qian(xd,i); // @@ [The function qian() only searches forward (i+1 to end) for segments that connect backward (current segment's start == another's end), but the loop in main starts from 0 and marks visited nodes. However, because qian() only checks indices > num, it may miss segments that appear before index 'num' in the array, leading to incomplete chain detection. Additionally, both qian() and hou() use a shared global 'sign' array and 'bcombo', causing interference between calls.]
            bcombo=0;
            combo+=hou(xd,i); // @@ [Similar to qian(), hou() only searches forward in the array (indices > num) for segments that continue forward (current segment's end == another's start). This misses segments that are located before index 'num' in the array, breaking the ability to form full chains. Also, using global 'bcombo' without proper reset or isolation leads to incorrect counts.]
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
            goto A; // @@ [This backward traversal to find the true starting point only checks segments where another segment ends at the current start. However, because the earlier logic (qian/ hou) did not correctly build the full chain due to directional search limitations, this may not find the actual beginning of the longest chain. Moreover, it doesn't consider that the correct start might not be reachable by only looking at segments with index < ree, especially since the array isn't sorted by connectivity.]
        }
    }
    rex1=xd[ree].x1,rey1=xd[ree].y1;
    printf("%d %d %d",maxcombo+1,rex1,rey1); // @@ [The final output adds 1 to maxcombo, assuming that combo counted connections rather than segments. However, due to flawed counting in qian() and hou() (which use a shared global bcombo and don't account for bidirectional chaining properly), maxcombo may not represent the correct number of connected segments minus one. Thus, the +1 may be applied to an already incorrect base value.]

    return 0;
}