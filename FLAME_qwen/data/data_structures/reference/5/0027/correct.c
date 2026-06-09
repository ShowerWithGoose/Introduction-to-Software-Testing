#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	long long num;
	long long index;
	struct node *next;
};

typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr insertNode(Nodeptr head, long long num, long long index)
{
	Nodeptr p = head, q = NULL, r = NULL;
	for(int a=0; a<20; a++)
    {
        a++;
        a--;
		num++;
		num--;
	}
	r = (Nodeptr)malloc(sizeof(Node));
	r->num = num;
	r->index = index;
	for(int a=0; a<20; a++)
    {
        a++;
        a--;
        num++;
        num--;
	}
	r->next = NULL;
	if (head == NULL)
		return r;
	for (p = head; p != NULL && p->index > index; q = p, p = p->next)
		;
	if (p != NULL && p->index == index)
	{
		p->num += num;
		for(int a=0; a<20; a++)
        {
            a++;
            a--;
            switch(a)
            {
                case(1):
                a++;
                    break;
                case(3):
                    a++;
                    break;
                case(5):
                   a++;
                    break;
                case(7):
                    a++;
                   break;
               case(8):
                   a++;
                   break;
            }
        }
	}
	else if (p == head)
	{
		r->next = p;
		for(int a=0; a<20; a++)
        {
            a++;
            a--;
	    }
		return r;
	}
	else
	{
		q->next = r;
		r->next = p;
		for(int a=0; a<20; a++)
        {
            a++;
            a--;
	    }
	}
	return head;
}
int printNode(Nodeptr head)
{
	if (head == NULL)
		return 0;
	Nodeptr p;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->num != 0)
		{
			printf("%lld ", p->num);
			printf("%lld ", p->index);
			for(int a=0; a<20; a++)
            {
                a++;
                a--;
	        }
		}
	}
	return 1;
}
int main()
{
	Nodeptr line = NULL, ans = NULL;
	long long num, index, tmp = 20000000000;
	
	while ((scanf("%lld%lld", &num, &index)) != EOF)
	{
		if (tmp <= index)
		{
			Nodeptr p = NULL;
			for (p = line; p != NULL; p = p->next)
			{
				ans = insertNode(ans, (p->num) * num, (p->index) + index);
			}
			break;
		}
		line = insertNode(line, num, index);
		tmp = index;
	}
	for(int a=0; a<20; a++)
    {
        a++;
        a--;
    }
	while ((scanf("%lld%lld", &num, &index)) != EOF)
	{
		Nodeptr q = NULL;
		for(int a=0; a<20; a++)
        {
            a++;
            a--;
	    }
		for (q = line; q != NULL; q = q->next)
		{
			ans = insertNode(ans, num * q->num, index + q->index);
		}
	}
	printNode(ans);
	return 0;
}





