#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int coefficient;int time;
	struct node* link;
}Node,*Nodeptr;

Nodeptr create()
{
	Nodeptr list=0,r,p;
	list=(Nodeptr)malloc(sizeof(Node));
	scanf("%d%d",&list->coefficient,&list->time);
	list->link=0;
	r=list;
	char ch;
	while((ch=getchar())!='\n')
	{
		p=(Nodeptr)malloc(sizeof(Node));
		scanf("%d%d",&p->coefficient,&p->time);
		p->link=0;
		r->link=p;
		r=p;
	}
	return list;
}

Nodeptr List=0;
void insert(Node point)
{
	Nodeptr r=List;
	if(List==0)
	{
		List=(Nodeptr)malloc(sizeof(Node));
		List->coefficient=point.coefficient;
		List->time=point.time;
		List->link=0;
		return;
	}
	if(point.coefficient==0)return ;
	Nodeptr pos=r;
	while(r!=0&&r->time>point.time)
	{
		pos=r;
		r=r->link;
	}
	if(r==List)
	{
		if(r->time==point.time)
		{
			r->coefficient=r->coefficient+point.coefficient;
		}else{
			Nodeptr ptr=(Nodeptr)malloc(sizeof(Node));
			ptr->link=r->link;
			ptr->coefficient=r->coefficient;
			ptr->time=r->time;
			List->link=ptr;
			List->coefficient=point.coefficient;
			List->time=point.time;
		}
		return;
	}
	if(r==0)
	{
		Nodeptr ptr=(Nodeptr)malloc(sizeof(Node));
		ptr->link=0;
		ptr->coefficient=point.coefficient;
		ptr->time=point.time;
		pos->link=ptr;
		return 0;
	}
	if(r->time==point.time)
	{
		r->coefficient=r->coefficient+point.coefficient;
	}else{
			Nodeptr ptr=(Nodeptr)malloc(sizeof(Node));
			ptr->link=r;
			ptr->coefficient=point.coefficient;
			ptr->time=point.time;
			pos->link=ptr;
	}
}

int main()
{
	Nodeptr Lista=0,Listb=0;
	List=0;
	Lista=create();
	Listb=create();
	Nodeptr ra=Lista,rb=Listb;
	for(;ra!=0;ra=ra->link)
	{
		for(rb=Listb;rb!=0;rb=rb->link){
			Node temp;
			temp.coefficient=ra->coefficient*rb->coefficient;
			temp.time=ra->time+rb->time;
			insert(temp);
		}
	}
	int kase=0;
	if(List->link==0&&List->coefficient==0)
	{
		printf("0 0\n");
		return 0;
	}
	for(Nodeptr it=List;it!=0;it=it->link)
	{
		if(kase)printf(" ");kase++;
		printf("%d %d",it->coefficient,it->time);
	}
	printf("\n");
	return 0;
}



