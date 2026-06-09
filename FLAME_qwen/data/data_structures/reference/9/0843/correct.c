#include<stdio.h>
#include<stdlib.h>
struct line
    {
        int x1;
        int y1;
        int x2;
        int y2;
        int number;
        int key;
    };
    struct line segment[105],p[105];
int cmp(const void *a,const void *b){
    return ((struct line *)a)->x1-((struct line *)b)->x1;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;} 
int main(){
    int n,j,i,Max=0,l=0,k=1,m=0,Min=999,miny1=0;
    scanf("%d",&n);
    for(i=0;i<=n;i++) {segment[i].number=1; segment[i].key=0;}
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&segment[i].x1,&segment[i].y1,&segment[i].x2,&segment[i].y2);
    }
    qsort(segment,n,sizeof(struct line),cmp);
    for(i=0;i<n;i++){
       for(j=0;j<i;j++){
       if(segment[j].x2==segment[i].x1&&segment[j].y2==segment[i].y1){
            if(segment[j].number==1){
                segment[j].key=k;
                segment[i].key=k;
                k++;
              }
              segment[i].key=segment[j].key;
              segment[i].number+=segment[j].number;
            }
        }
    }
    for(i=0;i<n;i++){
        Max=max(segment[i].number,Max);
    }
    for(i=0;i<n;i++){
        if(Max==segment[i].number){
                l=i;
        }
    }
    for(i=0;i<n;i++){
        if(segment[i].key==segment[l].key){
            p[m++]=segment[i];
        }
    }
    for(i=0;i<m-1;i++){
        Min=min(p[i].x1,Min);
        if(Min==p[i].x1){
            miny1=p[i].y1;
        }
    }
    printf("%d %d %d",Max,Min,miny1);
    return 0;
}
