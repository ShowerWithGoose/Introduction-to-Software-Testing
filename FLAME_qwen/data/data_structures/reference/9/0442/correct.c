#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct nnn{
	int x,y;
}node;
typedef struct eee{
	node begin;
	node end;
}edge;
edge data[110];
int anstime = 0;
node ansb;
int n;
void dfs(node begin,int num,edge via,int time)
{
	int flag = 0;
	for(int j=1 ; j<=n; j++)
	{
		if(j == num) continue;
		if(data[j].begin.x == via.end.x && data[j].begin.y == via.end.y)
		{
			flag = 1;
			dfs(begin,j,data[j],time+1);
		}
	}
	if(!flag)
	{
		if(time>anstime)
		{
			anstime = time;
			ansb= begin;
		}
		
	}
}

int main ()
{
//	int n;
	scanf("%d",&n);
	for(int i=1; i<=n ;i++)
	{
		char ch = getchar();
	//	ch = getchar();
		scanf("%d%d%d%d",&data[i].begin.x,&data[i].begin.y,&data[i].end.x,&data[i].end.y);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(data[i].begin,i,data[i],1);
	}
	printf("%d %d %d",anstime,ansb.x,ansb.y);
	return 0;
}


