#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
typedef struct node
{
	int num;
	int index;
	struct node *next;
} *Nodeptr, Node;
char c;
int a,n,a2,n2;
int main(){
Nodeptr q1,head1=NULL,p1=NULL,q2,head2=NULL,p2,p0=NULL;
do{
scanf("%d%d%c",&a,&n,&c);
q1=(Nodeptr)malloc(sizeof(Node));
q1->num=a;q1->index=n;q1->next=NULL;
if(head1==NULL){
	head1=p1=q1;//为了存头指针，后面要用 
}
else{p1->next=q1;
p1=p1->next;}	
}while(c!='\n');
do{
scanf("%d%d%c",&a,&n,&c);
for(p1=head1;p1!=NULL;p1=p1->next)
{
	a2=a*p1->num;
	n2=n+p1->index;
		
q2=(Nodeptr)malloc(sizeof(Node));
q2->num=a2;q2->index=n2;q2->next=NULL;
if(head2==NULL)
{
	head2=p2=q2;//存首节点
}
else{
for(p2=head2;p2!=NULL;p0=p2,p2=p2->next)
{
	if(q2->index>p2->index)
	{
		if(p2==head2){q2->next=head2;head2=q2;break;}//插入头结点前
		else {q2->next=p2;p0->next=q2;break;} 
	}
	else if(q2->index==p2->index){p2->num+=q2->num;break;}
	
}
if(p2==NULL)p0->next=q2;
}
}
}while(c!='\n');
for(p2=head2;p2!=NULL;p2=p2->next)
{
	printf("%d %d ",p2->num,p2->index);
}
return 0;
}

