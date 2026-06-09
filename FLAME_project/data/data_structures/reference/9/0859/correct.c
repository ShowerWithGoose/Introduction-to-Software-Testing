#include<stdio.h>
struct line{
	int x1,y1,x2,y2;
}lines[105];
int cri(int,int);
int main()
{
	int n;
	scanf("%d",&n);
	int maxlx1,maxly1,maxlx2,maxly2;
	int i=0;
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
	}
	int count=1,mcount=1;
	int mx,my,mX,mY,q;
	for(i=0;i<n;i++)
	{
		if(cri(i,n)!=-1)
		mx=lines[i].x1,my=lines[i].y1,q=i;
		while(cri(i,n)!=-1)
		{
			i=cri(i,n);
			count++;
		}
		if(mcount<count)
		{
		mcount=count;
		mX=mx,mY=my;
		}
		if(count>1)
		i=q,count=1;
	}
	printf("%d %d %d",mcount,mX,mY);
	return 0;
}
int cri(int i,int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1&&j!=i)
		return j;
	}
	return -1;
}

