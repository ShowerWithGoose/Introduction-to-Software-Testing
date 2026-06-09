#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int i,j,len,cnt1,cnt2,flag;
char test[100000],t;
struct node{
	int xi;
	int zhi;
	struct node *next;   
} ;

typedef struct node node;

int main()
{
	node *p1,*p2,*p3,*p4,*p5,*p6,*a,*b,*c;
	p1=p2=malloc(sizeof(node));
	a=p1;
	scanf("%d %d%c",&p1->xi,&p1->zhi,&t);
	while(t!='\n'){
		p1=malloc(sizeof(node));
		scanf("%d %d%c",&p1->xi,&p1->zhi,&t);
		p2->next=p1;
				p2=p1;
		cnt1++;
	}
	t=' ';
	p1=p2=malloc(sizeof(node));
	b=p1;
	scanf("%d %d%c",&p1->xi,&p1->zhi,&t);
	while(t!='\n'){
		p1=malloc(sizeof(node));
		scanf("%d %d%c",&p1->xi,&p1->zhi,&t);
		p2->next=p1;
		p2=p1;
		cnt2++;
	}
	p1=p2=malloc(sizeof(node));
	c=p1;
	p1->xi=0x7fffffff;
	p1->zhi=0x7fffffff;
	p1=malloc(sizeof(node));
	p1->xi=-1;
	p1->zhi=-1;
	p2->next=p1;
	p2=p1;
	p3=a;
	p4=b;
	p6=c;
	for(i=0;i<cnt1+1;i++){
		for(j=1;j<cnt2+2;j++){
			p1=malloc(sizeof(node));
			p1->xi=p3->xi*p4->xi;
			p1->zhi=p3->zhi+p4->zhi;
			for(p5=c->next;p5->zhi!=-1;p5=p5->next){
				if(p1->zhi==p5->zhi){
					p5->xi+=p1->xi;
					flag=1;
					break;
				}
			}
			if(flag==0){
				for(p5=c->next;p5->zhi>p1->zhi;p5=p5->next){
					p6=p6->next;
				}
				p1->next=p6->next;
				p6->next=p1;
			}
			p4=p4->next;
			p6=c;	
			flag=0;
		}
		p4=b;
		
		p3=p3->next;
	}	

	for(p1=c->next;p1->zhi>-1;p1=p1->next)
	printf("%d %d ",p1->xi,p1->zhi);
		
	
return 0;
}


