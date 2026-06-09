#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
typedef struct{
	int x;
	int y;
} point;
typedef struct{
	point p1;
	point p2;
} line;
struct a{
	line l;
	struct a* link;
};
typedef struct a* noteptr;
typedef struct a note;
typedef struct{
	noteptr start;
	noteptr end;
	int num;
}longline;
longline lists[101];
line getline()
{
	line l1;
	scanf("%d%d%d%d",&l1.p1.x,&l1.p1.y,&l1.p2.x,&l1.p2.y);
	return l1;
}
int main()
{
	int linenum,i,j,listnum=1,flag;
	noteptr list=NULL,m;
	scanf("%d",&linenum);
	for(i=0;i<linenum;i++){
		noteptr p,q=NULL,r=list;
		p=(noteptr)malloc(sizeof(note));
		p->l=getline();
		while(r!=NULL&&r->l.p1.x<p->l.p1.x){
			q=r;
			r=r->link;
		}
		if(q==NULL){
			p->link=list;
			list=p;
		}
		else{
			p->link=q->link;
			q->link=p;
		}			
	}
	lists[0].start=list;
	lists[0].end=list;
	lists[0].num=1;
	for(m=lists[listnum-1].end;m!=NULL;m=m->link){
		flag=1;
		for(i=0;i<listnum;i++){
			if(lists[i].end->l.p2.x==m->l.p1.x&&lists[i].end->l.p2.y==m->l.p1.y){
				lists[i].end=m;
				lists[i].num++;
				flag=0;
			}
		}
		if(flag){
			lists[listnum].start=m;
			lists[listnum].end=m;
			lists[listnum].num=1;
			listnum++;
		}
	}
	j=0;
	for(i=1;i<listnum;i++){
		if(lists[i].num>lists[j].num) j=i;
	}
	printf("%d %d %d",lists[j].num,lists[j].start->l.p1.x,lists[j].start->l.p1.y);
	return 0;
}

