#include<stdio.h>//已做优化 
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	long long index, ratio;
	struct Node *right, *left;
} *LNode, LinkList;

LNode list = NULL, list1 = NULL, list2 = NULL, list3 = NULL, root = NULL;

void ins(LNode s)
{
	LNode p = root, r = NULL, t = NULL;
	while (p != NULL)
	{
		r = p;
		if (s->index > p->index)
		{
			if(p->left != NULL)
			{
				t = p->left;
				t->right = s;
				s->left = t;
			}
			s->right = p;
			p->left = s;
			root = s;
			return; 
		}
		else if (s->index < p->index)
		{
			p = p->right;
			continue;
		}
		else //指数相等 
		{
			p->ratio = p->ratio + s->ratio;//
			free(s);//释放内存 合并后一定要释放s 
			s = NULL;
			root = p;
			return;
		}
	}
	r->right = s;
	s->left = r;
	root = s;
}

int main()
{
	//freopen("multiply.in", "r", stdin);
	char ch;
	long long ind, ra;
	LNode p = NULL, q = NULL, r = NULL, s = NULL;
	while (1)
	{
		scanf("%lld %lld", &ra, &ind);
		r = p;//上一个节点 
		p = (LNode)malloc(sizeof(LinkList));
		p->ratio = ra;
		p->index = ind;
		p->left = NULL;
		p->right = NULL;
		if (list1 == NULL)
		{
			list1 = p;//建立表头 
		}
		if (r == NULL)
		{
			p->left = NULL; 
		}
		else
		{
			p->left = r;
			r->right = p;
		}
		p->right = NULL;
		if((ch = getchar()) == '\n')
		{
			break;
		}
	}
	/*
	p = list1;
	while(p != NULL)
	{
		r = p;
		printf("%lld %lld ", p->ratio, p->index);
		p = p->right;
	}
	*/
	p = NULL;
	r = NULL;
	
	while ((scanf("%lld%lld", &ra, &ind))!= EOF)
	{
		r = p;//上一个节点 
		p = (LNode)malloc(sizeof(LinkList));
		p->ratio = ra;
		p->index = ind;
		p->left = NULL;
		p->right = NULL;
		if (list2 == NULL)
		{
			list2 = p;//建立表头 
		}
		if (r == NULL)
		{
			p->left = NULL; 
		}
		else
		{
			p->left = r;
			r->right = p;
		}
		p->right = NULL;
	}
	/*
	printf("\n");
	p = list2;
	while(p != NULL)
	{
		r = p;
		printf("%lld %lld ", p->ratio, p->index);
		p = p->right;
	}
	*/
	p = NULL;
	r = NULL;
	
	p = list1;
	while (p != NULL)
	{
		q = list2;
		if(list != NULL)
		{
			root = list;
		}
		while (q != NULL)
		{
			s = (LNode)malloc(sizeof(LinkList));
			s->ratio = p->ratio * q->ratio;//ratio永不为零（题目已经保证） 
			s->index = p->index + q->index;
			s->left = NULL;
			s->right = NULL;
			if(list == NULL)
			{
				list = s;
				root = s;
				q = q->right;
				continue;//插入已完成 
			}
			ins(s);
			q = q->right;
		}
		p = p->right; 
	}
	//输出答案并释放内存 
	//printf("\n");
	p = list;
	while(p != NULL)
	{
		r = p;
		printf("%lld %lld ", p->ratio, p->index);
		p = p->right;
		free(r);
	}
	r = NULL;
	
	p = list1;
	while(p != NULL)
	{
		r = p;
		p = p->right;
		free(r);
	}
	r = NULL;
	
	p = list2;
	while(p != NULL)
	{
		r = p;
		p = p->right;
		free(r);
	}
	r = NULL;
	//fclose(stdin);
	return 0;
}











