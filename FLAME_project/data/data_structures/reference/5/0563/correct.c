#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct loof{
	int x;//系数 
	int y;//指数 
};
int compare1(const void *a,const void *b){
	struct loof *c=(struct loof *)a;
	struct loof *d=(struct loof *)b;
	return (d->y)-(c->y);
}

int main()
{
	struct loof a[10000],b[10000],d[10000];
	char c;int f,g;int i=0;int j=0;
	do{
		scanf("%d%d%c",&f,&g,&c); 
		a[i].x=f;a[i].y=g;
		i++;
	}while(c!='\n');
	do{
		scanf("%d%d%c",&f,&g,&c); 
		b[j].x=f;b[j].y=g;
		j++;
	}while(c!='\n');
	int alen=i;int blen=j;
	i=0;j=0;int u=0;//用于记载 d的下标 
	for(i=0;i<alen;i++){
		for(j=0;j<blen;j++){
			d[u].x=a[i].x*b[j].x;
			d[u].y=a[i].y+b[j].y;
			u++;
		}
	}
	qsort(d,u,sizeof(d[0]),compare1);
	for(int n=0;n<u;n++){
		for(int r=n+1;r<u;r++){
			if(d[r].y==d[n].y){
				d[n].x=d[r].x+d[n].x;
				for(int t=r;t<u-1;t++){
					d[t]=d[t+1];
				}
		        u--;
		        r--;
			}
		}
	}
	qsort(d,u,sizeof(d[0]),compare1);
	for(int i=0;i<u;i++){
		if(d[i].x!=0)
		printf("%d %d ",d[i].x,d[i].y);
	}
	return 0;
 } 



