#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
typedef struct node{
	char word[25];
	int num;
	struct node *link;
}LNode, *LinkList;
int main()
{
	char s[1005];
	FILE *in = fopen("article.txt", "r");
	int i, j = 0, flag = 0;
	LinkList list = NULL, p, q, r;
	p = (LinkList)malloc(sizeof(LNode));
	p->link = NULL;
	while(fgets(s,1000,in) != NULL)	//按升序排字母并计数 
	{
		for(i = 0; i < strlen(s); i++)
		{
			if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
			{
				p->word[j++] = tolower(s[i]);
				flag = 1;
			}
			else if(flag != 0)
			{
				p->word[j] = '\0';
				j = 0;
				flag = 0;
				if(list == NULL || strcmp(p->word, list->word) < 0)
				{
					p->link = list;
					p->num = 1;
					list = p;
				}
				else if(strcmp(p->word, list->word) == 0)
					list->num += 1;
				else
				{
					q = list;
					while(q != NULL && strcmp(p->word, q->word) > 0)
					{
						r = q;
						q = q->link;
					}
					if(q != NULL && strcmp(p->word, q->word) == 0)
						q->num += 1;
					else
					{
						p->link = q;
						p->num = 1;
						r->link = p;
					}
				}
				p = (LinkList)malloc(sizeof(LNode));
				p->link = NULL;
			}
		}
	}
	free(p);
	for(p = list; p != NULL; p = p->link)
		printf("%s %d\n", p->word, p->num);
	return 0;
}



