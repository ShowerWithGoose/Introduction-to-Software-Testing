#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
    int xdnum;
}xianduan;
xianduan xd[100],xmax;
int rise(const void*p1,const void*p2){
    xianduan *d1=(xianduan*)p1,*d2=(xianduan*)p2;
    if(d1->x1>d2->x1)return 1;
    else if(d1->x1<d2->x1)return -1;
    else return 0;
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);      
        xd[i].xdnum=1;
    }
    qsort(xd,n,sizeof(xd[0]),rise);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((xd[i].x2==xd[j].x1)&&(xd[i].y2==xd[j].y1)){
                xd[i].xdnum=xd[i].xdnum+1;
                xd[i].x2=xd[j].x2; // @@ The logic modifies the current segment's endpoint to extend it, but fails to mark the consumed segment (xd[j]) as used. This allows xd[j] to be potentially counted again or interferes with subsequent checks if not handled correctly. More critically, this greedy extension without marking visited nodes can lead to incorrect counts in complex chains, although for simple chains it might work if sorted. However, the primary issue is that it doesn't skip processed segments properly in the inner loop or update the search state correctly for multi-segment chains.
                xd[i].y2=xd[j].y2; // @@ Same as above, updating endpoint without proper chain management.
                printf("%d %d %d %d\n",xd[j].x1,xd[j].y1,xd[j].x2,xd[j].y2); 
            }
        }
    }
    xmax=xd[0];
    for(i=0;i<n;i++){
        if(xd[i].xdnum>xmax.xdnum)xmax=xd[i];
    }
    printf("%d %d %d",xmax.xdnum,xmax.x1,xmax.y1);
}