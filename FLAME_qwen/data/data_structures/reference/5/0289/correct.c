#include<stdio.h>
#include<stdio.h>

int GetNum(char* input, int* co, int* index)//input为输入字符串，co为系数数组，index为指数数组，返回的值为一共输入了多少组系数和指数 
{
	int tool = 0, count = 0;//tool == 0 时，对系数进行加法操作，反之对指数进行操作 
	while (*input != '\0')
	{
		if (*input >= '0' && *input <= '9')
		{
			if (tool == 0)
			{
				*co = *co * 10 + (*input - 48);
			}
			else
			{
				*index = *index * 10 + (*input - 48);
			}
		}
		else
		{
			if (tool == 0)
			{
				tool = 1;
				co++;
				count++;//计数 
			}
			else
			{
				tool = 0;
				index++;
			}
		}
		input++;
	}
	return count;//返回的值：一共输入了多少组数 
}
int main()
{
	char input1[200];
	int co1[100]={0};
	int index1[100]={0};
	gets(input1);//读取多项式1
	int num1 = GetNum(input1, co1, index1);//num1为多项式1的系数组数
	char input2[200];
	int co2[100]={0};
	int index2[100]={0};
	gets(input2);//读取多项式2
	int num2 = GetNum(input2, co2, index2);//num2为多项式2的系数组数
	
	int ansCo[200]={0};//答案的系数
	int ansIndex[200]={0};//答案的指数
	
	int k=0;
	for(int i=0;i<num1;i++)//遍历多项式1
	{
		for(int j=0;j<num2;j++)//遍历多项式2
		{
			ansCo[k]=co1[i]*co2[j];
			ansIndex[k]=index1[i]+index2[j];
			k++;
		}
	}//逐项相乘，共得到k+1对数据（未排序版）
	
	//ansIndex中元素从高到低排序，记得连系数一起换
	for(int i=0;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			if(ansIndex[i]<ansIndex[j])//如果前面小于后面,就换
			{
				int tempIn=ansIndex[i];
				ansIndex[i]=ansIndex[j];
				ansIndex[j]=tempIn;//交换指数
				int tempCo=ansCo[i];
				ansCo[i]=ansCo[j];
				ansCo[j]=tempCo;//交换系数
			}
			//如果前面大于等于后面，无事发生
		}
	}
	
	
	//合并系数相同的项
	for(int i=0;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			//如果两项指数相同，合并系数，让其中一个为0（等下会删除）
			if(ansIndex[j]==ansIndex[i])
			{
				ansCo[i]+=ansCo[j];
				ansCo[j]=0;
			}
			//系数不同，继续遍历，无事发生
		}
	}
	
	//删除系数为零的项
		//for(int i=0;i<=k;i++)
		//{
		//	if(ansCo[i]==0)//如果系数为零，删掉这一对系数和指数
		//	{
				//后面的元素集体往前移动，k--
		//		for(int j=i+1;j<=k;j--)
		//		{
		//			ansCo[j-1]=ansCo[j];
		//		}
		//		k--;
		//	}
		//}
		
	for(int i=0;i<=k;i++)
	{
		if(ansCo[i]!=0)
		printf("%d %d ",ansCo[i],ansIndex[i]);
	
	}
	return 0;
}

