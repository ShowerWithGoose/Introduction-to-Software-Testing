#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct dc
{
	char arr[100];
	struct dc* link;
	int num;
}ps;
int arr = 0;
char tmp[40]={'\0'};
int main()
{
	char c;
	FILE* IN;
	ps* start=NULL;
	ps* q=NULL;
	ps* r=NULL;
	ps* j=NULL;
	int check = 0;
	int now=0;
	int p=-1;
	IN=fopen("article.txt", "r");
	while ((c = fgetc(IN)) != EOF)
	{
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		{

			now = 0;
			if (now == 0 && p == -1)
			{
				arr = 0;
				if ('A' <= c&&c<='Z')
				{
					tmp[arr] = c+'a'-'A';
				}
				else if('a'<=c&&c<='z')
				{
					tmp[arr] = c;
				}
				
			}
			else if(now==0&&p==0)
			{
				if ('A' <= c && c <= 'Z')
				{
					tmp[arr] = c + 'a' - 'A';
				}
				else if ('a' <= c && c <= 'z')
				{
					tmp[arr] = c;
				}
			}
			arr++;
		}
		else
		{
			now = -1;
			if (p == 0 && now == -1)
			{
				tmp[arr] = '\0';
				if (check == 0)
				{
					start = (struct dc*)malloc(sizeof(ps));
					start->num = 1;
					strcpy(start->arr, tmp);
					
					start->link = NULL;
					check+=1;
					r = start;
				}
				else
				{
				
					j = start;
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
						q = (struct dc*)malloc(sizeof(ps));
						q->num = 1;
						q->link = NULL;
						strcpy(q->arr, tmp);
						r->link = q;
						r = q;
						check += 1;
					}
				}
				arr = 0;
			}
		}
		p = now;
	}
	while (1)
	{
		q = start;
		int point = 0;
		while (q->link != NULL)
		{
			if (strcmp(q->arr, q->link->arr) > 0)
			{
				char si[100];
				int sis = q->num;
				strcpy(si, q->arr);
				strcpy(q->arr, q->link->arr);
				strcpy(q->link->arr, si);
				q->num = q->link->num;
				q->link->num = sis;
				point = 1;
			}
			else
			{
				q = q->link;
			}
		}
		if (point == 0)
		{
			break;
		}
		else
		{
			q = start;
		}
	}
	q = start;
	while (1)
	{
		if (q == NULL)
		{
			break;
		}
		printf("%s %d\n", q->arr, q->num);
		q = q->link;
	}
	return 0;
}

