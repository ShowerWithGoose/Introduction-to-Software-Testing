#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct data{

     int x1;
     int y1;
     int x2;
     int y2;
}xy[500];
int main()
{
    struct data xy[500];
    int i,j,n,temp,maxx,maxy,leng=1,max=0,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&xy[i].x1,&xy[i].y1,&xy[i].x2,&xy[i].y2);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(xy[j].x1>xy[j+1].x1){
                temp=xy[j].x1;
                xy[j].x1=xy[j+1].x1;
                xy[j+1].x1=temp;
                temp=xy[j].y1;
                xy[j].y1=xy[j+1].y1;
                xy[j+1].y1=temp;
                temp=xy[j].x2;
                xy[j].x2=xy[j+1].x2;
                xy[j+1].x2=temp;
                temp=xy[j].y2;
                xy[j].y2=xy[j+1].y2;
                xy[j+1].y2=temp;
            }
        }
    }
    for(i=0;i<n;i++){
          leng=1;
        for(j=i+1;j<n;j++){
            if(xy[i].x2==xy[j].x1&&xy[i].y2==xy[j].y1){
                leng=leng+1;
                xy[i].x2=xy[j].x2;
                xy[i].y2=xy[j].y2;
            }
        }
        if(leng>max){
                max=leng;
            maxx=xy[i].x1;
            maxy=xy[i].y1;
        }

    }
    printf("%d %d %d ",max,maxx,maxy);

}

