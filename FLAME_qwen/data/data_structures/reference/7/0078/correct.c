#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#define Datatype int
typedef int Datatype;
struct node {
    Datatype data;
    int high;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  root=NULL; //Root是一个全局变量
int high=1;
BTNodeptr  insertBST(BTNodeptr p, Datatype item,int high){
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
        p->high = high;
    }
    else if( item < p->data)
        p->left = insertBST(p->left, item,high+1);
    else //if( item > p->data)
       p->right = insertBST(p->right,item,high+1);
    //else
      // do-something; //树中存在该元素
    return p;
}

/*void  sortTree(Datatype k[ ], int n,int len)
{
       int i;
       for(i=0; i<n; i++)
             insertBST(k[i],len);
       return  ;
 }  */

void leafheight(BTNodeptr  root){
	if (root!=NULL) {
		if(root->left==NULL&&root->right==NULL){   // lchild
			printf("%d %d\n",root->data,root->high);
			//printf("1 ");//return 1;
		}
		leafheight(root->left) ;
		leafheight(root->right);
	}//return ;


	//return leafcount(tree->left)+leafcount;
}

int main()
{
	int n,i,item=0;     //k[50]  ,,len
	//BTNodeptr  root=NULL;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &item);
		//len=0;
           root = insertBST(root, item,1);
	}
	leafheight(root);
	//rintf("%d\n", treeheight(root));
	//for(){
	//}

    return 0;

}

  /*else{                     //??非递归?
		q=root; high++;
    	while(1) {
        	if(item<q->data)  {
            	if(q->left==NULL){          /* 比较值的大小
                    q->left=p;           /* 小于向左，大于向右
                    break;
            	}else
                    q=q->left;
         	}else if (item>=q->data) {
            	if(q->right==NULL){
                    q->right=p;
                    break;
             	}else
                     q=q->right;
         	}//else {	}  //树中存在该元素
    	}
	}
	int treeheight(BTNodeptr  root){
	if (root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL){   // lchild
		//printf("%d ",root->data);
		return 1;
	}
	int lheight = treeheight(root->left);
	int rheight = treeheight(root->right);

	return 1+(lheight>rheight?lheight:rheight);
}*/



