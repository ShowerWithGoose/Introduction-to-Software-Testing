//输入线段，全部排序，从头开始找，有合适的即合并并清除线段，统计条数，最后选出最大的条数。 
//以此重复，留下保持最大条数的信息 
#include<stdio.h>
#include<stdlib.h>

int line[101][5];

int  cmp(void const *x1,void const *x2);

int main()
{
	int num;
	int max=0,ans;
	
	//输入数据
	scanf("%d",&num);
	
	for(int i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&line[i][1],&line[i][2],&line[i][3],&line[i][4]);
		line[i][0]=1;		//一条线段 
	} 
	
	//排序 
	qsort(line,num,sizeof(line[0]),cmp);
	
	//统计线段
	 for(int i=0;i<num;i++)		//起始线段 
	 	for(int j=0;j<num;j++)	//查找线段 
	 	{
	 		if(j<=i)continue;
		 	if(line[i][3]==line[j][1]&&line[i][4]==line[j][2]&&line[j][1]!=-1&&line[i][1]!=-1)
		 	{
			 	line[i][0]++;	//统计 
			 	line[i][3]=line[j][3];	//化简 
			 	line[i][4]=line[j][4];
			 	line[j][0]=0,line[j][1]=-1,line[j][2]=-1,line[j][3]=-1,line[j][4]=-1;	//清除 
			}
		}
		
	//选择最大条 
	for(int i=0;i<num;i++)
	{
		if(max<line[i][0])
		{
			max=line[i][0];
			ans=i;
		}
	}
	
	printf("%d %d %d",max,line[ans][1],line[ans][2]);
	
	return 0;
}

int  cmp(void const *x1,void const *x2)
{
	int *x=(int *)x1;
	int *y=(int *)x2;
	
	if(x[1]<y[1])
	{
		return -1;
	}else if(x[1]>y[1])
	{
		return 1;
	}else
	{
		if(x[2]<y[2])
		{
			return -1;
		}else if(x[2]>y[2])
		{
			return 1;
		}
	}
	return 0;
}

