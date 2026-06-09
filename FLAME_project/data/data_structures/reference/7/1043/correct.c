#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
struct node {
    int data;
    int high;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, int item,int h)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->high=h;
        p->left = p->right = NULL;
    } 
    else if( item < p->data)
    {
    	h++;
		p->left = insertBST(p->left, item,h);
	}
        
    else if( item >= p->data)
    {
    	h++;
		p->right = insertBST(p->right,item,h);
	}  
    return p;
}
void  inorder(BTNodeptr t)
{
      if(t!=NULL){
             inorder(t->left);
             inorder(t->right);
             if(t->left==NULL&&t->right==NULL)
             {
			 	printf("%d %d\n",t->data,t->high);
			 }
       }
}
int main()
{
	int i, item;
	BTNodeptr  root=NULL;
	int n,h;
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{ 
		h=1;
		scanf("%d", &item);
	    root = insertBST(root, item,h);
	}
	inorder(root);
    return 0;
}
/*13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/

