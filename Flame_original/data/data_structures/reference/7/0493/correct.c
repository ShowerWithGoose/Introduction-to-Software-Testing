#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000

typedef int datatype;
struct bst{
	datatype data;
	struct bst *llink,*rlink;
};

struct bst* build(struct bst* p,datatype item){
	if(p==NULL){
		p=(struct bst*)malloc(sizeof(struct bst));
		p->data=item;
		p->llink=NULL;
		p->rlink=NULL;
	}
	else if(item<p->data){
		p->llink=build(p->llink,item);
	}
	else if(item>=p->data){
		p->rlink=build(p->rlink,item);
	}	
	return p;
}
int h=1;
void search(struct bst*p){
	if(p!=NULL){
		if(p->llink==NULL&&p->rlink==NULL)
		printf("%d %d\n",p->data,h);
		h++;
		search(p->llink);
		search(p->rlink);
		h--;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	struct bst *root=NULL;
	for(int i=0;i<n;i++){
		int item;
		scanf("%d",&item);
		root=build(root,item);
	}
	search(root);
	return 0;
} 

