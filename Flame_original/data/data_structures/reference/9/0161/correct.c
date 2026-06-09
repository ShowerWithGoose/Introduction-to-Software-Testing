#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct xd{
	int x1,x2,y1,y2;
};

int cmp(const void *a,const void *b){
	struct xd *c = (struct xd *) a;
	struct xd *d = (struct xd *) b;
	if(c->x1>d->x1) return 1;
	else return -1;
}

int main()
{
	int i,j,n,len,lenmax=0,start_x,start_y;
	struct xd point[200],next;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d %d %d %d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
	qsort(point,n,sizeof(point[0]),cmp);
	for(i=0;i<n;i++){
		len=1;
		next.x2=point[i].x2;next.y2=point[i].y2;
		for(j=i+1;j<n;j++){
			if(next.x2==point[j].x1&&next.y2==point[j].y1){
				next.x2=point[j].x2;
				next.y2=point[j].y2;
				len++;
			}
		}
		if(len>lenmax){
			lenmax=len;
			start_x=point[i].x1;
			start_y=point[i].y1;
		}
	}
	printf("%d %d %d",lenmax,start_x,start_y);
	return 0;
}

