#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

struct line{
	int x0,y0,x1,y1;
	struct line* p;
}a[110];

int cmp(const void*a,const void*b);

int main()
{
	int sx,sy,i,j,k,count,max,n;max=-1;count=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x0,&a[i].y0,&a[i].x1,&a[i].y1);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(a[i].x1==a[j].x0&&a[i].y1==a[j].y0){
				count++;
				i=j;
			}
		}
		if(count>max){
			sx=a[k].x0;
			sy=a[k].y0;
			max=count;
		}
		count=1;
		i=k;
	}
	printf("%d %d %d",max,sx,sy);
 	return 0;
}

int cmp(const void*a,const void*b){
	struct line*a1=(struct line*)a;
	struct line*b1=(struct line*)b;
	return a1->x0-b1->x0; 
}

