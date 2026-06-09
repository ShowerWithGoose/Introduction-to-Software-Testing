#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int index;
	struct tree *llink,*rlink;
}treenode;
typedef treenode* nodeptr;
void getleaf(int height,nodeptr p)
{
	if(p->llink==NULL&&p->rlink==NULL)
	    printf("%d %d\n",p->index,height);
	else{
		if(p->llink!=NULL)
		    getleaf(height+1,p->llink);
		if(p->rlink!=NULL)
		    getleaf(height+1,p->rlink);
	}
}
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	nodeptr root=NULL,p,q;
	for(;n>0;n--){
		q=(nodeptr)malloc(sizeof(treenode));
		scanf("%d",&q->index);
		q->llink=q->rlink=NULL;
		if(root==NULL)//生成新树 
			root=q;
		else{
			p=root;
			while(p!=NULL){
				if(p->llink==NULL&&p->index>q->index){
				    p->llink=q;
				    break;
				}
				if(p->rlink==NULL&&p->index<=q->index){
					p->rlink=q;
					break;
				}//找到插入位置 
				if(p->index>q->index&&p->llink!=NULL)
				    p=p->llink;
				if(p->index<=q->index&&p->rlink!=NULL)
				    p=p->rlink;//没有延伸足够层数，再深入 
			}
		}
	}//二叉树建立完毕
	getleaf(1,root);
	return 0; 
}

