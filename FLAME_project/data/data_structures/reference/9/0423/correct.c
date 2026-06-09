#include<stdio.h>

typedef struct 
{
	int x;
	int y;
}DOT;

typedef struct 
{
	DOT first;
	DOT last;
	int flag;//用来判断此条线段是否连成线
}LINE;

int n;//线段的个数
int i,j;
int num[2]={1,1},max,signbuf;//存储个数,通过sign来交换存储位置
int firstdot[2],lastdot[2],firstdotbuf[2],lastdotbuf[2];//来存连续线段的首尾

int main()
{
	scanf("%d",&n);
	LINE line[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&line[i].first.x,&line[i].first.y);
		scanf("%d%d",&line[i].last.x,&line[i].last.y);
		line[i].flag=0;
	}
	
	for(i=0;i<n-1;i++)
	{
		static int max1,sign;
		max1=line[i].first.x;
		sign=i;
		
		for(j=i+1;j<n;j++)
		{
			if(max1>line[j].first.x)
			{
				max1=line[j].first.x;
				sign=j;
			}
		}
		
		LINE tmp;
		tmp=line[i];
		line[i]=line[sign];
		line[sign]=tmp;
	}
	
	/*输出调试
	for(i=0;i<n;i++)
	{
		printf("%d %d ",line[i].first.x,line[i].first.y);
		printf("%d %d\n",line[i].last.x,line[i].last.y);
	}
	*/
	
	for(i=0;i<n-1;i++)
	{
		if(line[i].flag) continue;
		
		static int a[2],b[2];
		a[0]=line[i].first.x; a[1]=line[i].first.y;
		b[0]=line[i].last.x;  b[1]=line[i].last.y;
		firstdotbuf[0]=a[0]; firstdotbuf[1]=a[1]; 
		//lastdotbuf[0]=b[0];  lastdotbuf[1]=b[1]; 
		
		for(j=i+1;j<n;j++)
		{
			if(line[j].flag) continue;
			
			static int c[2],d[2];
			c[0]=line[j].first.x; c[1]=line[j].first.y;
			d[0]=line[j].last.x;  d[1]=line[j].last.y;
			
			if((b[0]==c[0])&&(b[1]==c[1]))
			{
				//lastdotbuf[0]=d[0];  lastdotbuf[1]=d[1]; 
				num[signbuf]++;
				line[j].flag=1;
				b[0]=d[0]; b[1]=d[1];
			}
			if((a[0]==d[0])&&(a[1]==d[1]))
			{
				firstdotbuf[0]=c[0]; firstdotbuf[1]=c[1];
				a[0]=c[0]; a[1]=c[1];
				num[signbuf]++;
				line[j].flag=1;
			}
		}
		
		if(num[signbuf]>num[!signbuf])
		{
			firstdot[0]=firstdotbuf[0]; firstdot[1]=firstdotbuf[1];
			//lastdot[0]=lastdotbuf[0];   lastdot[1]=lastdotbuf[1];
			max=num[signbuf];
			signbuf=!signbuf;
		}
		
		num[signbuf]=1;//清零操作
	}
	
	printf("%d %d %d",max,firstdot[0],firstdot[1]);
	return 0;
}
