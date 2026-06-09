#include<stdio.h>
#include<stdlib.h>
typedef struct node* linklist;
typedef struct node Linklist;
typedef int ElemType;
struct node{
	ElemType coe;
	ElemType exp;
	linklist link;
};
void listsort(linklist list)
{
	linklist r1,r2;
	r1=list;
	while(r1->link){
		r2=list;
		while(r2->link){
			if(r2->link->exp>r2->exp){
				int temp1,temp2;
				temp1=r2->link->coe;
				temp2=r2->link->exp;
				r2->link->coe=r2->coe;
				r2->link->exp=r2->exp;
				r2->coe=temp1;
				r2->exp=temp2;
			}
			r2=r2->link;
		}
		r1=r1->link;
	}
}
linklist find(linklist list,ElemType item){
	linklist p=list;
	while(p!=NULL&&p->exp!=item) p=p->link;
	return p;
}
void linkdelete(linklist list,linklist q)
{
	linklist target;
	for(target=list;target->link!=q;target=target->link);
	target->link=q->link;
	free(q);
}
linklist creatlist()
{
	linklist p,q,list=NULL;
	int coe,exp;
	char c1;
	do{
		scanf("%d%d%c",&coe,&exp,&c1);
		p=(linklist)malloc(sizeof(Linklist));
		p->coe=coe;
		p->exp=exp;
		p->link=NULL;
		if(list==NULL) list=p;
		else q->link=p;
		q=p;
	}while(c1!='\n');
	return (list);
}
int main()
{
	linklist a,b,p1,list=NULL;
	a=creatlist();
	b=creatlist();
	p1=a;
	while(p1!=NULL){
		linklist p2=b,p,q;
		while(p2){
			p=(linklist)malloc(sizeof(Linklist));
			p->coe=p1->coe*p2->coe;
			p->exp=p1->exp+p2->exp;
			p->link=NULL;
			if(find(list,p->exp)){
					linklist r=find(list,p->exp);
					r->coe+=p->coe;
				
					p2=p2->link;
			}
			else {
				if(list==NULL) list =p;
				else  q->link=p;
				q=p;
				p2=p2->link;
			}
		}
		p1=p1->link;
	}
	listsort(list);
	while(list) 
	{
		if(list->coe!=0)
		printf("%d %d ",list->coe,list->exp);
		list=list->link;
	}
	return 0;
}

