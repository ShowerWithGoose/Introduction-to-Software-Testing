#include <stdio.h>
#include <stdlib.h>
int N;
typedef struct tree *pt;
struct tree{
	int i;
	pt left;
	pt right;
};
pt store;
pt init();
void input();
void output(int,pt);
int main()
{
	store=init();
	input();
	output(1,store);
}
pt init()
{
	pt ptrl;
	ptrl=(pt)malloc(sizeof(struct tree));
	ptrl->i=-10086;
	ptrl->left=NULL;
	ptrl->right=NULL;
	return ptrl;
}
void input()
{
	scanf("%d",&N);
	int tmp;
	pt ptrl=store,ptrr;
	while (N){
		scanf("%d",&tmp);
		if (store->i==-10086){
			store->i=tmp;
		}
		else{
			ptrl=store;
			while(ptrl!=NULL){
				ptrr=ptrl;
				if (ptrl->i>tmp){
					ptrl=ptrl->left;
				}
				else{
					ptrl=ptrl->right;
				}
			}
			ptrl=init();
			ptrl->i=tmp;
			if (ptrr->i>tmp){
				ptrr->left=ptrl;
			}
			else{
				ptrr->right=ptrl;
			}
		}
		N--;
	}
}
void output (int ceng,pt xxy)
{
	if (xxy->left==NULL&&xxy->right==NULL){
		printf("%d %d\n",xxy->i,ceng);
		return;
	}
	if (xxy->left!=NULL)
		output(ceng+1,xxy->left);
	if (xxy->right!=NULL)
		output(ceng+1,xxy->right);
}

