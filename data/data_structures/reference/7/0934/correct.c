#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
	int id;
	struct node* l, * r;
	int h;
};
typedef struct node* Nodeptr;
typedef struct node Node;
Nodeptr root = NULL;
Nodeptr insert(int id) {
	Nodeptr p,q;
	p=(Nodeptr)malloc(sizeof(Node));
	p->id=id;
	p->l=NULL;
	p->r=NULL;
	if(root==NULL){
		root=p;
		root->h=1;
	}
	else{
		q=root;
		while(1){
			if(id<q->id){
				if(q->l==NULL){
					q->l=p;
					p->h=q->h+1;
					break;
				}
				else q=q->l;
			}
			else if(id>=q->id){
				if(q->r==NULL){
					q->r=p;
					p->h=q->h+1;
			//		printf("%d %d\n", p->data, p->h);
					break;
				}
				else q=q->r;
			}
		}
	}
}
void search(Nodeptr p) {
	if (p == NULL)return;
	search(p->l);
	if (p->r == NULL && p->l == NULL) {
		printf("%d %d\n", p->id, p->h);
		//return;
	}
//	search(p->l);
	search(p->r);
}
int main() {
	int num, id;
	//Nodeptr ps=NULL;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &id);
		insert(id);
	}
	search(root);
	return 0;
}


