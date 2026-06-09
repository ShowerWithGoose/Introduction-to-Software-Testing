#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//法一 邻接矩阵法
int t,r,rr,k;
int visit[500]={0};
int tu[500][500]={0}; 
int flag[500]={0};
int num=0,e;
void b(int m)
{
      int in=0,out=0;
	  while(1)
	{
	  if(in>out)break; 
		  int y=flag[in];in++;//打过的也要出队！！！ 
	  	if(visit[y]==1)continue;
	  printf("%d ",y),visit[y]=1;
	  	
	  	for(e=0;e<m;e++)
	  	{
	  		if(tu[y][e]==1&&visit[e]==0)
	  		{
	  			flag[++out]=e;
			}
		}
	  	
	} 
}
void d(int a,int m)
{
	//每到一个结点都要继续访问它所连的下一个节点，且该节点所有连接点都要最后被访问过一轮，所以循环该节点的下一个。 
 //递归搞深度 循环搞广度 
  printf("%d ",a);visit[a]=1;
  //int r;//必须定义成局部变量，如果定义成全局变量就死菜了因为会记录r的值，递归过来r的值还留着 
   
  for(r=0;r<m;r++)
  {
      if(visit[r]==0&&(tu[a][r]==1||tu[r][a]==1))
      {
      	d(r,m);
	  }
  } 
  r=0;//如果非要定义成全局，那就这样(保证递归回来的时候r是从0开始的，不要记录上一次r的循环结果)
}
int main()
{
	int m,n,op;
	int i,j,p,q;
	scanf("%d%d",&m,&n);
	//构建邻接矩阵 
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		//!!!!!!无向图，(p,q)和(q,p)都得得1 
		tu[p][q]=1;tu[q][p]=1; 
	}
	scanf("%d",&op);
	//删除前先遍历一遍
	d(0,m);//深度优先遍历
	printf("\n");
	for(i=0;i<m;i++)visit[i]=0;
	b(m);//广度优先遍历 
	printf("\n");
	for(i=0;i<m;i++)
	{
		//tu[i][op]=0;
		//tu[op][i]=0;
		visit[i]=0; //!!!再次使用遍历时，重置visit数组很重要
	} 
//	visit[500]={0}; (只有在最开始定义数组的时候可以这么玩儿)
	visit[op]=1;
	d(0,m);
	printf("\n");
	for(i=0;i<m;i++)visit[i]=0;
    visit[op]=1;
	b(m);
	printf("\n"); 
	return 0;
}

//关键词：无向图
//构建图、删除结点、DFS和BFS遍历 

