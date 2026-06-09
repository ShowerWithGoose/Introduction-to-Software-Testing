#include <stdio.h>
#include <string.h>

char box[21]={'\0'};
int N,mark[11]={0};  //0代表没用过 

void sort(int m,int n)
{
	int i;
	
	if(n==0)
	{
		puts(box);
		return;
	}
	
	for(i=1;i<=N;i++)
	{
		if(mark[i]==0)
		{
			mark[i]=1;
			box[m]=i+'0';
			box[m+1]=' ';
			sort(m+2,n-1);
			mark[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&N);
	sort(0,N);
	return 0;
}



