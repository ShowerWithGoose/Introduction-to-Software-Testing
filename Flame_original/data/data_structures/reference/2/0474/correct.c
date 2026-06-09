#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct linknode
{
	int num;
	char sign;
	struct linknode *next;
	struct linknode *prior;
}linknode,*linklist;
void input(linklist head)
{
	int n;
	char s,clean;
	linklist rear,tmp;
	rear=head;
	while(1)
	{
		scanf(" ");
		scanf("%d",&n);
		scanf(" ");
		scanf("%c",&s);
		if(rear->sign=='+'||rear->sign=='-'||rear==head)
		{
			tmp=(linklist)malloc(sizeof(linknode));
			tmp->num=n;
			tmp->sign=s;
			rear->next=tmp;
			tmp->prior=rear;
			rear=tmp;
			//printf("%d ",n);
		}
		else
		{
			if(rear->sign=='*')
				rear->num*=n;
			else
				rear->num/=n;
			rear->sign=s;
		}
		
		if(s=='=')
			break;
	}
	rear->next=NULL;
}
int func(linklist head)
{
	int n=head->next->num;
	linklist tmp=head->next;
	
	while(tmp!=NULL)
	{
		//printf("%d ",tmp->num);
		if(tmp->sign=='+')
			n+=tmp->next->num;
		else if(tmp->sign=='-')
			n-=tmp->next->num; 
		else if(tmp->sign=='=')
			break;
		tmp=tmp->next;
	}
	return n;
}
int main()
{
	linklist head;
	int n;
	head=(linklist)malloc(sizeof(linknode));
	
	input(head);
	//printf("test");
	n=func(head);
	printf("%d",n);
	return 0;
}



