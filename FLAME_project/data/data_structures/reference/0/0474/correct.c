#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct linknode
{
	char data;
	struct linknode *next;
	struct linknode *prior;
}linknode,*linklist;
void input(linklist head)
{
	char m;
	linklist rear,tmp;
	rear=head;
	while((m=getchar())!=EOF)
	{
		tmp=(linklist)malloc(sizeof(linknode));
		tmp->data=m;
		rear->next=tmp;
		tmp->prior=rear;
		rear=tmp;
	}
	rear->next=NULL;
}
void output(linklist head)
{
	linklist tmp=head->next;
	int delta=0,i;
	while(tmp!=NULL)
	{
		delta=0;
		if(tmp->data!='-')
			printf("%c",tmp->data);
		else
		{
			if(tmp->next->data>tmp->prior->data)
			{
				if(tmp->prior->data>='0'&&tmp->prior->data<='9'&&tmp->next->data>='0'&&tmp->next->data<='9')
					delta=1;
				else if(tmp->prior->data>='a'&&tmp->prior->data<='z'&&tmp->next->data>='a'&&tmp->next->data<='z')
					delta=1;
				else if(tmp->prior->data>='A'&&tmp->prior->data<='Z'&&tmp->next->data>='A'&&tmp->next->data<='Z')
					delta=1;
				if(delta==1)
				{
					for(i=1;i<=tmp->next->data-tmp->prior->data-1;i++)
						printf("%c",tmp->prior->data+i);
				}
				else
					printf("%c",tmp->data);
			}
			else
				printf("%c",tmp->data);
		}
		tmp=tmp->next;
	}
}
int main()
{
	linklist head;
	head=(linklist)malloc(sizeof(linknode));
	input(head);
	output(head);
	return 0;
}



