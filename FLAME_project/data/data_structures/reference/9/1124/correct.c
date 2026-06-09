#include<stdio.h>
#include<stdlib.h>
typedef struct LINE
{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
}L;
int main()
{
    int i,j,k=0,in[105][4],n,flag;
    L line[105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%d%d%d%d",&in[i][0],&in[i][1],&in[i][2],&in[i][3]);
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(in[i][0]==in[j][2]&&in[i][1]==in[j][3])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)//i为一个起点; 
		{
			line[k].x1=in[i][0];
			line[k].y1=in[i][1];
			line[k].x2=in[i][2];
			line[k].y2=in[i][3];
			line[k].len=1;
			k++;
		}
	}
	for(i=0;i<k;i++)//本段有死循环； 
	{
		for(j=0;j<n;j++)
		{
			if(line[i].x2 ==in[j][0]&&line[i].y2 ==in[j][1])//将新的线段接到原有线段中，作为新的起点。 
			{
			    line[i].x2=in[j][2];
			    line[i].y2=in[j][3];
			    line[i].len++;
			    j=-1;
			}
		}
	}
	int max_len=0,max;//max为最长线段的序号； 
	for(i=0;i<k;i++)
	{
		if(line[i].len>max_len)
		{
			max=i;
			max_len=line[i].len;
		}
	}
	printf("%d %d %d",line[max].len,line[max].x1,line[max].y1);
	return 0;
}

