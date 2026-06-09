#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
int xl[100];
int yl[100];
int xh[100];
int yh[100];
int index[100];
int link[100];
int len[100];

int main()
{
	int n,i,j;
	scanf("%d",&n);
	//printf("%d\n",n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&xl[i],&yl[i],&xh[i],&yh[i]);
		index[i]=i;
	}//存储每条线段信息
	
	
		/*for(i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",xl[i],yl[i],xh[i],yh[i]);
	}*/
	
	int tmp;
	for(i=1;i<=n-1;i++)
	{
		for(j=n;j>=i+1;j--)
		{
			if(xl[index[j]]<xl[index[j-1]])
			{
				tmp=index[j];
				index[j]=index[j-1];
				index[j-1]=tmp;
			}
		}
	}
	//按照x的大小进行升序排序
	/*for(i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",xl[index[i]],yl[index[i]],xh[index[i]],yh[index[i]]);
	}*/
	
	
	memset(link,0,sizeof(link));
	memset(len,0,sizeof(len));
	int k=0;int rem=0;
	for(i=1;i<=n;i++)
	{
		if(link[index[i]]!=0)
		k=link[index[i]];
		else if(link[index[i]]==0)
		{
			rem++;
			k=rem;
			link[index[i]]=k;
			len[k]=1;
			//printf("%d %d %d\n",k,xl[index[i]],yl[index[i]]);
		}
		for(j=i+1;j<=n;j++)
		{
			if(xh[index[i]]==xl[index[j]]&&yh[index[i]]==yl[index[j]])
			{
				link[index[j]]=k;
				len[k]++;
				break;
			}
		}
	}
	//查找：当未查找的数X1小于等于该等待被链接的线段x2时一直查找 
	       //如果有连接则赋予一个统一的编号，没有连接，k+1 
		   //记录该最终长度到len[k]中
	int max=-1;int mark=0;
	for(i=1;i<=rem;i++)
	{
		//printf("\n%d %d\n",i,len[i]);
		if(len[i]>max)
		{
		max=len[i];
		mark=i;
		}
	}
    printf("%d",max);
	//输出过程先找长度的最大值
	for(i=1;i<=n;i++)
	{
		//printf("%d\n",link[index[i]]);
		if(link[index[i]]==mark)
		{
		printf(" %d %d",xl[index[i]],yl[index[i]]);
		break;
			
		}
	}
	//再整个线性表中循环 查找link为k的线段 此时是按照原顺序 输出即可 
    return 0;
}


