#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct coordinate{
	int x;
	int y;
} C;
typedef struct line{
	C v1;
	C v2;
} L;
int cmpx(const void *p1,const void *p2){
	int a,b;
	L *l1=(L*)p1;
	L *l2=(L*)p2;
	a=l1->v1.x-l2->v1.x;
	if(a>0) b=1;
	if(a<0) b=-1;
	return b;
}
int main(){
	int N,i,j=0,k=1;
	scanf("%d",&N);
	L l[N];
	int cnt[N],m=0,n,p;
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&l[i].v1.x,&l[i].v1.y,&l[i].v2.x,&l[i].v2.y);
		cnt[i]=1;
	}
	qsort(l,N,sizeof(L),cmpx);
	for(i=0;i<N;i++){
		p=i;
		for(n=p+1;n<N;n++){
			if(l[p].v2.x==l[n].v1.x&&l[p].v2.y==l[n].v1.y){
				cnt[i]++;
				p=n;
			}
		}
	}
	for(k=1;k<i;k++){
		int d=cnt[k]-cnt[m];
		if(d>0) m=k;
	}
	printf("%d %d %d",cnt[m],l[m].v1.x,l[m].v1.y);
}


