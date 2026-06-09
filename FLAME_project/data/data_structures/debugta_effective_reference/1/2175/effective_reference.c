#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int a[]={1,2,3,4,5,6,7,8,9,10};
int *p[10];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b; 
}



void f(int x,int y)
{
	int i,j,t,*temp;
	
	
	
	for(j=x-1;j<=y-1;j++)//交换循环表皮 同一层中 x不变 且交换前位不变 并且交换前位和刷新前位一样 所以可令 j=x-1. 满足终止条件时自动 break 但仍需设立执行条件语句来进入循环 
	{
		
		
		
		//把刷新改为从x-1到y-1的qsort排序 
		//for(i=x-1;i<=y-1;i++)//刷新 从 p[x-1]刷新到 p[y-1],所以用<= 且因为同一层中x、y不变 所以令 i=x-1 截止到 y-1满足同一层中刷新不变 
		//{
		//	p[i]=&a[i];
		//}//刷新 for循环到此结束 
		
		qsort(&p[x-1],y-x+1,sizeof(p[x-1]),cmp);
		
		
		
		//交换执行语句 
		temp=p[x-1];
		p[x-1]=p[j];
		p[j]=temp;
		
		
		
		
		if(x==y)//递归最小层 刷新前后位相等 即 x=y 
		{
			//打印
			for(t=0;t<y;t++)
			{
				printf("%d ",*p[t]);
			} 
			printf("\n");
			
			
			
			
		//continue;//可直接跳过本轮 for交换循环接下来的语句 跳过下面的本次递归 
		break;//可直接打破本轮 for交换循环 跳到 f(x-1,y)(上一个递归层)中 相当于上一层 f(x+1,y)语句执行完毕 开始下一轮交换循环 
		
		
		
		
		} 
		
		
		
		f(x+1,y);
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	} 
	
	
	
	
}


int main()
{
	int i,N;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		p[i]=&a[i];
	}
	f(1,N); //从第i个开始,排N个数 
	return 0;
}

//#include<string.h>
//memset()
//strlen()
//strcmp()
//strcpy()
//strstr()

//<ctype.h>
//isalnum()
//isalpha()
//islower()
//isupper()
//tolower()
//toupper()


