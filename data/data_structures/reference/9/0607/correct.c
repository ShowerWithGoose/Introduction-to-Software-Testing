#include<stdio.h>
#include<stdlib.h>
struct node{
	int x1,x2,y1,y2;
	int from,to;
	int tot;
}l[110];

int cmp(const void *m,const void *n){
	struct node x=*(struct node*)m;
	struct node y=*(struct node*)n;
	if(x.x1<y.x1) return -1;
	if(x.x1>y.x1) return 1;
	return x.y1<y.y1?-1:1;
}

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		l[i].tot=1; l[i].from=l[i].x1; l[i].to=l[i].y1;
	}
	qsort(l+1,n,sizeof(l[1]),cmp);
	//for(i=1; i<=n; i++){
	//	printf("%d:%d %d %d %d\n",i,l[i].x1,l[i].y1,l[i].x2,l[i].y2);
	//}
	int j;
	for(i=1; i<=n; i++){
		for(j=i+1; j<=n; j++){
			if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1){
				l[j].tot=l[i].tot+1;
				l[j].from=l[i].from;
				l[j].to=l[i].to;
			}
		}
	}
	int max=l[1].tot,p=1;
	for(i=1; i<=n; i++)
		if(max<l[i].tot){
			max=l[i].tot; p=i;
		}
	printf("%d %d %d\n",max,l[p].from,l[p].to);
	return 0;
}




