#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef int Datatype;
struct node {
	Datatype data;
	//int num;
	int cmp;//比较次数就是度-1; 
	struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
int M=100000;
int num[200000]={0};

int n,sum=0;

BTNodeptr Root = NULL; // Root是一个全局变量

void insertBST(int item) {
	BTNodeptr p, q;
	p = (BTNodeptr)malloc(sizeof(BTNode));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;
	if (Root == NULL)
	{
			Root = p;
			p->cmp=1;
			//printf("%d: \n",p->data);
			//p->num=1;
	}
	else {
		q = Root;
		p->cmp=1;
		//printf("%d:\n",p->data);
		while (1) {
			/* 比较值的大小 */
			/* 小于向左，大于向右 */
			if (item < q->data) {
				//printf("%d ",q->data);
				p->cmp++;
				if (q->lchild == NULL) {
					q->lchild = p;
					//p->num=1;
					//printf("cmp=%d ",p->cmp);
					//printf("\n");
					break;
				} else q = q->lchild;
			} else if (item >= q->data) {
				p->cmp++;
				//printf("%d ",q->data);
				if (q->rchild == NULL) {
					q->rchild = p;
					//printf("cmp=%d ",p->cmp);
					//printf("\n");
					break;
				} else
					q = q->rchild;
			}
		}
		sum+=p->cmp;
		//printf("num=%d\n ",p->num);
		//printf("sum=%d ",sum);
		//printf("\n");
	}
}



void VISIT(BTNodeptr p) {	
	//printf("%d: ",p->data);
	//printf("%d ",num[p->data+M]);
	//printf("%d ",p->cmp);
	//printf("%d ",sum);
	//printf("%d ",p->num);
	//printf("\n");
	//printf("maxci=%d\n",maxci);
	if((p->lchild == NULL)&&(p->rchild == NULL)) 
	{
		printf("%d %d\n",p->data,p->cmp);
	}
}

void postorder(BTNodeptr t) {
	BTNodeptr stack1[n], p = t;
	int stack2[n], top = -1, flag;
	if (t != NULL)
		do {
			while (p != NULL) {
				stack1[++top] = p;//当前P所指结点的地址进栈
				stack2[top] = 0; //当前P所指结点不可访问标志进栈
				p = p->lchild;
			} // P指向其左孩子结点
			p = stack1[top];
			flag = stack2[top--]; //退栈
			if (flag == 0) {
				stack1[++top] = p; //当前P所指结点再次进栈
				stack2[top] = 1; // 当前P所指结点可访问标志进栈
				p = p->rchild;
			} else {
				VISIT(p);
				p = NULL; //表明以P结点为根的树访问完成
			}
		} while (p != NULL || top != -1);
}

int main() {
	int i, item;
	BTNodeptr root = NULL;

	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		//构造一个有n个元素的BST树
		scanf(" %d", &item);
		num[item+M]++;
		//printf("%d ",item);
		//printf("%d\n",num[item]);
		insertBST(item);
	}
	//printf("%d\n",sum);
	postorder(Root);
	//printf("max=%d\n",maxnum);
	return 0;
}

