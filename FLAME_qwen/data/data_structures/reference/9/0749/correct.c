#include<stdio.h>
#include<string.h>
int cnt;
struct node
{
	int x1,x2,y1,y2;
	int len;
}s[105];
int main()
{
	int n,a1,b1,a2,b2,k=0;
	int maxn,maxx,maxy;
	struct node tmp;
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		k=0;
		if(cnt==0)
		{
			s[0].x1=a1;
			s[0].x2=a2;
			s[0].y1=b1;
			s[0].y2=b2;
			s[0].len=1;
			cnt++;
			continue;
		}
		for(int i=0;i<cnt;i++)
		{
			//rintf("i=%d s£º%d %d %d %d\nx£º%d %d %d %d\n",i,s[i].x1,s[i].y1,s[i].x2,s[i].y2,a1,b1,a2,b2);
			if(a1==s[i].x2 && b1==s[i].y2)
			{
				s[i].len++;
				s[i].x2=a2;
				s[i].y2=b2;
				k=1; 
				break;
			}
			if(a2==s[i].x1 && b2==s[i].y1)
			{
				s[i].len++;
				s[i].x1=a1;
				s[i].y1=b1;
				k=1;
				break;
			}
		}
		if(k==0)
		{
			s[cnt].x1=a1;
			s[cnt].y1=b1;
			s[cnt].x2=a2;
			s[cnt].y2=b2;
			s[cnt].len=1;
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++)
	for(int j=0;j<cnt-1-i;j++)
	{
		if(s[j].x1>s[j+1].x1)
		{
			tmp=s[j];
			s[j]=s[j+1];
			s[j+1]=tmp;
		}
	}
	for(int i=0;i<cnt;i++)
	for(int j=i+1;j<cnt;j++)
	{
		if(s[i].len==0||s[j].len==0) continue;
		if(s[i].x2==s[j].x1&&s[i].y2==s[j].y1) 
		{
			s[i].len+=s[j].len;
			s[i].x2=s[j].x2;
			s[i].y2=s[j].y2;
			s[j].len=0;
		}
	}
	maxn=0;

	for(int i=0;i<cnt;i++)
	{
		//printf("    %d %d %d %d    %d\n",s[i].x1,s[i].y1,s[i].x2,s[i].y2,s[i].len); 
	
		if(s[i].len>maxn)
		{
			maxn=s[i].len;
			maxx=s[i].x1;
			maxy=s[i].y1;
		}
	}
	printf("%d %d %d",maxn,maxx,maxy);
	return 0;
}

