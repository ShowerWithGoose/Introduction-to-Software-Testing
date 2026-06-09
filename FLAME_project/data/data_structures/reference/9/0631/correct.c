#include<stdio.h> 
struct line
{
	int begin[2];
	int end[2];
}l[105];
int main()
{
	int n;
	int i,j;
	int count=0;
	int flag;
	int beginning[105][4];
	int link[2];
	int number[105];
	int max=0;
	int x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&l[i].begin[0],&l[i].begin[1],&l[i].end[0],&l[i].end[1]);
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(l[i].begin[0]==l[j].end[0]&&l[i].begin[1]==l[j].end[1])
			{
				break;
			}
			if(l[i].end[0]==l[j].begin[0]&&l[i].end[1]==l[j].begin[1])
			{
				flag=1;
			}
		}
		if(j==n&&flag==1)
		{
			beginning[count][0]=l[i].begin[0];
			beginning[count][1]=l[i].begin[1];
			beginning[count][2]=l[i].end[0];
			beginning[count][3]=l[i].end[1];
			count++;
		}
	}
	for(i=0;i<count;i++)
	{
		number[i]=1;
		link[0]=beginning[i][2];
		link[1]=beginning[i][3];
		for(j=0;j<n;j++)
		{
			if(link[0]==l[j].begin[0]&&link[1]==l[j].begin[1])
			{
				number[i]++;
				link[0]=l[j].end[0];
				link[1]=l[j].end[1];
				j=-1;
			}
		}
		if(number[i]>max)
		{
			max=number[i];
			x=beginning[i][0];
			y=beginning[i][1];
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

