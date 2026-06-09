#include<stdio.h>
#include<string.h>
struct line{
	int x1,x2;
	int y1,y2;
	int flag;	
	int o;	
}line[110];
int n;
int ans[2];
int lengh=1,head=0;
int dfs(int x);
int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].flag=0;
		line[i].o=i;
	}

	ans[0]=0;ans[1]=0;
	//ÅÅĞò 
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(line[j].x1>line[j+1].x1)
			{
				int holdx1,holdx2,holdy1,holdy2,holdo; 
				holdx1=line[j].x1; line[j].x1=line[j+1].x1; line[j+1].x1=holdx1;
				holdx2=line[j].x2; line[j].x2=line[j+1].x2; line[j+1].x2=holdx2;
				holdy1=line[j].y1; line[j].y1=line[j+1].y1; line[j+1].y1=holdy1;
				holdy2=line[j].y2; line[j].y2=line[j+1].y2; line[j+1].y2=holdy2;
				holdo=line[j].o; line[j].o=line[j+1].o; line[j+1].o=holdo;
			}
		}
	}
/**	for(int i=0;i<n;i++)
	{printf("%d %d %d %d %d %d\n",line[i].o,line[i].x1,line[i].y1,line[i].x2,line[i].y2,line[i].flag);}*/

	for(int p=0;p<n;p++)
	{
		dfs(p);
		if(head==1)
		{
			ans[1]=p;
			head=0;
		}
	}
	
	printf("%d %d %d",ans[0],line[ans[1]].x1,line[ans[1]].y1);
	
	
	return 0;
} 

int dfs(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(i==n)
		{
			if(ans[0]<lengh)
			{
				ans[0]=lengh;
				head=1;	
			}
			
			lengh=1;
		} 	
		if(line[i].flag==0)
		{
			if(line[x].x2==line[i].x1 && line[x].y2==line[i].y1)
			{
				lengh++;
				line[i].flag=1;
				line[x].flag=1;
				x=i;
				dfs(x);
			}
		}
		
	}
	return 1;
}

