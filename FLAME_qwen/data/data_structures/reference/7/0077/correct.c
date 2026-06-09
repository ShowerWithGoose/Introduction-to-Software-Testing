#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
typedef int Typedata;
typedef int Datatype;
struct node{
	Datatype data;
	struct node *left,*right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr  Root=NULL; //Root是一个全局变量
BTNodeptr  root=NULL;
int h=0;
void  insertBST( Typedata item);
BTNodeptr  searchBST( BTNodeptr t);
int  getlayerBST(BTNodeptr t, Datatype item);
int main()
{
	int item;
	int n;
	int i;
	BTNodeptr t=NULL;
	BTNodeptr q=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&item);
		insertBST(item);
	}
	t=Root;
	searchBST(t);

 return 0;
}

void  insertBST( Typedata item)
{
      BTNodeptr p, q;
      p=(BTNodeptr)malloc(sizeof(BTNode));
      p->data=item;
      p->left=NULL;
      p->right=NULL;
      if(Root==NULL)
      Root=p;
	  else{
		q=Root;
    while(1) {
         /* 比较值的大小 */
         /* 小于向左，大于向右 */
         if(item<q->data)  {
             if(q->left==NULL){
                    q->left=p;
                    break;
             }
             else
                    q=q->left;
         }
         else if (item>q->data) {
              if(q->right==NULL){
                     q->right=p;
                     break;     
             }
             else
                     q=q->right;
         }
         else { 
		if(q->right==NULL){
                     q->right=p;
                     break;     
             }
             else
                     q=q->right;
         }
		 }
    }
          
}
BTNodeptr  searchBST( BTNodeptr t)
{
	  if(t!=NULL){
            if(t->left==NULL && t->right==NULL) {
            	printf("%d %d\n",t->data,getlayerBST(t,t->data));
            	return t; 
			}
                                          /* 查找成功  */ 
                               /* 查找T的右子树  */                              
            else{			
                  searchBST(t->left);
				  searchBST(t->right);
				}
				   
       }                                                  /* 查找T的左子树 */
        else return NULL;                    /* 查找失败  */
}
int  getlayerBST(BTNodeptr t, Datatype item)
{
      int h=1;
      int flag=0;
	  BTNodeptr  p=Root;

      while(p!=NULL){
            if(item == p->data && p==t) 
                  return h; 
			
			else if(item == p->data && p!=t )  {
				p=p->right;
				h++;
				
			}                
            if(item > p->data){
                  h++;
                  p=p->right;          /* 将p 移到右子树的根结点 */
            }
            else if(item < p->data){
                  h++;
                  p=p->left;           /* 将p 移到左子树的根结点 */
            }
		}
		
}



