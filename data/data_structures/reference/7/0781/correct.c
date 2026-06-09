#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	int num;
	struct Node *left;
	struct Node *right;
};
typedef struct Node BTNode;
typedef struct Node *BTNodeptr;
BTNodeptr inserttree(BTNodeptr head,int x);
void order(BTNodeptr p);
int main(){
	int n,i,x;
	BTNodeptr head=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		head=inserttree(head,x);
	}
	order(head);
	return 0;
}
BTNodeptr inserttree(BTNodeptr head,int x){
	BTNodeptr p=(BTNodeptr)malloc(sizeof(BTNode));
	p->num=x;
	p->left=p->right=NULL;
	BTNodeptr q=head;
	if(head==NULL){
		head=p;
	}
	else{
		while(1){
			if(q->num>x){
				if(q->left!=NULL)  q=q->left;
				else {q->left=p;break;}
			}
			else{
				if(q->right!=NULL) q=q->right;
				else {q->right=p;break;}
			} 
		}
	}
	return head;
}
void order(BTNodeptr p){
	static int h=1;
	if(p!=NULL){
		if((p->left==NULL)&&(p->right==NULL)){
			printf("%d %d\n",p->num,h);
		}
		else{
			h++;
			order(p->left);
			order(p->right);
			h--;
		}
	}
}

