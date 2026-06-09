#include<stdio.h>
#include<string.h>
int x1[102],y1[102],x2[102],y2[102];
void bubbleSort( int n)//输入的为某数组和项数n 
{
int i, j, hold, flag;
for (i = 1; i <= n-1; i++)
{
flag = 0;
for (j = 1; j <= n-1-i; j++)
{
if (x1[j] > x1[j + 1])
{
hold = x1[j];
x1[j] = x1[j + 1];
x1[j + 1] = hold;
hold = x2[j];
x2[j] = x2[j + 1];
x2[j + 1] = hold;
hold = y1[j];
y1[j] = y1[j + 1];
y1[j + 1] = hold;
hold = y2[j];
y2[j] = y2[j + 1];
y2[j + 1] = hold;
flag = 1;
}
}
if (0 == flag)
break;
}
}

int main()
{   int k;
	int n;
	
	int sum1[102]={0};
	memset(sum1,0,sizeof(sum1)); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);

	for(int i=1;i<=n;i++)//检索以每个点为起点的连续线段的个数 
	{
	k=i;//k表达上一线段 
		for(int j=1;j<=n;j++)//j为待检索的线段 
		{
			if(x2[k]==x1[j]&&y2[k]==y1[j])//判断是否连接下一个线段 
			{
				k=j;
				sum1[i]++;//存储连续线段个数 
				j=0;
				
			}
		}
	}
	
	int max1=1; 
  for(int i=1;i<=n;i++)
  {
	if(sum1[i]>=sum1[max1])//求出连续线段最长的起点的位置 
 	max1=i;
  }

	printf("%d %d %d",sum1[max1]+1,x1[max1],y1[max1]);
 
	
	return 0;
    }
	
  


