#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coe;//系数
	int index;//指数
	struct node* link;
}Lnode,*Linklist;
int main(){
	Linklist origin=NULL,newone=NULL;
	Linklist p,q,r,r0;
	int flag=0;
	int coe=0,index=0;
	char ch;
	do{
		scanf("%d%d%c",&coe,&index,&ch);
			p=(Linklist)malloc(sizeof(Lnode));
			p->coe=coe;
			p->index=index;
			p->link=NULL;
			if(origin==NULL)
			 origin=p;
			else
			 r->link=p;
			r=p;
	}while(ch!='\n');//以上为第一个多项式（原表

	do{
		flag++;
		scanf("%d%d%c",&coe,&index,&ch);
		if(flag==1){
			q=origin;
			while(q!=NULL){
				p=(Linklist)malloc(sizeof(Lnode));
				p->coe=coe*(q->coe);
				p->index=index+(q->index);
				p->link=NULL;
				if(newone==NULL)
				 newone=p;
				else
				 r->link=p;
				r=p;
				q=q->link;
		}
		}
		else{
			q=origin;
			while(q!=NULL){
				p=(Linklist)malloc(sizeof(Lnode));
				p->coe=coe*(q->coe);
				p->index=index+(q->index);
				p->link=NULL;//以上为第二个多项式作用于一的第2个小项
				for(r=newone;r!=NULL;r0=r,r=r->link){
					if(p->index>r->index){
						if(r==newone){
							p->link=newone;newone=p;break;//前端插入
						}
						else{
							p->link=r;r0->link=p;break;
						}
					}
					else if(p->index==r->index){
						r->coe+=p->coe;
						break;
					}
				}
				if(r==NULL)
				r0->link=p;
				q=q->link;
		}
	}
	}while(ch!='\n');
//第二个多项式作用生成新表，再是相同于多项式相加

	for(p=newone;p!=NULL;p=p->link)
		printf("%d %d ",p->coe,p->index);
		
	return 0;
	}





