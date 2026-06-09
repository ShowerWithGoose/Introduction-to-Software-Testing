#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char word[30];
	int count;
	struct node* link;
}Wordscount,*LinkList;

int isLetter(char c)//判断是否字母
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	else
		return 0;
}
char BigToSmall(char c)//大写变为小写
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return c;
}

LinkList SAVE(FILE* in)//将in文件中的单词存入链表，返回链表首地址
{
	int flag = 0;
	LinkList add, list = NULL;
	char c;
	char tempstore[30] = "";
	int count = 0, length = 1;

	while ((c=fgetc(in))!=EOF)
	{
		c = BigToSmall(c);
		flag = 0;
		if ((isLetter(c)) == 0)//不是字母
		{
			tempstore[count] = '\0';
			if (tempstore[0] != '\0')//存单词
			{
				if (length == 1)//第一个单词：创建链表
				{
					add = (LinkList)malloc(sizeof(Wordscount));
					strcpy(add->word, tempstore);
					add->count = 1;
					add->link = NULL;
					list = add;
				}
				else//不是第一个单词
				{
					//先判断先前结点中有无该单词
					LinkList q = list, t = NULL;
					for (q = list; q != NULL; q = q->link)
					{
						if ((strcmp(q->word, tempstore)) == 0)//在前面找到了s
						{
							q->count++;
							flag = 1;
						}
					}
					if (flag == 0)//新单词，创建新结点，按顺序插入
					{
						add = (LinkList)malloc(sizeof(Wordscount));
						strcpy(add->word, tempstore);
						add->count = 1;
						if ((strcmp(tempstore, list->word)) < 0)//新单词比第一个小,插在list前面
						{
							add->link = list;
							list = add;
						}
						else
						{
							q = list;
							while (q != NULL && (strcmp(tempstore, q->word)) >= 0)//寻找插入位置，插在t,q之间
							{
								t = q;
								q = q->link;
							}
							add->link = q;
							t->link = add;
						}
					}
				}
				length++;
                memset(tempstore, '\0', sizeof(tempstore));
			    count = 0;
			    continue;
			}
		}
		else//是字母,存入s
		{
			tempstore[count] = c;
			count++;
		}
	}
	return list;
}

int main()
{
	FILE* in=fopen("article.txt","r");
	if (in == NULL)
	{
		perror("打开文件失败！\n");
		return 0;
	}

	LinkList list = NULL;//结果链表的头指针
	list = SAVE(in);
	LinkList q = list;
	for (q = list; q != NULL; q = q->link)
		printf("%s %d\n", q->word, q->count);
	fclose(in);
	return 0;
}


