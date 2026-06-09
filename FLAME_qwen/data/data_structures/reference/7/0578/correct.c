#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    int layer;
    struct node *left, *right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
void perorder(BTNodeptr t);
void insertBST(int item);
int main()
{
    int i,item,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){ //构造一个有n个元素的BST树
         scanf("%d",&item);
         insertBST(item);
     }
    perorder(root); 
    return 0;
}

//插入一个元素
void insertBST(int item){ 
      BTNodeptr p,q;
      p=(BTNodeptr)malloc(sizeof(BTNode));
      p->data=item,p->left=NULL,p->right=NULL,p->layer=1;
      if(root==NULL)
       root=p;
      else{
       q=root;
       while(1){
         /* 比较值的大小 */
         /* 小于向左，大于向右 */
         if(item<q->data){
             if(q->left==NULL){
             	    p->layer++;
                    q->left=p;
                    break;
             }
             else q=q->left,p->layer++;
         }
         else{
              if(q->right==NULL){
              	     p->layer++;
                     q->right=p;
                     break;     
             }
             else q=q->right,p->layer++;
         }
    }
  }     
}
//遍历 找叶节点 
void perorder(BTNodeptr t){//根左右 
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL) 
			printf("%d %d\n",t->data,t->layer);        //visit(t)
		perorder(t->left);
		perorder(t->right);
	}
}



