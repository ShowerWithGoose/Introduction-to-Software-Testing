#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
	int x;
	int y;
	struct linknode *next;
}linknode,*linklist; 
linklist *head,*back;
int maxl,maxx,maxy;
void initial(linklist pointer,int x0,int y0)
{
	pointer=(linklist)malloc(sizeof(linknode));
	pointer->x=x0;
	pointer->y=y0;
	pointer->next=NULL;
}
void input(int i)
{
	int x1,y1;
	int x2,y2;
	int r,delta=0,alpha=0;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	
	for(r=1;r<=i-1;r++)
	{
		if(back[r]->x==x1&&back[r]->y==y1)
		{
			head[i]=back[r];
			delta=1;
		}
	}
	for(r=1;r<=i-1;r++)
	{
		if(head[r]->x==x2&&head[r]->y==y2)
		{
			back[i]=head[r];
			alpha=1;
		}
	}
	if(delta==0)
	{
		head[i]=(linklist)malloc(sizeof(linknode));
		head[i]->x=x1;
		head[i]->y=y1;
		//head[i]->next=NULL;
	}
	if(alpha==0)
	{
		back[i]=(linklist)malloc(sizeof(linknode));
		back[i]->x=x2;
		back[i]->y=y2;
		back[i]->next=NULL;
	}
	head[i]->next=back[i];
}
void func(int i)
{
	linklist tmp=head[i];
	int m=0;
	while(1)
	{
		tmp=tmp->next;
		if(tmp==NULL)
			break;
		m++;
	}
	if(m>=maxl)
	{
		maxl=m;
		maxx=head[i]->x;
		maxy=head[i]->y;
	}
	//printf("\n%d\n",m);
}
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	head=(linklist *)calloc(n+1,sizeof(linklist));
	back=(linklist *)calloc(n+1,sizeof(linklist));
	//printf("test");
	for(i=1;i<=n;i++)
		input(i);
	for(i=1;i<=n;i++)
		func(i);
	printf("%d %d %d",maxl,maxx,maxy);
	return 0; 
}

