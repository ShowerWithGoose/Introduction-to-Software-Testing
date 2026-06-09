#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct A {
	int data,step;
	struct A *left, *right;
} tree, *sort;
int step=1;
sort f(sort p, int data);
void print(sort p);
int main(){
    sort root = NULL;
    int m,i,flag;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&flag);
        root=f(root,flag);
    }
    print(root);
}
sort f(sort p, int data){
    if (p == NULL) {
		p = (sort)malloc(sizeof(tree));
		p->data = data;
		p->step = step;
		step = 1;
		p->left = p->right = NULL;
	} else if (data < p->data) {
		step++;
		p->left = f(p->left, data);
	} else {
		step++;
		p->right = f(p->right, data);
	}
	return p;
}
void print(sort p){
    if (p!= NULL)
    {
        print(p->left);
        print(p->right);
        if (!(p->left) && !(p->right))
        {
            printf("%d %d\n", p->data, p->step);
        }
    }
}

