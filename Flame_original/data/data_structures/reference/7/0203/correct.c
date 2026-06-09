#include <stdio.h>
//数据存入树之后 是中序遍历得到从小到大排列的原序列 且允许有重复数据值
//建立一棵这样的树，输出叶结点数据及其所在的层数 
struct node{
	int data;
	int depth;
	struct node *leftc,*rightc;
}; 
typedef struct node BTNode, *BTNodeptr;

BTNodeptr *build_in_order(BTNode *t,int item,int n)
{
	n++;
	if(t==NULL)
	{
		t=(BTNodeptr*)malloc(sizeof(BTNode));
		t->data =item;
		t->leftc =t->rightc =NULL;
		t->depth =n;
	}
	else if(item<(t->data))
		t->leftc =build_in_order(t->leftc,item,n);
	else if(item>=(t->data))
		t->rightc =build_in_order(t->rightc,item,n);
	return t;
}
void in_order(BTNodeptr t)
{
	if(t!=NULL)
	{
		if(t->leftc ==NULL&&t->rightc ==NULL)
		printf("%d %d\n",t->data ,t->depth );
		
		in_order(t->leftc);
		in_order(t->rightc);
	}
}
int main(){
	int ori,i,tmp;
	int d;
	BTNodeptr *root=NULL;
	scanf("%d",&ori);
	for(i=0;i<ori;i++)
	{
		scanf("%d",&tmp);
		d=0;
		root=build_in_order(root,tmp,d); 
	}
	in_order(root);	 
	return 0;
}

