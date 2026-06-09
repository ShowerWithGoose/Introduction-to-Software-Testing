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
	int a;
	int b;
	int x2;
	int y2;
};
linklist creatlist(struct a list[] ,struct a point1,int n)
{
	linklist p,q,r;
	r=(linklist)malloc(sizeof(Linklist));
	r->data[0]=point1.a,r->data[1]=point1.b,r->data[2]=point1.x2,r->data[3]=point1.y2;
	r->link=NULL;
	q=r;
	int j,cnt1;
	for(cnt1=1;cnt1<=n;cnt1++){
		for(j=1;j<=n;j++){
			p=(linklist)malloc(sizeof(Linklist));
			p->data[0]=list[j].a,p->data[1]=list[j].b,p->data[2]=list[j].x2,p->data[3]=list[j].y2;
			p->link=NULL;
			if(q->data[2]==p->data[0]&&q->data[3]==p->data[1]){
				q->link=p;
				q=p;
			}
		}
	}
	return (r);
	
}
int getlength(linklist r)
{
	linklist p=r;
	int n=0;
	while(p!=NULL) {
		n++;
		p=p->link;
	}
	return n;
}
int main()
{
	int n;
	struct a list[105];
	scanf("%d",&n);
	int j;
	for ( j = 1; j<=n; j++)
		scanf("%d%d%d%d",&list[j].a,&list[j].b,&list[j].x2,&list[j].y2);
	int max=0;
	linklist ans;
	for(j=1;j<=n;j++){
		linklist r=creatlist(list ,list[j],n);
		int k1=getlength(r);
		if(k1>max) {
			max=k1;
			ans=r;
		}
	}
	printf("%d %d %d",max,ans->data[0],ans->data[1]);
	return 0;
}

