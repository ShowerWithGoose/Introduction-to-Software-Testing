#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct tree{
	int num;
	int high;
	struct tree *left,*right;
};
typedef struct tree BTNode;
typedef struct tree *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,int m,int h){
	h++;
	if(p==NULL){
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->num=m;
        p->left=p->right=NULL;
        p->high=h;
    } 
    else if(m<p->num)
        p->left=insertBST(p->left,m,h);
    else if(m>=p->num)
       p->right=insertBST(p->right,m,h);
    return p;
}
void print(BTNodeptr p){
	if(p){
		if(!p->left&&!p->right)printf("%d %d\n",p->num,p->high);
		print(p->left);
		print(p->right);
	}
}
int main()
{
	int n,i,m,h;
	BTNodeptr root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		h=0;
		root=insertBST(root,m,h);
	}
	print(root);
 	return 0;
}


