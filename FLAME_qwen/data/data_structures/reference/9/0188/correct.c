#include<stdio.h>
struct
{
	int qian,hou;
	int zx,zy,yx,yy;
} line[105],qi;
int num_line=0;
int main()
{
	// shuru
	int n=0;
	scanf("%d",&n);
	int i=1;
	for(;i<=n;i++)
	{
		scanf("%d%d%d%d",&line[i].zx,&line[i].zy,&line[i].yx,&line[i].yy);
		line[i].qian=0;
		line[i].hou=0;
	}
	
	//lianjie
	i=1;
	for(;i<=n;i++)
	{
		int j=1;
		for(;j<=n;j++)
		{
			if(i==j) continue;
			if(line[i].zx==line[j].yx&&line[i].zy==line[j].yy)
			{
				line[i].qian=j;
				line[j].hou=i;
			}
			if(line[i].yx==line[j].zx&&line[i].yy==line[j].zy)
			{
				line[i].hou=j;
				line[j].qian=i;
			}
		}
	}
	
	//bijiao
	i=1;
	for(;i<=n;i++)
	{
		int num=1,xu=i;
		while(1)
		{
			if(line[xu].hou==0) break;
			else
			{
				xu=line[xu].hou;
				num++;
			}
		}
		if(num>num_line)
		{
			qi.zx=line[i].zx,qi.zy=line[i].zy;
			num_line=num;
		}
	}
	
	//shuchu
	printf("%d %d %d",num_line,qi.zx,qi.zy);
	
	return 0;
}

