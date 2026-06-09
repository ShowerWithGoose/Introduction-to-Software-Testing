#include <stdio.h>
int number[11]={0,1,2,3,4,5,6,7,8,9,10};
int n;
void put();
void swap(int x,int y);
void order(int num);
int main()
{
	scanf("%d",&n);
	order(1);
	return 0;
}
void put()
{
	int i;
	for(i=1;i<=n;i++)
	printf("%d ",number[i]);
	printf("\n");
	return;
}
void swap(int x,int y)
{
	int tem;
	tem = number[x];
	number[x] = number[y];
	number[y] = tem;
}
void order(int num)
{
	if(num == n)
	{
		put();
		return;
	}
	order(num+1);
	int i;
	for(i=0;num+i<n;i++)
	{
		swap(num+i+1,num);
		order(num+1);
	}
	for(i=n;i>num;i--)
	swap(i,num);
}



