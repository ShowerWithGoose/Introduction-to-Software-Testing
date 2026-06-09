#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct dc
{
	char arr[100];
	struct dc* link;
	int num;
}ps;
int i = 0;
char tmp[40]={'\0'};
int main()
{
	char c;
	FILE* IN;
	ps* head=NULL;
	ps* p=NULL;
	ps* r=NULL;
	ps* j=NULL;
	int pre_num = 0;
	int now=0;
	int before=-1;
	IN=fopen("article.txt", "r");
	while ((c = fgetc(IN)) != EOF)
	{
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		{

			now = 0;
			if (now == 0 && before == -1)
			{
				i = 0;
				if ('A' <= c&&c<='Z')
				{
					tmp[i] = c+'a'-'A';
				}
				else if('a'<=c&&c<='z')
				{
					tmp[i] = c;
				}
				
			}
			else if(now==0&&before==0)
			{
				if ('A' <= c && c <= 'Z')
				{
					tmp[i] = c + 'a' - 'A';
				}
				else if ('a' <= c && c <= 'z')
				{
					tmp[i] = c;
				}
			}
			i++;
		}
		else
		{
			now = -1;
			if (before == 0 && now == -1)
			{
				tmp[i] = '\0';
				if (pre_num == 0)
				{
					head = (struct dc*)malloc(sizeof(ps));
					head->num = 1;
					strcpy(head->arr, tmp);
					
					head->link = NULL;
					pre_num+=1;
					r = head;
				}
				else
				{
				
					j = head;
					int tims = 0;
					while (j != NULL)
					{
						if (strcmp(j->arr, tmp) == 0)
						{
							j->num++;
							tims = 1;
							break;
						}
						j = j->link;
					}
					if (tims == 0)
					{
						p = (struct dc*)malloc(sizeof(ps));
						p->num = 1;
						p->link = NULL;
						strcpy(p->arr, tmp);
						r->link = p;
						r = p;
						pre_num += 1;
					}
				}
				i = 0;
			}
		}
		before = now;
	}
	while (1)
	{
		p = head;
		int point = 0;
		while (p->link != NULL)
		{
			if (strcmp(p->arr, p->link->arr) > 0)
			{
				char si[100];
				int sis = p->num;
				strcpy(si, p->arr);
				strcpy(p->arr, p->link->arr);
				strcpy(p->link->arr, si);
				p->num = p->link->num;
				p->link->num = sis;
				point = 1;
			}
			else
			{
				p = p->link;
			}
		}
		if (point == 0)
		{
			break;
		}
		else
		{
			p = head;
		}
	}
	p = head;
	while (1)
	{
		if (p == NULL)
		{
			break;
		}
		printf("%s %d\n", p->arr, p->num);
		p = p->link;
	}
	return 0;
}

