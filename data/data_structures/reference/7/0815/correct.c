#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>  
int high;
struct num{
	int h;
	int data;
	struct num *left,*right;
};
struct num *insert(struct num *p,int item){
	high++; 
	if(p==NULL){
//可以单独写个函数，但是主函数中去掉 b=,直接insert就行 
		p=(struct num *)malloc(sizeof(struct num));
		p->left=p->right=NULL;
		p->data=item;
		p->h=high;
	}
    else if(item  <  p->data)
        p->left=insert(p->left,item);
    else if(item  >=  p->data)
        p->right=insert(p->right,item);
	return p;
} 
void print(struct num *a){//下面三个顺序可以换 
    if(a->left!=NULL)
        print(a->left);
    if(a->right!=NULL)
        print(a->right); 
    if(a->left==NULL&&a->right==NULL)
	    printf("%d %d\n",a->data,a->h);   	
}
int main(){
	int i,n,item;
	scanf("%d",&n);
	struct num *b=NULL;	
	for(i=0;i<n;i++){
		scanf("%d",&item);
		high=0;
		b=insert(b,item);
//b=必须写 
	}
	print(b);
	return 0;
} 

