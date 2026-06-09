#include <stdio.h>
#include <stdlib.h>
struct a{
	int data;
	int ceng;
	struct a *l,*r
};
int i=1; 
//struct a b; 
struct a *f(struct a *p, int item)
{
    if(p == NULL){
        p = (struct a*)malloc(sizeof(struct a));
        p->data = item;
        p->ceng=i;
        p->l = p->r= NULL;
    } 
    else if( item < p->data)
   {i++;
        p->l =f(p->l, item);}
    else if( item >= p->data)
      { i++;
	  p->r = f(p->r,item);}
      
    
 
    return p;
} 

void g(struct a *p) {
	if (p == NULL) return ;
	if (p -> l == NULL && p -> r == NULL) {
		printf("%d %d\n", p -> data, p -> ceng);
		return ;
	}
	g(p -> l), g(p -> r);
}

int main() {
	int q,q1,q2;
	struct a* root;
	root=NULL;
	scanf("%d",&q);
	for(q1=1;q1<=q;q1++)
	{i=1;
		scanf("%d",&q2);

	root=f(root,q2);
	}
	
	g(root);
	
	
	return 0;
}


