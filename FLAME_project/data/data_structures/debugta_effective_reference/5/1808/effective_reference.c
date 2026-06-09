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
	Nodeptr first_1,first_3,p1,q,r,s;
	first_1=p1=NULL;//head1和p都指向第一个链表的头 
	first_3=NULL;
	do{
		scanf("%d%d%c",&a,&b,&c);
		if(first_1==NULL){
			first_1=p1=(Nodeptr)malloc(sizeof(Node));
		}else{
			p1->link=(Nodeptr)malloc(sizeof(Node));
			p1=p1->link;
		}
		p1->xi=a;
		p1->zhi=b;
		p1->link=NULL;
	}while(c!='\n');
	do{//读第二个多项式 
		scanf("%d%d%c",&a,&b,&c);
		for(p1=first_1;p1!=NULL;p1=p1->link){//遍历第一个链表（多项式 
			q=(Nodeptr)malloc(sizeof(Node));
			q->xi=a*p1->xi;;
			q->zhi=b+p1->zhi;
			q->link=NULL;
			if(first_3==NULL){
				first_3=q;//head指向结果第一项 
			}else{
				for(s=first_3;s!=NULL;r=s,s=s->link){//遍历结果链表，找到插入位置 
					if(q->zhi>s->zhi){
						if(s==first_3){
						q->link=first_3;
						first_3=q;
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
	for(p1=first_3;p1!=NULL;p1=p1->link)
		printf("%d %d ",p1->xi,p1->zhi);
		
	return 0;
}
 

