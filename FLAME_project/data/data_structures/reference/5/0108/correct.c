#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct in{
	int coe;
	int degree;
};
struct out{
	int coe;
	int degree;
	struct out*next;
};
/*char getin(struct in a)
{
	char ch;
	scanf("%d%d",&a.coe,&a.degree);
	ch=getchar();
	return ch;
}*/
int main()
{
	struct in fir[99],sec[99];
	char ch=' ';
	int i=0,j,length1,length2;
	while(ch!='\n')
	{
		scanf("%d%d",&fir[i].coe,&fir[i].degree);
		ch=getchar();
		i++;
	}
	length1=i;
	i=0;
	ch=' ';
	while(ch!='\n')
	{
		scanf("%d%d",&sec[i].coe,&sec[i].degree);
		ch=getchar();
		i++;
	}
	length2=i;
	struct out *current,*prev;
	struct out *head=NULL;
	for(i=0;i<length1;i++)
	{
		for(j=0;j<length2;j++)
		{
			current=(struct out*)malloc(sizeof(struct out));
			current->coe=fir[i].coe*sec[j].coe;
			current->degree=fir[i].degree+sec[j].degree;
			current->next=NULL;
			if(head==NULL)
			{
				head=current;
				continue;
			}
			struct out *tool;
			tool=head;
			while(1)
			{
				if(tool->degree<current->degree)
				{
					prev=head;
					head=current;
					current->next=prev;
					break;
				}
				else if(tool->degree>current->degree&&tool->next==NULL)
				{
					tool->next=current;
					break;
				}
				else if(tool->degree>current->degree&&(tool->next)->degree<current->degree)
				{
					prev=tool->next;
					tool->next=current;
					current->next=prev;
					break;	
				}
				else if(tool->degree==current->degree)
				{
					tool->coe+=current->coe;
					break;
				}
				tool=tool->next;
			}
		}
	}
	while(head!=NULL)
	{
		printf("%d %d ",head->coe,head->degree);
		head=head->next;
	}
}

