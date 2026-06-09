#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char cha[50];
int cmp(const void*, const void*);
struct node
{
	char ch[50];
	int num;
}; 
int main()
{
	struct node *word[10000];
	int i, cnt = 0, wordsum = 0;
	char now;
	FILE *in;
	in = fopen("article.txt", "r");
	while(1)
	{
		i = fscanf(in, "%c", &now);
		if(i == EOF)
		{
			break;
		}
		if(now >= 'a' && now <= 'z')
		{
			cha[cnt++] = now;
			continue;
		}
		if(now >= 'A' && now <= 'Z')
		{
			cha[cnt++] = (now - 'A') + 'a';
			continue;
		}
		if(cnt > 0)
		{
			if(wordsum == 0)
			{
				word[wordsum] = (struct node*)malloc(sizeof(struct node));
				memset(word[wordsum]->ch, 0, sizeof(word[wordsum]->ch));
				strcpy(word[wordsum]->ch, cha);
				word[wordsum]->num = 1;
				wordsum++;
			}
			else
			{
				int flag = 0;
				for(int j = 0; j < wordsum; j++)
				{
					if(strcmp(word[j]->ch, cha) == 0)
					{
						word[j]->num++;
						flag = 1;
						break;
					}
				}
				if(flag == 0)
				{
					word[wordsum] = (struct node*)malloc(sizeof(struct node));
					memset(word[wordsum]->ch, 0, sizeof(word[wordsum]->ch));
					strcpy(word[wordsum]->ch, cha);
					word[wordsum]->num = 1;
					wordsum++;
				}
			}
			cnt = 0;
			memset(cha, 0, sizeof(cha));
			continue;
		} 	
	}
	qsort(word, wordsum, sizeof(struct node *), cmp);
	for(int k = 0; k < wordsum; k++)
	{
		printf("%s %d\n", word[k]->ch, word[k]->num);
	}
	return 0;
}
int cmp(const void *p1, const void *p2)
{
	struct node *P1 = *(struct node **)p1, *P2 = *(struct node **)p2;
	char *a = P1->ch, *b = P2->ch;
	return strcmp(a, b);
}

