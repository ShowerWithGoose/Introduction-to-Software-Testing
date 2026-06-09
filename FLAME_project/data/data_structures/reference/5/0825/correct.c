#include<stdio.h>
#include<stdlib.h>
struct shi{
	int num;
	int pow;
	struct shi *next;
};
struct shi *first1,*first2,*p,*q,*end,*rp,*rq,*rp0,*p0;
int main()
{
	int a,n;
	char c;
	do {//创建一个链表存放第一个多项式 
		scanf("%d%d%c",&a,&n,&c);
		q=(struct shi *)malloc(sizeof(struct shi));
		q->num=a;
		q->pow=n;
		q->next=NULL;
		if(first1==NULL)
			first1=p=q;
		else {
			p->next=q;
			p=p->next;
		}
	} while(c!='\n');
	do {//创建一个链表存放第一个多项式 
		scanf("%d%d%c",&a,&n,&c);
		q=(struct shi *)malloc(sizeof(struct shi));
		q->num=a;
		q->pow=n;
		q->next=NULL;
		if(first2==NULL)
			first2=p=q;
		else {
			p->next=q;
			p=p->next;
		}
	} while(c!='\n');
	/*for(p=first1;p!=NULL;p=p->next)
	printf("%d %d ",p->num,p->pow);
	printf("\n");
	for(p=first2;p!=NULL;p=p->next)
	printf("%d %d ",p->num,p->pow);
	printf("\n");*/
	end=NULL;
	for(p=first1,q=first2;q!=NULL;q=q->next){
		rq=(struct shi *)malloc(sizeof(struct shi));
		rq->num=p->num*q->num;
		rq->pow=p->pow+q->pow;
		rq->next=NULL;
		if(end==NULL)end=rp=rq;
		else{
			rp->next=rq;
			rp=rp->next;
		}
	}
	/*for(p=end;p!=NULL;p=p->next)
	printf(" %d %d ",p->num,p->pow);
	printf("\n");*/
	for(p=first1->next;p!=NULL;p=p->next){
		for(q=first2;q!=NULL;q=q->next){
			rq=(struct shi *)malloc(sizeof(struct shi));
			rq->num=p->num*q->num;
			rq->pow=p->pow+q->pow;
			rq->next=NULL;
			for(rp=end;rp!=NULL;rp0=rp,rp=rp->next){
				if(rq->pow>rp->pow){
					if(rp==end){rq->next=end;end=rq;break;}
					else{rq->next=rp;rp0->next=rq;break;}
				}else if(rq->pow==rp->pow){rp->num+=rq->num;break;}
				
			}
			if(rp==NULL)rp0->next=rq;
		}
	}
	for(p=end;p!=NULL;p=p->next){
		printf("%d %d ",p->num,p->pow);
	}
	
/*		do{//将第二个多项式的每个项插入到第一个多项式链表中 
		scanf("%d%d%c",&a,&n,&c);//生成第二个多项式的一个节点 
		q=(struct shi *)malloc(sizeof(struct shi));
		q->num=a;q->pow=n;q->next=NULL;
		for(p=first1;p!=NULL;p0=p,p=p->next){
			if(q->pow>p->pow){
				if(p==first1){q->next=first1;first1=q;break;}//插入到头节点前 
				else{q->next=p;p0->next=q;break;}//将q插入到p前 
			}
			else if(q->pow==p->pow){p->num+=q->num;break;}//指数相等，系数相加 
		}
		if(p==NULL)p0->next=q;//将q插入到尾节点后 
	}while(c!='\n');
	for(p=first1;p!=NULL;p=p->next)
	printf("%d %d ",p->num,p->pow);*/
	return 0;
}

