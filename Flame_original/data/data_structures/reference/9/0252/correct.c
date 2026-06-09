#include<stdio.h>
#include<string.h>
struct Line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int number;
}line[100];
void sequence(struct Line *line,int n)
{
	struct Line temp;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(line[j].x1>line[j+1].x1)
			{
				temp=line[j+1];
				line[j+1]=line[j];
				line[j]=temp;
			}
		} 
	}
}
int check(struct Line *line,int n,int bg) 
{
	if(bg==n-1) return 1;
	int i,flag=0;
	for(i=bg+1;i<n;i++)
	{
		if(line[bg].x2==line[i].x1&&line[bg].y2==line[i].y1)
		{
			flag=1;
			break;
		}
	} 
	if(flag==1) return (1+check(line,n,i));
	else return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	sequence(line,n);
	int max=0,maxi=0;
	for(i=0;i<n;i++)
	{
		line[i].number=check(line,n,i);
		if(line[i].number>max)
		{
			maxi=i;
			max=line[i].number;
		}
	}
	printf("%d %d %d",max,line[maxi].x1,line[maxi].y1);
	return 0;
}


