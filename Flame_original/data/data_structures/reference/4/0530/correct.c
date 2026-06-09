#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct save {
	char word[20];
	int times;
	struct save* next;
}note, * ptr;
ptr head;
char tmp[200] ;
int number = 0;//记录总共有多少个不同的单词
void store(char kind[]);

int main()
{
	FILE* fp1 = NULL;
	fp1 = fopen("article.txt", "r");
	char* re;
	char save[10] = { '\0' };
	int len, i, j, cot = 0;
	while (fgets(tmp, 199, fp1)!=NULL)
	{
		len = strlen(tmp);
		for (i = 0; i < len; i++)
			if (tmp[i] >= 'A' && tmp[i] <= 'Z')
				tmp[i] = tolower(tmp[i]);
		for (i = 0; i < len; i++)
		{
			if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= 'A' && tmp[i] <= 'Z'))
			{
				for (; isalpha(tmp[i]) != 0; i++)
				{
					save[cot] = tmp[i];
					cot++;
				}
				store(save);
				cot = 0; memset(save, '\0', sizeof(save));
			}
		}
		memset(tmp, '\0', sizeof(tmp));
	}

	ptr p = head->next;
	for (i = 0; i < number; i++)
	{
		printf("%s %d\n", p->word, p->times);
		p = p->next;
	}
	return 0;
}


void store(char kind[])
{
	int flag = 0;
	ptr p = head, check, add;//这里分了头节点和首元节点；
	if (number == 0)
	{
		head = (ptr)malloc(sizeof(note)); memset(head->word, '\0', sizeof(note));
		head->next = p = (ptr)malloc(sizeof(note));
		strcpy(p->word, kind); p->times = 1; p->next = NULL;
		number++;
	}
	else
	{
		check = head->next;
		while (check != NULL)
		{
			if (strcmp(check->word, kind) == 0)
			{
				check->times++;
				flag = 1;
				break;
			}
			check = check->next;
		}
		if (flag == 0)
		{
			number++;
			check = head->next;
			add = (ptr)malloc(sizeof(note));
			strcpy(add->word, kind); add->times = 1; add->next = NULL;
			while (check != NULL)
			{
				if (check == head->next && strcmp(kind, check->word) < 0)//在头部插入
				{
					add->next = head->next;
					head->next = add;
					break;
				}
				else if (check->next == NULL && strcmp(kind, check->word) > 0)//在尾部插入
				{
					check->next = add; add->next = NULL;
					break;
				}
				else if (strcmp(kind, check->word) > 0 && strcmp(kind, check->next->word) < 0)//在中间插入
				{
					add->next = check->next; check->next = add;
					break;
				}
				check = check->next;
			}

		}
	}
}



