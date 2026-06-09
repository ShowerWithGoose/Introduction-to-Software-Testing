#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct xianduan{
    int x1,x2,y1,y2,index;
}line[105];
int main(){
    int i,j,k,n,cnt=0,max=-1000000,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
                line[i].index=j;
            }
        }
    }
    for(i=1;i<=n;i++){
        cnt=0;
        j=i;
        while(1){
            if(line[j].index!=0){
                j=line[j].index;
                cnt++;
            }
            else break;
        }
        if(max<=cnt){
            max=cnt;
            m=i;
        }
    }
    printf("%d %d %d",max+1,line[m].x1,line[m].y1);
    return 0;
}
