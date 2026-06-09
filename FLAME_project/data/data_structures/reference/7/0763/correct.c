#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct shu {
	int shuzi;
	struct shu *zuo,*you;
};
struct shu *jin(struct shu *root,int shuzi)
{
	struct shu *p;
	if(root==NULL)
	{
		p=(struct shu*)malloc(sizeof(struct shu));
		p->shuzi=shuzi;
		p->zuo=p->you=NULL;
		return p;
	}
	else if(root->shuzi>shuzi)
	{
		root->zuo=jin(root->zuo,shuzi);
		return root;
	}
	else {
		root->you=jin(root->you,shuzi);
		return root;
	}
}
void prints(struct shu *root,int h)
{
	if(root->zuo!=NULL)
	prints(root->zuo,h+1);
	if(root->you!=NULL)
	prints(root->you,h+1);
	if(root->zuo==NULL&&root->you==NULL)
	printf("%d %d\n",root->shuzi,h);
}
int main()
{
	struct shu *root=NULL;
	int n,i=0,a[5000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	root=jin(root,a[i]);
	prints(root,1);
}

