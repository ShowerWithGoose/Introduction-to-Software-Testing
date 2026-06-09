#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *llink;
	struct node *rlink;
};

int main()
{
	int i, cont = 0;
	struct node *p = NULL;
	while(1)
	{
		scanf("%d", &i);
		if(i == -1)
		{
			break;
		}
		else if(i == 1)
		{
			if(cont == 100)
			{
				printf("error ");
				scanf("%d", &i);
				continue;
			}
			struct node *temp = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &i);
			temp->num = i;
			temp->rlink = NULL;
			temp->llink = p;
			if(p != NULL)
			{
				p->rlink = temp;
			}
			p = temp;
			cont++;
		}
		else
		{
			if(cont == 0)
			{
				printf("error ");
				continue;
			}
			printf("%d ", p->num);
			cont--;
			struct node *temp = p;
			p = p->llink;
			free(temp);
			if(cont)
			{
				p->rlink = NULL;
			}
		}
	}
}

