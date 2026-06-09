#include<stdio.h>
#include<string.h>
struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
}line[110];

int cnt[110];

int search(int n)
{

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) 
		{
			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)//后接 
			{
			 	cnt[i]+=cnt[j];
			 	cnt[j]=cnt[i];
			 	line[i].x2=line[j].x2;
			 	line[i].y2=line[j].y2;
			 	line[j].x1=line[i].x1;
			 	line[j].y1=line[i].y1;
				
				search(n);
			} 
		}
	}
};



int main()
{
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d\n",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		cnt[i]=1;
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=i+1;j<n;j++)
//		{
//			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)
//			//找到相接的
//			 {
//			 	cnt[i]++;
//			 	//sx[i]=line[i].x2<=line[j].x1?line[i].x2:line[j].x1;
//			 	//sy[i]=line[i].x2<=line[j].x1?line[i].y2:line[j].y1;
//			 	line[i].x2=line[j].x2;
//			 	line[i].y2=line[j].y2;
//				for(int k=j;k<n;k++)
//			 	{
//			 		line[k]=line[k+1];
//				}
//				j--;
//				n--;
//			 } 
//			 else if(line[i].x1==line[j].x2&&line[i].y1==line[j].y2)
//			 {
//			 	cnt[i]++;
//			 	//sx[i]=line[i].x1<=line[j].x2?line[i].x1:line[j].x2;
//			 	//sy[i]=line[i].x1<=line[j].x2?line[i].y1:line[j].y2;
//			 	line[i].x1=line[j].x1;
//			 	line[i].y1=line[j].y1;
//			 	for(int k=j;k<n;k++)
//			 	{
//			 		line[k]=line[k+1];
//				}
//				j--;
//				n--;
//				 
//			 }
//		}
//	}

	search(n);
//	for(int i=0;i<n;i++)
//	{
//		printf("%d %d %d\n",cnt[i],line[i].x1,line[i].y1);
//	}
	int max=0,k;
	for(int i=0;i<n;i++)
	{
		if(cnt[i]>=max)
		{
			max=cnt[i];
			k=i;
		}
			
	}
	printf("%d %d %d",max,line[k].x1,line[k].y1);
	return 0;
 } 

