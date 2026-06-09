#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int l[107][4];
int cmp(int(*a)[4],int(*b)[4]){
	if((*a)[0]>(*b)[0])return 1;
	else return -1;
}
typedef struct line {
	int x1;
	int y1;
	int x2;
	int y2;
	struct line*link;
} LINE;
int main(){
	int n;
	scanf("%d",&n);
	FOR(i,0,n)scanf("%d%d%d%d",l[i],l[i]+1,l[i]+2,l[i]+3);
	qsort(&l[0],n,4*sizeof(int),cmp);
	LINE*p;
	LINE*roots[107];
	int r=0;
	FOR(i,0,n){
		p=malloc(sizeof(LINE));
		p->x1=l[i][0];
		p->y1=l[i][1];
		p->x2=l[i][2];
		p->y2=l[i][3];
		p->link=NULL;
		FOR(j,0,r)if(roots[j]->x2==p->x1&&roots[j]->y2==p->y1)p->link=roots[j],roots[j]=p;
		if(p->link==NULL)roots[r++]=p;
	}
	int m,max=0;
	LINE*longest;
	FOR(i,0,r){
		p=roots[i],m=0;
		while(p->link!=NULL)p=p->link,m++;
		if(m>max)max=m,longest=p;
	}
	printf("%d %d %d\n",max+1,longest->x1,longest->y1);
	return 0;
}

