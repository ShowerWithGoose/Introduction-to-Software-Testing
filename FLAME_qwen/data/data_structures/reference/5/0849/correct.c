#include<stdio.h> 
#include<stdlib.h>
struct Node{
	int coe;///系数
	int pow;// 幂
	struct Node *next; 
};
int main()
{
	int a,n;
	char c;
	struct Node *head,*p,*q,*p0,*p1,*q1,*tmp,*head1;
	head=p=NULL;
	head1=p1=NULL;
	do{//创造一个链表存放第一个多项式 
		scanf("%d%d%c",&a,&n,&c);
		q=(struct Node*)malloc(sizeof(struct Node));
		q1=(struct Node*)malloc(sizeof(struct Node));
		q->coe=a;
		q->pow=n;
		q->next=NULL;
		q1->coe=a;
		q1->pow=n;
		q1->next=NULL;
		if(head==NULL){
			head=p=q;
			head1=p1=q1;
		}
		else{
			p->next=q;
			p=p->next;
			p1->next=q1;
			p1=p1->next;
		}
	}while(c!='\n');//一个head，一个head1备份，作为第一组
	scanf("%d%d%c",&a,&n,&c);
	for(p=head;p!=NULL;p=p->next){
		p->coe*=a;
		p->pow+=n;
	}////head成为第一个子多项式输出的结果 
	if(c=='\n'){
		for(p=head;p!=NULL;p=p->next)
		printf("%d %d ",p->coe,p->pow);
		return 0;
	}//多项式二只有一个元素的情况 
	
	 
	
	
	do{//将第二个多项式每个项插入第一个多项式的链表中
		scanf("%d%d%c",&a,&n,&c);//生成第二个多项式的一个节点
	for(q1=head1;q1!=NULL;q1=q1->next){
		q=(struct Node*)malloc(sizeof(struct Node));
		q->coe=a*q1->coe;
		q->pow=n+q1->pow;
		q->next=NULL;		
		for(p=head;p!=NULL;p0=p,p=p->next){
		if(q->pow>p->pow){
			if(p==head){
				q->next=head;
				head=q;
				break;
			}
			else {
				q->next=p;
				p0->next=q;
				break;
			}
		}
		else if(q->pow==p->pow){
			p->coe+=q->coe;
//			free(q);
			break;
		}
	  }
	  if(p==NULL) p0->next=q;
		}
	}while(c!='\n');
	for(p=head;p!=NULL;p=p->next)
	printf("%d %d ",p->coe,p->pow);
	return 0;

	
	
	
	
	
	
	
	
	
	
	
	
}


