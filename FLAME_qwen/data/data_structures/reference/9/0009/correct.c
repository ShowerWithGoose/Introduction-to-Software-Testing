#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct point
{
	int x[2],y[2];
}p1[1000];
typedef struct point p;
int cmp2(const void*p1,const void*p2);
int cmp2(const void*p1,const void*p2)
{
	struct point *a=(struct point*)p1;
	struct point *b=(struct point*)p2;
	if(a->x[0] != b->x[0]) return a->x[0]-b->x[0];
	else return a->y[0]-b->y[0];
}

int n,cnt=1,i,j,f=0,c,d,k;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d %d %d %d",&p1[i].x[0],&p1[i].y[0],&p1[i].x[1],&p1[i].y[1]);
	qsort(p1,n,sizeof(p),cmp2);//结构体二级排序（先排横坐标，如果横坐标相同，排纵坐标） 
	for(i=0;i<n;i++)
	{
		k=i;
		cnt=1;
	   for(j=i+1;j<n;j++)
	   {
		if(i==j)
		continue;
		else if(p1[j].x[0]==p1[k].x[1]&&p1[j].y[0]==p1[k].y[1])
		{
		   cnt++;
		   k=j;
		} 
	   }
	if(cnt>f)
        {
            f=cnt;
            c=p1[i].x[0];
            d=p1[i].y[0];
        }//如果这条线段更长就更新
	}
	
    printf("%d %d %d",f,c,d);
return 0;
}



