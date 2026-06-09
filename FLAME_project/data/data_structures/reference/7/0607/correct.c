#include<stdio.h>
#include<string.h>
#include<math.h>
#define max_node 100000005
long long tree[max_node];
int n;

void insert(long long num,int father)
{
	if(tree[father]>num)
	{
		if(tree[father*2]==-1)
		{
			tree[father*2]=num;
			return;
		}
		else if(tree[father*2]!=-1)
		{
			insert(num,father*2);
			return;
		}
	}
	else if(tree[father]<=num)
	{
		if(tree[father*2+1]==-1)
		{
			tree[father*2+1]=num;
			return;
		}
		else if(tree[father*2+1]!=-1)
		{
			insert(num,father*2+1);
			return;
		}
	}
}

void print(int id)
{
	if((tree[id*2]==-1)&&(tree[id*2+1]==-1))
	{
		printf("%lld %d\n",tree[id],(int)(log2(id))+1);
		return;
	}
	if(tree[id*2]!=-1) print(id*2);
	if(tree[id*2+1]!=-1) print(id*2+1);
}

int main()
{
	memset(tree,-1,sizeof(tree));
	scanf("%d",&n);
	long long i,tmp;
	scanf("%lld",&tmp);
	tree[1]=tmp;
	for(i=1; i<n; i++)
	{
		scanf("%lld",&tmp);
		insert(tmp,1);
	}
	print(1);
	return 0;
}


