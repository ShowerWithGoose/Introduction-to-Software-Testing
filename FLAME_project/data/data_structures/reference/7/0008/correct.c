#include<stdio.h>
#include<string.h>
void insert(int num);
void cmp(int num);
int flag=0;
int n;
int cnt=1;
struct node{
	int data;
	int mark;
	struct node *ri,*le;
};
struct node *p,*q,*list,max;
void postorder(struct node *t);
int main()
{

	int exnum;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&exnum); 
		insert(exnum);
		p=list;
	}

	postorder(list);
	
}
void insert(int num)
{

	q=(struct node*)malloc(sizeof(struct node));
	q->le=NULL;
	q->ri=NULL; 
	if(flag==0)
	{
		q->data=num;
		q->mark=1;
		p=list=q;
		flag=1;
		return;
	}

	else
	{
	/*	printf("num>%d\n",num);
		printf("p>%d\n",p->data);
		printf("list>%d\n",list->data);
	*/
		cmp(num);
		
		
	}
}
void cmp(int num){
	cnt++;
	if(num>=p->data)
	{	
		if(p->ri!=NULL) 
		{
			p=p->ri;
			insert(num);
		}
		else 
		{
			q=(struct node*)malloc(sizeof(struct node));
			q->le=NULL;
			q->ri=NULL; 
			p->ri=q;
			p->ri->data=num;
		//	printf("%d",cnt);
			p->ri->mark=cnt;
			cnt=1;
		}
	}
	else if(num<p->data)
	{
		if(p->le!=NULL )
		{
			p=p->le;
			insert(num);
		}
		else
		{
			q=(struct node*)malloc(sizeof(struct node));
			q->le=NULL;
			q->ri=NULL; 
			p->le=q;
			p->le->data=num;
			p->le->mark=cnt;
			cnt=1;
		 } 
	}
}
void postorder(struct node *t)
{
	if(t!=NULL)
	{
		postorder(t->le);
		if(t->le==NULL&&t->ri==NULL){
			printf("%d %d\n",t->data,t->mark);
		}
		postorder(t->ri);
		
	}
}


