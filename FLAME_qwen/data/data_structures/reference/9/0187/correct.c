#include<stdio.h>
#include<stdlib.h>
typedef struct node* linklist;
typedef struct node Linklist;
typedef int ElemType;
struct node{
	ElemType data[4];
	linklist link;
};
typedef struct a{
	int x1;
	int y1;
	int x2;
	int y2;
};
linklist creatlist(struct a point[] ,struct a point1,int k)
{
	linklist p,q,list;
	list=(linklist)malloc(sizeof(Linklist));
	list->data[0]=point1.x1,list->data[1]=point1.y1,list->data[2]=point1.x2,list->data[3]=point1.y2;
	list->link=NULL;
	q=list;
	int cnt,cnt1;
	for(cnt1=1;cnt1<=k;cnt1++){
		for(cnt=1;cnt<=k;cnt++){
			p=(linklist)malloc(sizeof(Linklist));
			p->data[0]=point[cnt].x1,p->data[1]=point[cnt].y1,p->data[2]=point[cnt].x2,p->data[3]=point[cnt].y2;
			p->link=NULL;
			if(q->data[2]==p->data[0]&&q->data[3]==p->data[1]){
				q->link=p;
				q=p;
			}
		}
	}
	return (list);
	
}
int getlength(linklist list)
{
	linklist p=list;
	int n=0;
	while(p!=NULL) {
		n++;
		p=p->link;
	}
	return n;
}
int main()
{
	int k;
	struct a point[105];
	scanf("%d",&k);
	int cnt;
	for ( cnt = 1; cnt<=k; cnt++)
		scanf("%d%d%d%d",&point[cnt].x1,&point[cnt].y1,&point[cnt].x2,&point[cnt].y2);
	int max=0;
	linklist finallist;
	for(cnt=1;cnt<=k;cnt++){
		linklist list=creatlist(point ,point[cnt],k);
		int k1=getlength(list);
		if(k1>max) {
			max=k1;
			finallist=list;
		}
	}
	printf("%d %d %d",max,finallist->data[0],finallist->data[1]);
	return 0;
}

