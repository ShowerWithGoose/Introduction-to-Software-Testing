#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int a;
	int x;
	struct node *link;
};

struct node *sort(struct node *head) 
{
    struct node *current=head;
    struct node *index=NULL;
    int temp1,temp2;

    if (head==NULL) 
	{
        return head;
    } 
	else 
	{
        while (current!=NULL) 
		{
            index = current->link;

            while (index != NULL) 
			{
                if (current->x < index->x) 
				{
                    temp1 = current->a;
                    temp2 = current->x;
                    current->a = index->a;
                    current->x = index->x;
                    index->a = temp1;
                    index->x = temp2;
                }
                index = index->link;
            }
            current = current->link;
        }
    }

    return head;
}

int main()
{
	struct node *list1=NULL,*list2=NULL,*p=NULL,*q=NULL;
	char c;
	do
	{
		q=(struct node*)malloc(sizeof(struct node));
		scanf("%d %d%c",&(q->a),&(q->x),&c);
		q->link=NULL;
		if(list1==NULL)
		{
			list1=p=q;
		}
		else
		{
            p->link=q;
		}
		p=q;
	}while(c!='\n');
	
	do
	{		
		q=(struct node*)malloc(sizeof(struct node));
		scanf("%d %d%c",&(q->a),&(q->x),&c);
		q->link=NULL;	
		if(list2==NULL)
		{
			list2=p=q;
		}
		else
		{
			p->link=q;
		}
		p=q;
	}while(c!='\n');
	struct node *result=NULL;
    struct node *t1,*t2;
    for(t1=list1;t1!=NULL;t1=t1->link)
    {
    	for(t2=list2;t2!=NULL;t2=t2->link)
    	{
    		int num=t1->a*t2->a;
            int on=t1->x+t2->x;

            struct node *newnode=(struct node*)malloc(sizeof(struct node));
            newnode->a=num;
            newnode->x=on;
            newnode->link=NULL;
			
			struct node *pre=NULL, *current=result;
            while (current != NULL && current->x > newnode->x) 
			{
                pre = current;
                current = current->link;
            }
            if (current != NULL && current->x == newnode->x) 
			{
                current->a += newnode->a;
                free(newnode); 
            } 
			else 
			{
                if (pre == NULL) 
				{
                    newnode->link = result;
                    result = newnode;
                } 
				else 
				{
                    pre->link = newnode;
                    newnode->link = current;
                }
            }
		}
	}
	sort(result);
	for (struct node *current=result;current!=NULL;current=current->link) 
	{
        printf("%d %d ",current->a,current->x);
    }
	while(list1!=NULL)
    {
        p=list1;
        list1=list1->link;
        free(p);
    }
    while(list2!=NULL)
    {
        p=list2;
        list2=list2->link;
        free(p);
    }
    while (result != NULL) 
	{
        p=result;
        result=result->link;
        free(p);
    }
    return 0;
}


