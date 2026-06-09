#include <stdio.h>
#include <stdlib.h>
struct  node { 
        int num;
        struct  node  *link;
};
struct node* top=NULL,* p;
int main()
{	int m,n;
	while(1)
	{	
		scanf("%d",&m);
		if(m==1)
		{	
			scanf("%d",&n);
			p=(struct node* )malloc(sizeof(struct node));
			p->num=n;
			p->link=NULL;
			if(top==NULL)
			top=p;
			else
			{	
				p->link=top;
				top=p;
			}
		}
		if(m==0)
		{	if(top==NULL)
			{	printf("error ");
				continue;
			}
			else
			{	n=top->num;
				p=top;
				top=top->link;
				free(p);
				printf("%d ",n);
			}
		}
		if(m==-1)
		return 0;
	}
}

