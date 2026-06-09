#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct LinkList
{
	char wo[50];
	int num;
	struct LinkList* next;
};

int main()
{
	FILE *in;
	in = fopen("article.txt", "r");
	
	struct LinkList* word = (struct LinkList*)malloc(sizeof(struct LinkList));
	struct LinkList* p;
	struct LinkList* q;
	struct LinkList* tool;
	p = word;
	q = word;
	p -> next = NULL;
	
	char str[1000], a[50];
	memset(str, '\0', sizeof(str));
	memset(a, '\0', sizeof(a));
	int i=0, j=0;
	
	while(fgets(str,1024,in) != NULL)
	{
		//change big to small
		for(i=0; i<strlen(str); i++)
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 'a' - 'A';
			}
		i = 0;
		//read word
		while(str[i] != '\0')
		{
			if(str[i] < 'a' || str[i] > 'z')
			{
				if(i == 0)
				{
					i++;
					continue;
				}
				else
				{
					if(a[0] == '\0')
					{
						i++;
						continue;
					}
					struct LinkList* s = (struct LinkList*)malloc(sizeof(struct LinkList));
					s -> num = 1;
					strcpy(s -> wo, a);
					p -> next = s;			
					p = s;
					p -> next = NULL;
					memset(a, '\0', sizeof(a));
					j = 0;			
				}
			}
			else
			{
				a[j] = str[i];
				j++;
			}
			i++;
		}
		//printf("%s\n",str);
	}
	struct LinkList* word_tail = (struct LinkList*)malloc(sizeof(struct LinkList));
	word_tail -> next = NULL;
	p -> next = word_tail;
	
	/*
	while(p -> next != NULL)
	{
		printf("%s %d\n", p -> wo, p -> num);
		p = p -> next;
	}
	*/
	//combine
	p = word -> next;
	while(p -> next != NULL)
	{
		q = p -> next;
		while(q -> next != NULL)
		{
			int cmp = strcmp(p -> wo, q -> wo);
			if(cmp == 0)
			{
				p -> num ++;
				tool = q -> next;
				strcpy(q -> wo, tool -> wo);
				q -> num = tool -> num;
				q -> next = tool -> next;
				free(tool);
				
				q = p -> next;
			}
			else
			{
				q = q -> next;
			}
		}
		p = p -> next;
	}	
	/*
	p = word -> next;	
	while(p -> next != NULL)
	{
		printf("%s %d\n", p -> wo, p -> num);
		p = p -> next;
	}
	*/
	//sort
	p = word -> next;
	while(p -> next != NULL)
	{
		q = p -> next;
		while(q -> next != NULL)
		{
			int cmp = strcmp(p -> wo, q -> wo);
			if(cmp > 0)
			{
				struct LinkList* s = (struct LinkList*)malloc(sizeof(struct LinkList));
				s -> next = NULL;
				strcpy(s -> wo, q -> wo);
				s -> num = q -> num;
				
				strcpy(q -> wo, p -> wo);
				q -> num = p -> num;
				strcpy(p -> wo, s -> wo);
				p -> num = s -> num;
				free(s);
				
				q = q -> next;
			}
			else
			{
				q = q -> next;
			}
		}
		p = p -> next;
	}
	//print
	p = word -> next;	
	while(p -> next != NULL)
	{
		printf("%s %d\n", p -> wo, p -> num);
		p = p -> next;
	}
	return 0; 
}




