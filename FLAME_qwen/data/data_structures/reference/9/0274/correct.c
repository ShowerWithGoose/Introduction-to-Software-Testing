#include<stdio.h>
#include<stdlib.h>
struct lines{
    int x1;
    int y1;
    int x2;
    int y2;
}line[111];
int cmp(const void *p1,const void *p2){
    struct lines *a=(struct lines *)p1;
    struct lines *b=(struct lines *)p2;
    if(a->x1>b->x1) return 1;
    else if(a->x1<b->x1) return -1;
    else return 0;
}
int main(){
    int n,i,j,k=0,x[111][2],p,max=0,Kmax=0;
    for(i=0;i<100;i++)
        for(j=0;j<2;j++)
            x[i][j]=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    qsort(line,n,sizeof(line[0]),cmp);
    for(i=0;i<n-1;i++){
        p=i;
        for(j=i+1;j<n;j++)
            if(line[p].x2==line[j].x1&&line[p].y2==line[j].y1){
                x[k][0]++;
                x[k][1]=i;
                p=j;
            }
        k++;
    }
    for(k=k+1;k>=0;k--)
        if(x[k][0]>max){
            max=x[k][0];
            Kmax=k;
        }
    printf("%d %d %d",max+1,line[Kmax].x1,line[Kmax].y1);
    return 0;
}
