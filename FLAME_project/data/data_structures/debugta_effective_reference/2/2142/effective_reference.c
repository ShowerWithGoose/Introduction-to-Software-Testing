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
	int result;
	char s,clean;
	linklist rear,tmp;
	rear=head;
	while(1)
	{
		scanf(" ");
		scanf("%d",&result);
		scanf(" ");
		scanf("%c",&s);
		if(rear->sign=='+'||rear->sign=='-'||rear==head)
		{
			tmp=(linklist)malloc(sizeof(linknode));
			tmp->num=result;
			tmp->sign=s;
			rear->next=tmp;
			tmp->prior=rear;
			rear=tmp;
			//printf("%d ",n);
		}
		else
		{
			if(rear->sign=='*')
				rear->num*=result;
			else
				rear->num/=result;
			rear->sign=s;
		}
		
		if(s=='=')
			break;
	}
	rear->next=NULL;
}
int func(linklist head)
{
	int result=head->next->num;
	linklist tmp=head->next;
	
	while(tmp!=NULL)
	{
		//printf("%d ",tmp->num);
		if(tmp->sign=='+')
			result+=tmp->next->num;
		else if(tmp->sign=='-')
			result-=tmp->next->num; 
		else if(tmp->sign=='=')
			break;
		tmp=tmp->next;
	}
	return result;
}
int main()
{
	linklist head;
	int result;
	head=(linklist)malloc(sizeof(linknode));
	
	input(head);
	//printf("test");
	result=func(head);
	printf("%d",result);
	return 0;
}



