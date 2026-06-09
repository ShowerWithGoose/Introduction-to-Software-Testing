#include <stdio.h>
struct node
{
	int num;
	int height;
	int book;
}tree[100000];

void dfs(int x)//a为当前比较节点的序号 b为比较值 
{
	if(tree[x].book==0)return ;
	if(tree[x*2].num==0&&tree[x*2+1].num==0)
	{//判断为叶节点 
		printf("%d %d\n",tree[x].num,tree[x].height);
		return ;
	}
	
	dfs(2*x);
	dfs(2*x+1);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		int read;
		scanf("%d",&read);
		if(i==1)
		{
			tree[i].num=read;
			tree[i].height=1;
			tree[i].book=1;
		}
		else
		{
			int j=1;
			int h=1;
			while(tree[j].book!=0)
			{
			 if(read>=tree[j].num)
			 {
			 	j=2*j+1;
			 	h++;
			 }else
			 {
			 	j=2*j;
			 	h++;
			 }
			}
			tree[j].num=read;
			tree[j].height=h;
			tree[j].book=1;
		}
	}
	
	dfs(1);
	
	return 0;
}

