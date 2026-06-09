#include <stdio.h>
struct tree{
	int num;
	int level;
	struct tree *left,*right;
};

void travel(struct tree *root)
{
	struct tree *p1;
	p1=root;
	if(p1!=NULL)
	{
		if(p1->left!=NULL||p1->right!=NULL)
		{
			travel(p1->left);
			travel(p1->right);
		}
		if(p1->left==NULL&&p1->right==NULL)
		{
			printf("%d %d\n",p1->num,p1->level);
		}
	}
	return ;
}
int main()
{
	int n,i,num,level;
	scanf("%d",&n);
	struct tree *root,*p=NULL;
	for(i=0;i<n;i++)
	{
		level=1;
		scanf("%d",&num);
		if(p==NULL)
		{
			root=(struct tree *)malloc(sizeof(struct tree));
			root->num=num;
			root->left=NULL;
			root->right=NULL;
			root->level=level;
		//	printf("%d %d\n",root->num,root->level);
			p=root;
		}
		else
		{
			for(p=root;p!=NULL;)
			{
				level++;
				if(num<p->num)
				{
					if(p->left==NULL)
					{
						p->left=(struct tree *)malloc(sizeof(struct tree));
						p->left->num=num;
						p->left->left=NULL;
						p->left->right=NULL; 
						p->left->level=level;
					//	printf("%d %d\n",p->left->num,p->left->level);
						break;
					}
					p=p->left;
				} 
				else
				{
					if(p->right==NULL)
					{
						p->right=(struct tree *)malloc(sizeof(struct tree));
						p->right->num=num;
						p->right->left=NULL;
						p->right->right=NULL;
						p->right->level=level; 
					//	printf("%d %d\n",p->right->num,p->right->level); 
						break;
					}
					p=p->right;
				}
			}
			
		}
	}
	travel(root);
	return 0;
} 

