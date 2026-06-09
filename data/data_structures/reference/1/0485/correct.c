#include<stdio.h>

void tree(int deep);

int input[20];
int output[20];
int hash[20];

int len;		//总长度 
int top=0;		//栈位标记 

int main()
{
	//输入长度 

	scanf("%d",&len);
	
	//生成数列
	 for(int i=0;i<len;i++)
	 {
	 	input[i]=i+1;
	 }
	 
	 //测试输入，正确 
//	  for(int i=0;i<len;i++)
//	 	 {
//	 	 	printf("%d\n",input[i]);
//	 	 }
	 
	 //提取数
	 tree(0);		//第0层开始取 
	 
	 return 0;
}

void tree(int deep)
{
	//是否超载底层(底层亦可提取))
	if(deep>len-1)	//是
	{
		//输出结果 
		for(int i=0;i<len;i++)	
		{
			printf("%d ",output[i]);
		}
		printf("\n");
		return ;
	} 
	else		//否 
	{
		//从生成数组中提取一个数(从小数开始)并深入下层提取
		for(int i=0;i<len;i++) 
		{
			if(!hash[i])		//该位未被提取，可用 
			{
				hash[i]=1;		//此位已用（标记） 
				output[top++]=input[i];		//此栈位存入并推深栈位
				tree(deep+1);		//深入下一位
				//下层全部提取完后回到本层重新提取另外数字(原提取标记恢复原状) 
				hash[i]=0;
				top--; 
			}
		}
	}
}



