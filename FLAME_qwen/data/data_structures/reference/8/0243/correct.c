#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int arc[100][100];//邻接矩阵
int visited[100];//标记访问
int q[100];//队列
int n1,n2;//顶点数和边数

void DFStraverse(int p)
{
	int i;
	printf("%d ",p);//直接打印就可以啦 
	visited[p]=1;//之后设置为1 表示已经访问 
	for(i=0;i<n1;i++)//遍历所有顶点 
	{
		if(arc[p][i]==1 && !visited[i])//假如两者之间有边且没被访问 
		{
			DFStraverse(i);//访问 
		}
	}
}

void BFStraverse(int p)
{
	int i;
	int head,tail;
	int temp;
	head=-1;
	tail=0;
	q[0]=p;
	while(head<=tail)
	{
		temp=q[++head];
		if(visited[temp])
		{
			continue;
		}
		else
		{
			printf("%d ",temp);
			visited[temp]=1;
			for(i=0;i<n1;i++)
			{
				if(arc[temp][i]==1 && !visited[i])
				{
					q[++tail]=i;
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n1,&n2);
	int i,j,k;
	int d;//要删除的下标 
	for(k=0;k<n2;k++)
	{
		scanf("%d%d",&i,&j);
		arc[i][j]=1;
		arc[j][i]=1;
	}
	DFStraverse(0);//深度优先遍历 记住是从第0个元素开始的！所以这里传进去0 
	printf("\n");//记得打空格
	memset(visited,0,sizeof(visited));//每一次遍历之后都要初始化
	
	BFStraverse(0);//广度优先
	printf("\n");
	memset(visited,0,sizeof(visited)); 
	
	scanf("%d",&d);
	visited[d]=1;//删除的操作就是将其设置为1 
	
	DFStraverse(0);
	printf("\n");
	memset(visited,0,sizeof(visited));

	memset(q,0,sizeof(q));//队列也要初始化 记住 
	visited[d]=1;//同样经历了一次遍历后这里也要再次赋值为1 
	BFStraverse(0);
	
	return 0;
}



