#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int data;
	int hi;
	struct node *lchild;
	struct node *rchild;
};
struct node*  insertBST(struct node* p, int item,int hi);
void leaf(struct node* p);
int main(){
    int i, item;
    struct node* root=NULL;
    int n;scanf("%d",&n);
    while(n--){
    scanf("%d", &item);
    root=insertBST(root,item,1);
	}
	leaf(root);
	return 0;
} 
struct node* insertBST(struct node* p, int  item,int h)
{ 
    if(p == NULL){
        p = (struct node*)malloc(sizeof(struct node));
        p->data = item;
        p->hi=h;
        p->lchild = p->rchild = NULL;
    } 
    else if( item < p->data){
    	p->lchild=insertBST(p->lchild, item,h+1);
	}
    else if( item >= p->data)
       p->rchild=insertBST(p->rchild,item,h+1);
    return p;
}
//判断是否是叶子节点并输出 
void leaf (struct node* p)
{
	if(p!=NULL){
	if(p->lchild==NULL&&p->rchild==NULL)
		printf("%d %d\n",p->data,p->hi);
    leaf(p->lchild);
    leaf(p->rchild);
	}	
} 

