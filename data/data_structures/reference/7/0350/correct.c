#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int cnt=0;
struct node {
	int num;
	int s;
	struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
void  inorder( BTNodeptr t ) {

	if(t!=NULL) {
		inorder(t->left);
//		VISIT(t);
		if(t->left==NULL&&t->right==NULL) {
			printf("%d %d\n",t->num,t->s);
		}
		inorder(t->right);
	}
}
BTNodeptr insertBST(BTNodeptr p,int n) {
	if(p==NULL) {
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->num=n;
		p->left=NULL;
		p->right=NULL;
		cnt++;
		p->s=cnt;
	} else if(n<p->num) {
		cnt++;
		p->left=insertBST(p->left,n);

	} else if(n>=p->num) {
		cnt++;
		p->right=insertBST(p->right,n);

	} else {}
	return p;
}
int main() {
	int x,m,max=-1;
	scanf("%d",&x);
	BTNodeptr root=NULL;
	while(x--) {
		scanf("%d",&m);
		cnt=0;
		root=insertBST(root,m);
//		printf("%d\n",cnt);
//		if(cnt>=max) {
//			max=cnt;
//		}

	}
	inorder(root);
	return 0;
}


