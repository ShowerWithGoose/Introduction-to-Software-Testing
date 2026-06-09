#include<stdio.h>
#include<string.h>
int n;
int cnt;
void backtrack(int tracks[10],int nums[11])
{
	int i,j;
	if(cnt==n)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",tracks[i]);
		}
		putchar('\n');
		return ;
	}
	for(j=1;j<=n;j++)
	{
		if(nums[j]==1)continue;
		nums[j]=1;
		tracks[cnt++]=j;
		backtrack(tracks,nums);
		nums[j]=0;
		tracks[--cnt]=0; 
	}
}
int main()
{
	int track[10],nums[11]={0};
	scanf("%d",&n);
	backtrack(track,nums);	
	return 0;
} 



