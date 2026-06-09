#include<stdio.h>
#include<string.h>
#define MAX 1005

int de=0;
int cnt=0; 

struct sb
{
	int son[2];
	int num;
}tree[MAX];

void array(int *m,int k)
{
	if(*m==0)
	{
		*m=++cnt;
		tree[*m].num=k;
		return;
	}
	if(tree[*m].num<=k)
		array(&tree[*m].son[1],k);
	else 
		array(&tree[*m].son[0],k); 
}
void print(int m,int deepth)
{
	if(m==0) return;
	else if(tree[m].son[0]==0 && tree[m].son[1]==0)
		printf("%d %d\n",tree[m].num,deepth);
	print(tree[m].son[0],deepth+1);
	print(tree[m].son[1],deepth+1);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int tem;
		scanf("%d",&tem);
		array(&de,tem);
	}
	print(de,1);
	return 0;
}



