#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define pf printf
#define sc scanf
#define MAX 1024


struct tree{
	int d;
	struct tree *lchild,*rchild;
};
void preBitree(struct tree *);
int j = 1;
int main()
{
	int n,data;
	sc("%d",&n);
	struct tree *root = NULL,*q,*p;
	for(int i = 0;i < n;i++){
		sc("%d",&data);
		
		q = (struct tree*)malloc(sizeof(struct tree));
		q->d = data;
		q->lchild = q->rchild = NULL;
		if(root == NULL){
				root = q;
		}
		
		else{
			p = root;
			while(1){
				if(data >= p->d){
					if(p->rchild == NULL){
						p->rchild = q;
						break;
					}
					else p = p->rchild;
				}
				else if(data < p->d){
					
					if(p->lchild == NULL){
						p->lchild = q;
						break;
					}
					else p = p->lchild;
				}
			}
		}
	}
	preBitree(root);
	return 0;
}

void preBitree(struct tree *T)//前序遍历
{
    if(T == NULL)
        return;//return不带参数返回时直接返回上一层函数
    else;
    {
        if(T->lchild == NULL && T->rchild == NULL)
        	printf("%d %d\n",T->d,j);//打印树中的节点数据
        j++;
        preBitree(T->lchild);//递归遍历左子树
        preBitree(T->rchild);//递归遍历右子树
        j--;
    }
}

