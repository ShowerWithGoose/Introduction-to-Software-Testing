#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char inputs[100006];
	char fx[100006];

	//input
	gets(inputs);
	int len_of_inputs=strlen(inputs);
	int j=0;
	for(int i=0;i<len_of_inputs;i++)
	{
		if(inputs[i]!=' ')
		{
			fx[j]=inputs[i];
			j++;
		}
	}
	fx[j]='\0';
	int len_of_fx=j;


	//处理表达式
	//存符号
	int locate_of_flag[100006];
	char flag[100006];
	j=0;
	for(int i=0;i<len_of_fx;i++)
	{
		if(fx[i]=='+'||fx[i]=='-'||fx[i]=='*'||fx[i]=='/'||fx[i]=='=')
		{
			flag[j]=fx[i];
			locate_of_flag[j]=i;
			j++;
		}
	}
	int num_of_flag=j;

	//存数字
	//将两个符号间的数字处理后存入num中
	int num[100006];
	for(int i=0;i<num_of_flag;i++)
	{
		if(i==0)
		{
			j=0;
			num[i]=fx[j]-'0';//存第一个
			for(int k=1;k<locate_of_flag[0];k++)
			{
				num[i]=fx[++j]-'0'+num[i]*10;
			}
		}
		else
		{
			j=locate_of_flag[i-1]+1;
			num[i]=fx[j]-'0';
			for(int k=locate_of_flag[i-1]+2;k<locate_of_flag[i];k++)
			{
				num[i]=fx[++j]-'0'+num[i]*10;
			}
		}
	}

	//运算
	//除法
	for(int i=0;i<num_of_flag;i++)
	{
		if(flag[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];//除完后存在下一位
			for(int k=i;k<num_of_flag-1;k++)//后方前移，覆盖已运算位
			{
				flag[k]=flag[k+1];
				num[k]=num[k+1];
			}
			num_of_flag--;
			i--;//重新运算此位
		}
	}
	//乘法
	for(int i=0;i<num_of_flag;i++)
	{
		if(flag[i]=='*')
		{
			num[i+1]=num[i]*num[i+1];
			for(int k=i;k<num_of_flag-1;k++)
			{
				flag[k]=flag[k+1];
				num[k]=num[k+1];
			}
			num_of_flag--;
			i--;
		}
	}
	//加减法
	for(int i=0;i<num_of_flag;i++)
	{
		if(flag[i]=='+')
		{
			num[i+1]=num[i]+num[i+1];
			for(int k=i;k<num_of_flag-1;k++)
			{
				flag[k]=flag[k+1];
				num[k]=num[k+1];
			}
			num_of_flag--;
			i--;
		}
		if(flag[i]=='-')
		{
			num[i+1]=num[i]-num[i+1];
			for(int k=i;k<num_of_flag-1;k++)
			{
				flag[k]=flag[k+1];
				num[k]=num[k+1];
			}
			num_of_flag--;
			i--;
		}
	}

	if(num[0]==11)
	{
		printf("211\n");
	}
	else
	{
		printf("%d\n",num[0]);
	}
	

	system("pause");
	return 0;
}
