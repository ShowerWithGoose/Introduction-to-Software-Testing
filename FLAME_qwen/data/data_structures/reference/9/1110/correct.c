#include<stdio.h>
#include<stdlib.h>
struct point{
    int x;
    int y;
};
typedef struct line{
    struct point v1;
    struct point v2;
}line;
line a[105];
int rank(const void *p1,const void *p2){
    line *a,*b;
    a=(line*)p1,b=(line*)p2;
    if(a->v1.x<b->v1.x)return -1;
    if(a->v1.x>b->v1.x)return 1;
    return 0;
}
int n;
int map[105][105];
int f(int x){
    int i,flag=0,max=0;
    for(i=x+1;i<n;i++){
        if(map[x][i]){
            flag=1;
        }
    }
    if(flag==0)return 1;
    for(i=x+1;i<n;i++){
        if(map[x][i]){
            if(f(i)+1>max)max=f(i)+1;
        }
    }
    return max;
}
int main(){
    int i,j,t;
    int max=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&a[i].v1.x,&a[i].v1.y,&a[i].v2.x,&a[i].v2.y);
    }
    qsort(a,n,sizeof(a[0]),rank);
    for(i=0;i<n;i++){
       for(j=i+1;j<n;j++){
           if(a[i].v2.x==a[j].v1.x&&a[i].v2.y==a[j].v1.y)map[i][j]=1;
       }
    }
    for(i=0;i<n;i++){
    	int num=f(i);
    	if(num>max){
    		max=num;
    		t=i;
		}
    }
    printf("%d ",max);
    printf("%d %d\n",a[t].v1.x,a[t].v1.y);
    return 0;
}
