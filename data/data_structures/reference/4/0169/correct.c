#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXN 1005

typedef struct tree
{
	char word[21];
	int num;
	struct tree *rchild, *lchild; 
} *BTREE, BTNode;

char buff[MAXN], wBuff[21];
int len, len1;
BTREE root = NULL;

char trans(char ch)//必须先判定是字母才能用 
{
	return islower(ch) != 0 ? ch : ch - 'A' + 'a';
}
int search(int i)
{
	memset(wBuff, 0, sizeof(wBuff)); 
	int j = 0;
	while (isalpha(buff[i]) != 0)
	{
		wBuff[j++] = trans(buff[i]);
		i++;
	}
	return i;
}

void ins_tree(BTREE p)
{
	BTREE q = NULL;
	
	if (strcmp(wBuff, p->word) < 0)
	{
		if(p->lchild == NULL)
		{
			q = p;
			p = (BTREE)malloc(sizeof(BTNode));
			strcpy(p->word, wBuff);
			p->num = 1;
			p->lchild = NULL;
			p->rchild = NULL;
			q->lchild = p;
			return;
		}//判空 
		ins_tree(p->lchild);//递归左子树 
		return;
	} 
	else if (strcmp(wBuff, p->word) > 0)
	{
		if(p->rchild == NULL)
		{
			q = p;
			p = (BTREE)malloc(sizeof(BTNode));
			strcpy(p->word, wBuff);
			p->num = 1;
			p->lchild = NULL;
			p->rchild = NULL;
			q->rchild = p;
			return;
		}//判空
		ins_tree(p->rchild);//递归右子树 
		return;
	}
	else
	{
		p->num++;//权值加1 
		return;
	}
}//递归实质是一种栈结构 

void print(BTREE p)//中序遍历
{
	if(p == NULL)
	{
		return;
	}
	print(p->lchild); 
	printf("%s %d\n", p->word, p->num);
	print(p->rchild);
} 

int main()
{
	memset(buff, 0, sizeof(buff));
	memset(wBuff, 0, sizeof(wBuff));
	
	FILE *p_article = fopen("article.txt", "r");
	int i;
	
	if(p_article == NULL)//指针健壮性检验 
	{
		perror("Cannot open 'article.txt'");
		return 1;
	}
	
	while (fgets(buff, 1004, p_article) != NULL)
	{
		len1 = strlen(buff);
		for (i = 0; i <= len1 - 1; i++)
		{
			if(isalpha(buff[i]) != 0)
			{
				i = search(i);
				if(root == NULL)
				{
					root = (BTREE)malloc(sizeof(BTNode));
					strcpy(root->word, wBuff);
					root->num = 1;
					root->lchild = NULL;
					root->rchild = NULL;
				}
				else
				{
					ins_tree(root);//插入元素 
				}
			}
			else
			{
				continue;
			}
		}
		
		memset(buff, 0, sizeof(buff));
	}
	
	print(root);
	
	fclose(p_article);
	return 0;
}

