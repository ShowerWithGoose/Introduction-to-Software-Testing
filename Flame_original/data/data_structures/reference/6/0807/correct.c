#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[101]={0};
int main()
{
	int n,cnt_1=0,cnt_0=0,i=0;
	while(~scanf("%d ",&n))
	{
		if(n==1)
		{
			if(i>99)
			{
			printf("error ");//栈满，不入
			continue;
			} 
			else{
			cnt_1++;//可以进栈，读入数据 
		    scanf("%d ",&a[i++]);
		    continue;
		    }
		}
		else if(n==0)
		{
			if(cnt_0>=cnt_1)
			{
			printf("error ");
			continue;
		    }
			else
			{   i--;
			    cnt_0++;
				printf("%d ",a[i]);
				
			}
		}
		else if(n==-1) 
	return 0;
	}
} 

