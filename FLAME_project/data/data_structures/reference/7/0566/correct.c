/*从标准输入中输入一组整数，在输入过程中按照左子结点值小于根结点值、右子结点值大于等于根结点值的方式构造一棵二叉查找树，然后从左至右输出所有树中叶结点的值及高度（根结点的高度为1）。例如，若按照以下顺序输入一组整数：50、38、30、64、58、40、10、73、70、50、60、100、35，则生成下面的二叉查找树：

image.png

从左到右的叶子结点包括：10、35、40、50、60、70、100，叶结点40的高度为3，其它叶结点的高度都为4。

【输入形式】

先从标准输入读取整数的个数，然后从下一行开始输入各个整数，整数之间以一个空格分隔。
【输出形式】

按照从左到右的顺序分行输出叶结点的值及高度，值和高度之间以一个空格分隔。
【样例输入】

13

50 38 30 64 58 40 10 73 70 50 60 100 35
【样例输出】

10 4

35 4

40 3

50 4

60 4

70 4

100 4
【样例说明】

按照从左到右的顺序输出叶结点（即没有子树的结点）的值和高度，每行输出一个。
【评分标准】 
*/
#include <stdio.h>
#include <stdlib.h>
int htr;

struct btr{
	int data, h;
	struct btr *lc, *rc;
};
struct btr *root = NULL;
struct btr* insert(struct btr* p, int item)
{
	if (p == NULL)
	{
		p = (struct btr*)malloc(sizeof(struct btr));
		p->data = item;
		p->lc=p->rc = NULL;
	}
	else if (item < p->data)
	p->lc = insert(p->lc, item);
	else if (item >= p->data)
	p->rc = insert(p->rc, item);
	
	
	return p;
}
/*struct btr* search(struct btr* t)//前序遍历  
{
	struct btr* p = t;
	while (p != NULL)
	{
		if (p->lc == NULL&&p->rc == NULL)
		{
			return p;
			
			
		}
	}
}*/
int search(struct btr* root, struct btr* q)
{
	struct btr* p = root;
	int num = 0;
	while (p != NULL)
	{
		if (q == p)
		return num;
		else
		{
			num++;
			if (q->data >= p->data)//!
			{
				p = p->rc;
			}
			else
			{
				p = p->lc;
			}
		}
	}
}
/*int height()//层次遍历求高度 
{
	
}*/
void preorder(struct btr* t)
{
	
	if (t != NULL)
	{
		//num++;
		//num++;这样不能计量递归轮数 每个里面num重新置0 
		if (t->lc == NULL&&t->rc == NULL)
		{
			printf("%d %d\n", t->data, search(root, t)+1);//用全局变量也不行 
		}
		preorder(t->lc);
		preorder(t->rc);
		
	}
	//num = 0;
}
/*void layerorder(struct btr* t)
{
	struct btr* queue[1005], p = NULL;
	int front, rear;
	if (t != NULL)
	{
		queue[0] = t;
		front = -1;
		rear = 0;
	}
	while (front < rear)
	{
		p = queue[++front];
		
	}
}*/
//还不一定是完全二叉树 高度不是用树的高度减去子树的高度 

//还要有遍历函数 
int max(int a, int b)
{
	return (a > b)?a:b;
}
int height(struct btr* p)
{
	if (p == NULL)
	return 0;
	else 
	return 1+max(height(p->lc), height(p->rc));
}
int main()
{
	int n, i, hold;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &hold);
		root = insert(root, hold); 
	}
	htr = height(root);
	preorder(root);
	return 0;
}

