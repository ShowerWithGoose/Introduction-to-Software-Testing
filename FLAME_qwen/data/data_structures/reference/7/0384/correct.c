#include <stdio.h>
#include <string.h>
 struct node{
	int number;
	int h;
	struct node *lmonkey,*rmonkey;
};
void print(struct node *p){
	if(p!=NULL)
	{
		if((p->lmonkey)==NULL&&(p->rmonkey)==NULL)
		{
			printf("%d %d\n",p->number,p->h);
		}
		print(p->lmonkey);
		print(p->rmonkey);
	}
}
struct node *first;
struct node *Tree(struct node *o,int temp, int len)
{
	len++;
	if(o==NULL)
	{
		o=(struct node *)malloc(sizeof(struct node));
		o->number=temp;
		o->lmonkey=NULL;
		o->rmonkey=NULL;
		first=o;
		o->h=len; 
	}
	else if(temp>=o->number)
		o->rmonkey=Tree(o->rmonkey,temp,len);
	else if(temp<o->number)
		o->lmonkey=Tree(o->lmonkey,temp,len);
	return o;		
}

int main()
{
	struct node *root=NULL;
	int sum,temp,i=1;
	scanf("%d",&sum);
	while(i<=sum){
		scanf("%d",&temp);
		int len=0;
		root=Tree(root,temp,len);
		i++;
	}
	print(root);
	return 0;
}


