#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	struct node{
		int x1;
		int y1;
		int x2;
		int y2;
		int num;
		struct node*link;
	};
	typedef struct node Node;
	typedef struct node* Nodeptr;
	Nodeptr list,p,end;
	list=p=end=NULL;
	
	int n;
	scanf("%d",&n);
//	printf("%d",n);
	for(int i=0;i<n;i++)
	{
		p=(Nodeptr)malloc(sizeof(Node));
		scanf("%d %d %d %d",&p->x1,&p->y1,&p->x2,&p->y2);
		p->link=NULL;
		p->num=0;
		if(list==NULL)
			list=end=p;
		else
			end->link=p;
		end=p;
	}
	p=list;
	while(p!=NULL)
	{
		Nodeptr temp=p->link;
		Nodeptr atemp=p;
		while(temp!=NULL)
		{
			if(p->x1==temp->x1 && p->y1==temp->y1){
				p->x1=temp->x2;
				p->y1=temp->y2;
				atemp->link=temp->link;	
				temp=temp->link;
				temp=p->link;
				atemp=p;
				p->num++;
				continue;
			}else if(p->x1==temp->x2 && p->y1==temp->y2){
				p->x1=temp->x1;
				p->y1=temp->y1;
				atemp->link=temp->link;
				temp=temp->link;
				temp=p->link;
				atemp=p;
				p->num++;
				continue;
			}else if(p->x2==temp->x1 && p->y2==temp->y1){
				p->x2=temp->x2;
				p->y2=temp->y2;
				atemp->link=temp->link;
				temp=temp->link;
				temp=p->link;
				atemp=p;
				p->num++;
				continue;
			}else if(p->x2==temp->x2 && p->y2==temp->y2){
				p->x2=temp->x1;
				p->y2=temp->y1;
				atemp->link=temp->link;
				temp=temp->link;
				temp=p->link;
				atemp=p;
				p->num++;
				continue;
			}
			temp=temp->link;
			atemp=atemp->link;
		}
		p=p->link;
	}
	p=list;
	int max=list->num;
	while(p!=NULL)
	{
		if(max < p->num)
			max=p->num;
		p=p->link;
	}
//	p=list;
//	printf("max=%d\n ",max);
//	do{
//		printf("%d ",p->num);
//		p=p->link;
//	}while(p!=NULL);
	p=list;
	while(1)
	{
		if(max==p->num)
		{
			if(p->x1<p->x2)
				printf("%d %d %d",max+1,p->x1,p->y1);
			else
				printf("%d %d %d",max+1,p->x2,p->y2);
			break;
		}
		p=p->link;
	}
	return 0;
}



