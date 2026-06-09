#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long LL;
struct node
{
	LL num;
	LL index;
	struct node *nxt;
};
typedef struct node node;
typedef node *nptr;
nptr getNode(LL num,LL index)
{
	nptr tmp=(nptr)malloc(sizeof(node));
	tmp->num=num;
	tmp->index=index;
	tmp->nxt=NULL;
	return tmp;
}
typedef struct list{
	nptr head;
	int size;
}list;
list a,b;
void insert(list *s,LL num,LL index)
{
	s->size++;
	nptr tmp=getNode(num,index);
	tmp->nxt=s->head;
	s->head=tmp;
	return;
}
void input(list *s)
{
	char shuo;
	int homo=1;
	int number1=0,number2=0;
	while(scanf("%c",&shuo))
	{	
		if(shuo=='\n')
		{
			insert(s,number1,number2);
			number1=0,number2=0;
			break;
		}
		if(shuo!=' ')
		{
			if(homo==1)
			{
				number1=number1*10+shuo-'0';
			}
			else if(homo==2)
			{
				number2=number2*10+shuo-'0';
			}
		}
		else
		{
			if(homo==1) homo=2;
			else  if(homo==2)
			{
				homo=1;
				insert(s,number1,number2);
				number1=0,number2=0;
			}
		}
	}
	return;
}
void getnumber()
{
	input(&a);
	input(&b);
	return;
}
list ab;
void insert_sort(list *s,LL num,LL index)
{
	nptr tmp=getNode(num,index);
	if(s->size==0){
		s->size=1;
		s->head=tmp;
		return;
	}
	nptr i=s->head,lst=NULL;
	while(i!=NULL && i->index<index)lst=i,i=i->nxt;
	if(i!=NULL && i->index==index)i->num+=num;
	else tmp->nxt=i,lst->nxt=tmp,s->size++;
	return;
}
void multipulCreate()
{
	for(nptr i=a.head;i!=NULL;i=i->nxt)
	for(nptr j=b.head;j!=NULL;j=j->nxt)
	{
		insert_sort(&ab, i->num*j->num, i->index+j->index);
	}
	return;
}
void out(nptr s)
{
	while(s==NULL) return;out(s->nxt);
	printf("%lld %lld ",s->num,s->index);
	return;
}
int main()
{
	getnumber();
	multipulCreate();
	out(ab.head);
	return 0;
}



