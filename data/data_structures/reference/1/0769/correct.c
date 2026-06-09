#include<stdio.h>
int usednum[13];
void A(int usednum[],int position,int num)
{
	int flag=0;
	for(int i=1;i<=num;i++)
	{
		flag=0;
		for(int j=1;j<position;j++)
		{
			if((i==usednum[j]))
			{
			flag++;
			break;
			}
		}
		if((flag==0)&&(position!=num))
		{
		usednum[position]=i;
		A(usednum,position+1,num);
		}
		else if((flag==0)&&(position==num))
		{
		usednum[position]=i;
		for(int k=1;k<=position;k++)
			printf("%d ",usednum[k]);
		puts("");
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	A(usednum,1,n);
	return 0;
}
