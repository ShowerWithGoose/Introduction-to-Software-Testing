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
    int num;
    int max=0;
    line lines[101];
    scanf("%d\n",&num);
    int index=0;
    
    
    
    while(num--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
        int flag=0;
        int i=0,j=0;
        for(int j=0;j<index;j++){
            if(!lines[j].val)continue;
            if(x1==lines[j].end.x && y1== lines[j].end.y){
                i=j;
                lines[j].count++;
                max=lines[max].count<lines[j].count?j:max;
                lines[j].end.x=x2;
                lines[j].end.y=y2;
                flag++;
            }
            else if(x2==lines[j].start.x &&y2==lines[j].start.y){
                j=j;
                lines[j].count++;
                max=lines[max].count<lines[j].count?j:max;
                lines[j].start.x=x1;
                lines[j].start.y=y1;
                flag++;
            }
        }
        if(!flag){
            lines[index].count=1;
            lines[index].start.x=x1;
            lines[index].start.y=y1;
            lines[index].end.x=x2;
            lines[index].end.y=y2;
            lines[index].val=1;
            index++;
        }
        if(flag==2){
            lines[i].count+=lines[j].count-1;
            max=lines[max].count<lines[i].count?i:max;
            lines[i].end.x=lines[j].end.x;
            lines[i].end.y=lines[j].end.y;
            lines[j].val=0;
        }
    }
    
    printf("%d %d %d",lines[max].count,lines[max].start.x,lines[max].start.y);
    return 0;
}

