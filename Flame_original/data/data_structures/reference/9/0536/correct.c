#include <stdio.h>
#include <stdlib.h>
struct point{
       int x;
       int y;
    };
int test(struct point[],struct point[],int,int);
int main()
{
    int n,i,j,flag,max=1,m;
    struct point p1[100],p2[100],p,start;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&p1[i].x,&p1[i].y,&p2[i].x,&p2[i].y);
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
                if(p1[j].x>p1[j+1].x){
                    p=p1[j];
                    p1[j]=p1[j+1];
                    p1[j+1]=p;
                    p=p2[j];
                    p2[j]=p2[j+1];
                    p2[j+1]=p;
                    flag=1;
                }
        }
        if(flag==0)
            break;
    }
    for(i=0;i<n;i++){
        m=test(p1,p2,i,n);
        if(m>=max){
            max=m;
            start=p1[i];}
    }
    printf("%d %d %d\n",max,start.x,start.y);
    return 0;
}
int test(struct point p1[],struct point p2[],int i,int n)
{
     int j,m=1;
     for(j=i+1;j<n;j++)
        if((p1[j].x==p2[i].x)&&(p1[j].y==p2[i].y))
            m+=test(p1,p2,j,n);
     return m;
}

















