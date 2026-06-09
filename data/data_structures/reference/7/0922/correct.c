#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		int item;
		struct lln *lch;
		struct lln *rch;
}tree;

void search(int, tree *);
tree *init(tree *);
int main()
{
	tree *head, *cnode, *p;
	head = (tree *)malloc(sizeof(tree));
	head = init(head);
	cnode = head;
	int i, n, num;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		cnode=head;
		if(!i)
			head->item=num;
		else{
			p = (tree *)malloc(sizeof(tree));
			p = init(p);
			while(1){
				if(num<cnode->item){
					if(cnode->lch==NULL)
						break;
					else
						cnode = cnode->lch;
				}
				else{
					if(cnode->rch==NULL)
						break;
					else
						cnode = cnode->rch;
				}
			}
			if(num<cnode->item)
				cnode->lch = p;
			else
				cnode->rch = p;
			p->item=num;
		}
	}
	search(0,head);
    return 0;
}

tree *init(tree *c){
	c->lch = NULL;
	c->rch = NULL;
	return c;
}

void search(int a, tree *p){
	a++;
	if(p->lch!=NULL)
		search(a,p->lch);
	if(p->rch!=NULL)
		search(a,p->rch);
	if(p->lch==NULL && p->rch==NULL)
		printf("%d %d\n",p->item,a);
}

