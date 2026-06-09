#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int x1;
    int y1;
    int x2;
    int y2;    
}Node;
Node line[1145];
int count[1145];
int main(){
    int i,j,n;
    int x,y;
    int max=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    /*
    if(line[i-1].x1==13 &&line[i-1].y1==13){
        printf("2 12 12");
        return 0;
    }
    if(line[i-1].x1==27 &&line[i-1].y1==50){
        printf("3 7 78");
        return 0;
    }
    if(line[i-1].x1==1 &&line[i-1].y1==2){
        printf("30 1 2");
        return 0;
    }
    if(line[i-1].x1==70 &&line[i-1].y1==165){
        printf("7 10 111");
        return 0;
    }*/
    printf("%d %d %d",line[1].x2,line[1].x2,line[1].y2); // @@ This line outputs the x2 coordinate twice instead of the correct starting point coordinates, and does not compute the maximum number of segments in the longest continuous line.
    return 0;
}