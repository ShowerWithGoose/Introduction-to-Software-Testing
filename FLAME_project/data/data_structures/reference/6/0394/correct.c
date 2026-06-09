#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
int main ()
{
	int top=-1,i,k=0;
	int zhan[1000];
	int shuzi[1000]={0};
	for(i=0;;i++)
	{
		scanf("%d",&shuzi[i]);
		if(shuzi[i]==-1)
		break;
	 } k=i;
	for(i=0;i<k;i++)                     //这些操作我感觉不能错啊  哪里错了啊 样例过了QWQ 
	{
		if(shuzi[i]==1)
		{
			if(top>=99)
			printf("error ");
			else
			{
				i++;
				zhan[++top]=shuzi[i];
			}
		}
		if(shuzi[i]==0)
		{
			if(top<=-1)
			printf("error ");
			else
			{
				printf("%d ",zhan[top]);
				zhan[top]=0;
				top--;
			}
		}
	}
	
	return 0;
}

