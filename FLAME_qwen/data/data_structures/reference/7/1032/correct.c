#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct s 
{
    int num;
    int height;
    struct s * left;
    struct s * right;
}*root;

struct s* creatTrie(int h,int a,struct s* root);
void printTrie(struct s*p);

int main()
{
    int n,i;
    int num;
    int h=1;
    root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        root=creatTrie(h,num,root);
    }
    
	printTrie(root);
    return 0;
}

struct s* creatTrie(int h,int a,struct s* root)
{
     
     if(root==NULL)
     {
         root=(struct s*)malloc(sizeof(struct s));
         root->num=a;
         root->left=NULL;
         root->right=NULL;
         root->height=h;
    }
     else
     {
         
		 if(a<root->num)
         root->left=creatTrie(h+1,a,root->left);
         else 
         root->right=creatTrie(h+1,a,root->right);
    }
    return root;
}

void printTrie(struct s*p)
{
    if(p==NULL)
    {
    	
    	return;
	}
	
    
    if(p->left==NULL&&p->right==NULL)
    printf("%d %d\n",p->num,p->height);
    else
    {
        printTrie(p->left);
        printTrie(p->right);
    }
}

