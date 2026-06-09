#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct place{
    int x;
    int y;
}place;

typedef struct line{
    place start;
    place end;
    int count;
    int val;
}line;


int main(){
    int n;
    int max=0;
    line lines[101];
    scanf("%d\n",&n);
    int i=0;
    
    
    
    while(n--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
        int mark=0;
        int head=0,tail=0;
        for(int j=0;j<i;j++){
            if(!lines[j].val)continue;
            if(x1==lines[j].end.x && y1== lines[j].end.y){
                head=j;
                lines[j].count++;
                max=lines[max].count<lines[j].count?j:max;
                lines[j].end.x=x2;
                lines[j].end.y=y2;
                mark++;
            }
            else if(x2==lines[j].start.x &&y2==lines[j].start.y){
                tail=j;
                lines[j].count++;
                max=lines[max].count<lines[j].count?j:max;
                lines[j].start.x=x1;
                lines[j].start.y=y1;
                mark++;
            }
        }
        if(!mark){
            lines[i].count=1;
            lines[i].start.x=x1;
            lines[i].start.y=y1;
            lines[i].end.x=x2;
            lines[i].end.y=y2;
            lines[i].val=1;
            i++;
        }
        if(mark==2){
            lines[head].count+=lines[tail].count-1;
            max=lines[max].count<lines[head].count?head:max;
            lines[head].end.x=lines[tail].end.x;
            lines[head].end.y=lines[tail].end.y;
            lines[tail].val=0;
        }
    }
    
    printf("%d %d %d",lines[max].count,lines[max].start.x,lines[max].start.y);
    return 0;
}

