#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//快排 
#define eps 1e-8
#define pi 3.14
#define eof EOF
struct xianduan
{
	int x1;
	int y1;
	int x2;
	int y2;
};
int t_search_w(struct xianduan x);
int  w_search_t(struct xianduan x);

struct xianduan a[105];
int b[105]={0}; 
int n;int i;

int main()
{	
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);	
	}
	
	for(i=1;i<=n;i++)
	{
		if(t_search_w(a[i])==-1)//没找到，可以做第一个线段 
		{
			w_search_t(a[i]);
		}
	}
	int max=b[1];int h;
	for(i=1;i<=n;i++)//找最大的
	{	int n;
		if(b[i]>=max)
		{	h=i;
			n=max;
			max=b[i];
			b[i]=n;
		}
	}
	printf("%d %d %d",max+1,a[h].x1,a[h].y1);
	 
	
	
}

int t_search_w(struct xianduan x)
{	
	int i;
	for(i=1;i<=n;i++)
	{
		if((x.x1==a[i].x2)&&(x.y1==a[i].y2))
		return 1;}
	return -1;
}

int  w_search_t(struct xianduan x)//递推 
{	
	int flag=0,k;
	int j;
	for(j=1;j<=n;j++)
	{
		if((x.x2==a[j].x1)&&(x.y2==a[j].y1))//找到了， 
		{	
			flag=1;
			k=j;
		}
	}
	if(flag==1)
	{
	b[i]++;
	w_search_t(a[k]);}
	else
	return 0;

}



