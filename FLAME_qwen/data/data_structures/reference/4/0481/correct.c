#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char string[101][101];
struct node{
	char str[101];
	int cnt;
	struct node* link; 
};
typedef struct node* Nodeptr;

void A_a(char str[]);  //转换小写 
Nodeptr createlist(Nodeptr list, char string[]);
Nodeptr insertlist(Nodeptr list, Nodeptr elem);
void printflist(Nodeptr list);

int main()
{
	Nodeptr list = NULL;
	FILE *in;
	int i = 0, j = 0;
	char ch;
	
	in = fopen("article.txt","r");
	if(in == NULL)
		return 1;
	ch = fgetc(in);
	//收集单词 
	while(ch != EOF)
	{
		if(isalpha(ch) != 0)
		{
			string[i][j] = ch;
			j++;
		}
		else
		{
			if(isspace(ch) != 0 || ispunct(ch) != 0)//判断空格和标点符号如 ,.:;"' #@￥%……&*()-= 
			{
				string[i][j] = '\0';
				if(strlen(string[i]) != 0)
					i++;
				j = 0;
			}
		}//数字直接不管即可 ，也不会被录入 
		ch = fgetc(in);
	}
	//创造链表 
	for(j = 0; j < i; j++)
	{
		A_a(string[j]);
		list = createlist(list, string[j]);
	}
	printflist(list);
	fclose(in);
	return 0;
}

void A_a(char str[])
{
	int j;
	// 大写变小写 
	for(j = 0; j < strlen(str); j++) 
	{
		if(isupper(str[j]) != 0)
		{
			str[j] = tolower(str[j]);
			continue;
		}
	}
} 

Nodeptr createlist(Nodeptr list, char string[])
{
	Nodeptr head = list, elem;
	elem = (Nodeptr)malloc(sizeof(struct node));
	elem->cnt = 1;
	strcpy(elem->str, string);
	elem->link = NULL;
	head = insertlist(head, elem);
	return head;
}

Nodeptr insertlist(Nodeptr list, Nodeptr elem)
{
	Nodeptr head, p, q = NULL;
	head = list;
	//head空
	if(head == NULL)
	{
		head = elem;
		head->link = NULL;
		return head;
	} 
	else
	{ 
		p = list;
		//对比前面的项，若有一样的则合并，否则插入
		while(p != NULL)
		{
			if(strcmp(p->str, elem->str) == 0)
			{
				p->cnt++;
				return head;
			}
			else
			{
				if(strcmp(p->str, elem->str) < 0)
				{
					q = p;
					p = p->link;//q比p慢一步，便于插入 
				}
				else
				{
					if(q != NULL)//避免头部添加的情况，此时q空 
						q->link = elem; 
					else
						head = elem;
					elem->link = p;
					return head;
				}
			}
		}
		//在链表尾部添加的情况 
		q->link = elem;
		q = q->link;
		q->link = NULL;
		return head; 
	}
}

void printflist(Nodeptr list)
{
	Nodeptr p;
	p = list;
	while(p != NULL)
	{
		printf("%s %d\n", p->str, p->cnt);
		p = p->link;	
	}
}

