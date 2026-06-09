#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode{
	int data;
	struct Lnode* left;
	struct Lnode* right;
}node,*list;
int lay=0;
void func(list m)
{
	lay++;
	if(m->right==NULL&&m->left==NULL&&m)
	{
		printf("%d %d\n",m->data,lay);
		return;
	}
	else if(m)
	{
		if(m->left){
		func(m->left);
		lay--;}
		if(m->right){
		func(m->right);		
		lay--;}
	}
}
int main()
{
int n,num,flag=0;
scanf("%d",&n);
list root=(list)malloc(sizeof(node));
scanf("%d",&num);
root->data=num;
root->left=NULL;
root->right=NULL;
n--;
while(n--){
	scanf("%d",&num);
	list p=(list)malloc(sizeof(node));
	p->data=num;
	p->left=NULL;
	p->right=NULL;
	list a=root;
	flag=0;
	while(!flag){
		if(num<a->data){
			if(a->left)
			a=a->left;
			else{
				flag=1;
				a->left=p;
			}
		}else{
				if(a->right)
			a=a->right;
			else{
				flag=1;
				a->right=p;
			}
		}
	}
}
func(root);
return 0;
}

