//使用DFS和BFS对树进行遍历
#include<stdio.h>
struct node{
	int data;
	int left;
	int right;
};
struct node tree[1000];
void dfs(int p,int num)
{
	if(tree[p].left==0&&tree[p].right==0)
	{
		printf("%d %d\n",tree[p].data,num);
		return;
	}
	if(tree[p].left>0)
	{
		dfs(tree[p].left,num+1);
	}
	if(tree[p].right>0)
	{
		dfs(tree[p].right,num+1);
	}
	return;
}
int main()
{
	int i,j,k,m,n,p=0,data,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		if(cnt==0)
		{
			tree[cnt].data=data;
			cnt++;
			continue;
		}
		p=0;
		while(1)
		{
			if(data<tree[p].data&&tree[p].left>0)
			{
				p=tree[p].left;
				continue;
			}
			else if(data<tree[p].data&&tree[p].left==0)
			{
				tree[p].left=cnt;
				tree[cnt].data=data;
				cnt++;
				break;
			}
			else if(data>=tree[p].data&&tree[p].right>0)
			{
				p=tree[p].right;
				continue;
			}
			else if(data>=tree[p].data&&tree[p].right==0)
			{
				tree[p].right=cnt;
				tree[cnt].data=data;
				cnt++;
				break;
			}
		}
	}
	dfs(0,1);
	return 0;
}




