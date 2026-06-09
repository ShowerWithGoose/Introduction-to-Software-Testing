#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct  node {
          int   data;
          struct  node   *lchild,  *rchild;
          int d;//高度 
   };
typedef struct node  bst;
typedef struct node  *pbst;


void v(pbst t)// 访问结点 
{
	printf("%d %d\n",t->data,t->d);
}
pbst insert(pbst p,int m,int depth)
{     if(p == NULL){     
        p = (pbst)malloc(sizeof(bst));
        p->data = m;
        p->d=depth;
        p->lchild = p->rchild = NULL;
    } 
    else if( m< p->data)
        p->lchild = insert(p->lchild, m,depth+1);
    else if( m>=p->data)
       p->rchild = insert(p->rchild,m,depth+1);
       
    
    return p;

}
void  postorder(pbst t)
{
      if(t!=NULL){
             postorder(t->lchild);
             postorder(t->rchild);
             if(t->lchild==NULL&&t->rchild==NULL)
			 v(t); // 访问t指的结点 
      }
}
int main()
{ int n,i,m;
scanf("%d",&n);
pbst root=NULL;//根指针 
int dep=1;//高度计数 
for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		root = insert(root,m,dep);}
	postorder(root);
	return 0;
}

