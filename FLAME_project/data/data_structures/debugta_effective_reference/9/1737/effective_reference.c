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
longline list[101];
line getline()
{
	line l1;
	scanf("%d%d%d%d",&l1.p1.x,&l1.p1.y,&l1.p2.x,&l1.p2.y);
	return l1;
}
int main()
{
	int n,i,j,listnum=1,flag;
	noteptr a=NULL,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		noteptr p,j=NULL,i=a;
		p=(noteptr)malloc(sizeof(note));
		p->l=getline();
		while(i!=NULL&&i->l.p1.x<p->l.p1.x){
			j=i;
			i=i->link;
		}
		if(j==NULL){
			p->link=a;
			a=p;
		}
		else{
			p->link=j->link;
			j->link=p;
		}			
	}
	list[0].start=a;
	list[0].end=a;
	list[0].num=1;
	for(m=list[listnum-1].end;m!=NULL;m=m->link){
		flag=1;
		for(i=0;i<listnum;i++){
			if(list[i].end->l.p2.x==m->l.p1.x&&list[i].end->l.p2.y==m->l.p1.y){
				list[i].end=m;
				list[i].num++;
				flag=0;
			}
		}
		if(flag){
			list[listnum].start=m;
			list[listnum].end=m;
			list[listnum].num=1;
			listnum++;
		}
	}
	j=0;
	for(i=1;i<listnum;i++){
		if(list[i].num>list[j].num) j=i;
	}
	printf("%d %d %d",list[j].num,list[j].start->l.p1.x,list[j].start->l.p1.y);
	return 0;
}

