#include <stdio.h>
#include <stdlib.h>
int fa[105],num[105];//num[i]代表以i号线段为主线段的线段个数 
int x1[105],y1[105],x2[105],y2[105]; 
void init (int n);
int find(int x);
int main(int argc, char *argv[])
{
  int i,j,n,find1,find2,max=0;
  scanf("%d",&n);
  init(n);//初始化,每条线段刚开始的头线段是自身，且个数为1 
  for(i=1;i<=n;i++)
  {
  	scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
  }
  for(i=1;i<n;i++)
  {
  	for(j=i+1;j<=n;j++)
  	{
  		if(x1[i]==x2[j]&&y1[i]==y2[j])//i线段在j线段的后面 
  		{
  			find1=find(i);//找到i线段的主线段 
  			find2=find(j);//找到j线段的主线段 
  			fa[i]=find2;//把i合并到j所在的集合中 
  			num[find2]+=num[find1];
  			if(num[find2]>max)max=num[find2];
		  }
		  else if(x1[j]==x2[i]&&y1[j]==y2[i])//j在i的后面 
		  {
		  	find1=find(i);
  			find2=find(j);
  			fa[j]=find1;
  			num[find1]+=num[find2];
  			if(num[find1]>max)max=num[find1];
		  }
	  }
  }
  for(i=1;i<=n;i++)
  {
  	if(num[i]==max)
  	{
  		printf("%d %d %d",num[i],x1[i],y1[i]);
  		break;
	  }
  }
  return 0;
}
void init (int n)
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		num[i]=1;
	}
}
int find(int x)//用递归的方法实现对代表元素的查询 
{
    if(fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

