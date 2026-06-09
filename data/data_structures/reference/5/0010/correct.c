#include<stdio.h>
struct node{
	int xi;
	int zhi;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node; 

int main(){
	int a,b;
	char c;
	Nodeptr head1,head2,p,q,r,s;
	head1=p=NULL;//head1和p都指向第一个链表的头 
	head2=NULL;
	do{
		scanf("%d%d%c",&a,&b,&c);
		if(head1==NULL){
			head1=p=(Nodeptr)malloc(sizeof(Node));
		}else{
			p->link=(Nodeptr)malloc(sizeof(Node));
			p=p->link;
		}
		p->xi=a;
		p->zhi=b;
		p->link=NULL;
	}while(c!='\n');
	do{//读第二个多项式 
		scanf("%d%d%c",&a,&b,&c);
		for(p=head1;p!=NULL;p=p->link){//遍历第一个链表（多项式 
			q=(Nodeptr)malloc(sizeof(Node));
			q->xi=a*p->xi;;
			q->zhi=b+p->zhi;
			q->link=NULL;
			if(head2==NULL){
				head2=q;//head指向结果第一项 
			}else{
				for(s=head2;s!=NULL;r=s,s=s->link){//遍历结果链表，找到插入位置 
					if(q->zhi>s->zhi){
						if(s==head2){
						q->link=head2;
						head2=q;
						break;
						}else{
						q->link=s;
						r->link=q;
						break;
						}
					}else if(q->zhi==s->zhi){
						s->xi+=q->xi;
						break;
					}
				}
				if(s==NULL)
					r->link=q;//r不能改成s，r在s后面 
			}
		}
	}while(c!='\n');
	for(p=head2;p!=NULL;p=p->link)
		printf("%d %d ",p->xi,p->zhi);
		
	return 0;
}
 

