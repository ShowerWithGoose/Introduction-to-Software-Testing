#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int data;
	int depth;
	struct node *left,*right;
};//在插入元素时就记录深度，方便输出 

void  inorder(struct node* t);
int main()
{
int n,i,item,cnt;
struct node *root=NULL, *p, *q;
scanf("%d",&n);
for (i=0;i<n;i++){
	scanf("%d",&item);
	p=(struct node*)malloc(sizeof(struct node));
	p->data=item,p->left=NULL,p->right=NULL;
	if (root==NULL){
		root=p;
		p->depth=1;
	}
	else{
		cnt=1;
		q=root;
		while(1){
			if (item < q->data){
				if (q->left==NULL){
				q->left=p;
				p->depth=cnt+1;
				break;
				}
				else
				q=q->left,cnt++; 
			}
			else if (item >= q->data){
				if (q->right==NULL){
					q->right=p;
					p->depth=cnt+1;
					break;
				}
				else
				q=q->right,cnt++;
			}
		}	
	} 
}
inorder(root);

return 0;
}
void  inorder(struct node* t)
{
      if(t!=NULL){
             inorder(t->left);
             if (t->left==NULL&&t->right==NULL) printf("%d %d\n",t->data,t->depth) ;      /* 访问T指结点  */
             inorder(t->right);
       }
}












