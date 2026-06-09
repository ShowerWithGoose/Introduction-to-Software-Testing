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
	LinkList p, list = NULL;
	char c;
	char s[30] = "";
	int i = 0, n = 1;

	while ((c=fgetc(in))!=EOF)
	{
		c = BigToSmall(c);
		flag = 0;
		if ((isLetter(c)) == 0)//不是字母
		{
			s[i] = '\0';
			if (s[0] != '\0')//存单词
			{
				if (n == 1)//第一个单词：创建链表
				{
					p = (LinkList)malloc(sizeof(Wordscount));
					strcpy(p->word, s);
					p->count = 1;
					p->link = NULL;
					list = p;
				}
				else//不是第一个单词
				{
					//先判断先前结点中有无该单词
					LinkList n = list, fn = NULL;
					for (n = list; n != NULL; n = n->link)
					{
						if ((strcmp(n->word, s)) == 0)//在前面找到了s
						{
							n->count++;
							flag = 1;
						}
					}
					if (flag == 0)//新单词，创建新结点，按顺序插入
					{
						p = (LinkList)malloc(sizeof(Wordscount));
						strcpy(p->word, s);
						p->count = 1;
						if ((strcmp(s, list->word)) < 0)//新单词比第一个小,插在list前面
						{
							p->link = list;
							list = p;
						}
						else
						{
							n = list;
							while (n != NULL && (strcmp(s, n->word)) >= 0)//寻找插入位置，插在t,q之间
							{
								fn = n;
								n = n->link;
							}
							p->link = n;
							fn->link = p;
						}
					}
				}
				n++;
                memset(s, '\0', sizeof(s));
			    i = 0;
			    continue;
			}
		}
		else//是字母,存入s
		{
			s[i] = c;
			i++;
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
	LinkList n = list;
	for (n = list; n != NULL; n = n->link)
		printf("%s %d\n", n->word, n->count);
	fclose(in);
	return 0;
}


