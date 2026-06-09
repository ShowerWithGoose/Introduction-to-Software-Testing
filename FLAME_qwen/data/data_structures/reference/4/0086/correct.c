#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct st {
	char words[10];
	int mark;
	struct st* next;
}*head,*q,zan;
struct st* listsearch(struct st* top, struct st content);/*返回指针（相同的返回相同的指针，不同的返回内容小于它的指针）,没找到返回尾结点*/
void add(struct st** jie, struct st cont);/*在jie所指的链表节点之后添加一个新的节点，内容是i。只能加在head之后，如果要加在head之前，需要特判*/
int main()
{
	FILE* in;
	in = fopen("article.txt", "r");
	head = (struct st*)malloc(sizeof(struct st));
	head->words[0] = 'a', head->words[1] = 'a', head->words[2] = 'a', head->words[3] = '\0';
	head->next = NULL;
	q = head;
	zan.next = NULL;
	char e, op[10];
	int i=0;
	while ((fscanf(in,"%c",&e)) !=EOF)
	{
		if (e <= 'z' && e >= 'a')
			op[i++] = e;
		else if (e <= 'Z' && e >= 'A')
			e = e + 32,op[i++]=e;
		else
		{
			if (i == 0)
				continue;
			else
			{
				op[i] = '\0';
				strcpy(zan.words, op);
				i = 0;
				q = listsearch(head, zan);
				if (strcmp(q->words, zan.words) == 0)
					q->mark++;
				else
				{
					add(&q, zan);
				}
			}
		}
	}
	q = head->next;
	while (q != NULL)
	{
		printf("%s %d\n", q->words, q->mark+1);
		q = q->next;
	}
	fclose(in);
	return 0;
}
struct st* listsearch(struct st* top, struct st content)/*返回指针（相同的返回相同的指针，不同的返回内容小于它的指针）,没找到返回尾结点*/
{
	struct st* jian = top;
	while (jian->next != NULL)
	{
		if (strcmp(jian->next->words,content.words)>0)
			return jian;
		else if (strcmp(jian->next->words, content.words) == 0)
			return jian->next;
		else
			jian = jian->next;
	}
	return jian;
}
void add(struct st** jie, struct st cont)/*在jie所指的链表节点之后添加一个新的节点，内容是i。只能加在head之后，如果要加在head之前，需要特判*/
{
	struct st* content;
	content = (struct st*)malloc(sizeof(struct st));
	struct st* jian;
	jian = (*jie)->next;
	(*jie)->next = content;
	*content = cont;/*输入添加的结构体内容*/
	content->next = jian;
}
