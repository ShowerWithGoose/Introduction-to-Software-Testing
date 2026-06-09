#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int first_not_zero;
int point;
typedef struct linknode
{
	int num;
	struct linknode *next;
}linknode,*linklist;
linklist vip;
void input(linklist head)
{
	int n;
	int i=1;
	char s;
	linklist rear,tmp;
	rear=head;
	while((s=getchar())!=EOF)
	{	
		if(s>='0'&&s<='9')
		{
			n=s-'0';
			tmp=(linklist)malloc(sizeof(linknode));
			tmp->num=n;
			rear->next=tmp;
			if(n!=0&&first_not_zero==0)
			{
				first_not_zero=i;
				vip=tmp;
			}
			rear=tmp;	
		}
		else if(s=='.')
			point=i;
		i++;
	}
	rear->next=NULL;
}
int output(linklist head)
{
	linklist tmp;
	//printf("%d %d\n",point,first_not_zero);
	printf("%d",vip->num);
	tmp=vip->next;
	if(tmp!=NULL)
		printf(".");
	while(tmp!=NULL)
	{
		printf("%d",tmp->num);
		tmp=tmp->next;
	}
	printf("e%d",(point-first_not_zero<0)?(point-first_not_zero):(point-first_not_zero-1));
}
int main()
{
	linklist head;
	int n;
	head=(linklist)malloc(sizeof(linknode));
	input(head);
	//printf("test");
	output(head);
	return 0;
}

