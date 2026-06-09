#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct tree {
	int data;
	int layer;
	struct tree *lchild,*rchild;
};
struct tree *root=NULL,*p=NULL,*q=NULL;

void insertBST(int item) {
	if(root==NULL) {
		root=p;//一个结点时
		//printf("root=%d\n",p->data);
		return;
	} else {
		q=root;
	}
	while(1) {
		if(item<q->data) {
			if(q->lchild==NULL) {
				p->layer++;
				q->lchild=p;
				//printf("lchild=%d\n",p->data);
				break;
			} else {
				p->layer++;
				q=q->lchild;
			}
		} else {
			if(q->rchild==NULL) {
				p->layer++;
				q->rchild=p;
				//printf("rchild=%d\n",p->data);
				break;
			} else {
				p->layer++;
				q=q->rchild;
			}
		}
	}
}

//void LeafCount(struct tree* root) {
//	struct tree *queue[1000],*p=NULL;
//	int front,rear;
//	if(root!=NULL) {
//		queue[0]=root;
//		front=0;
//		rear=1;
//		while(front<rear) {
//			p=queue[front];
//			front++;//刚才的第一个出去了
//			//printf("queue:%d\n",p->data);
//			if(p->lchild==NULL&&p->rchild==NULL) {
//				printf("%d %d\n",p->data,p->layer);
//			}
//			if(p->lchild!=NULL) {
//				queue[rear]=p->lchild;
//				rear++;
//			}
//			if(p->rchild!=NULL) {
//				queue[rear]=p->rchild;
//				rear++;
//			}
//		}
//	}
//}

void print(struct tree *root)
{
    if (root== NULL)
        return;
    if (root->lchild == NULL && root->rchild == NULL)
    {
        printf("%d %d\n", root->data, root->layer);
    }
    print(root->lchild);
    print(root->rchild);
    return;
}

int main() {
	int n,item,i;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&item);
		p=(struct tree*)malloc(sizeof(struct tree));
		p->data=item;
		p->lchild=NULL;
		p->rchild=NULL;
		p->layer=1;
		insertBST(item);
	}
	//printf("-----------------\n");
	print(root);
	return 0;
}

