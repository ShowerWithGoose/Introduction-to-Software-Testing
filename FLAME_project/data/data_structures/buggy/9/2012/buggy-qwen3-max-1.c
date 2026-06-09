#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
struct left{
    int x1;
    int y1;
};
struct right{
    int x2;
    int y2;
};
struct left left1[105],temp1,min[105];
struct right right1[105],temp2,max[105];
int cnt[105],flag[105],ans,ans1;
 
int main(){
    
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d%d",&left1[i].x1,&left1[i].y1);
    scanf("%d%d",&right1[i].x2,&right1[i].y2);
}//录入 
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(left1[j].x1<left1[i].x1){
            temp1=left1[j];temp2=right1[j];
            left1[j]=left1[i];right1[j]=right1[i];
            left1[i]=temp1;    right1[i]=temp2;
        }
    
    }
}//按左端点的x值排序 
for(int i=0;i<n;i++){
    if(flag[i]==0){
        min[i]=left1[i];
        max[i]=right1[i];
    for(int j=i;j<n;j++){
        if(left1[j].x1==max[i].x2&&left1[j].y1==max[i].y2){
            flag[j]=1;
            max[i]=right1[j];
            cnt[i]++;
        }
    }    
    }
} // @@ [The inner loop only checks segments from index i onward, but after connecting a segment j, it should continue checking from the new endpoint (max[i]) against all remaining unconnected segments, not just those with index >= i. This causes missed connections in chains that are not contiguous in the sorted array. Also, flag[i] is never set to 1, so the same starting segment may be reused incorrectly.]
for(int i=0;i<n;i++){
    ans=cnt[0];
    if(ans<cnt[i]){
        ans=cnt[i];
        ans1=i;
    }
} // @@ [Initialization 'ans=cnt[0]' inside the loop causes incorrect comparison; it should be initialized once before the loop.]
printf("%d %d %d",ans+1,left1[ans1].x1,left1[ans1].y1);
return 0;
}