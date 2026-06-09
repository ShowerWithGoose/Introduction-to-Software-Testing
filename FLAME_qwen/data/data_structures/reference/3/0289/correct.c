#include<stdio.h>
#include<string.h>
int main() {
	char str[110];
	gets(str);
	char ans[110]={};
	int s_dot = 0; //小数点位置
	int len = strlen(str);
	int s_num = 0; //第一个非零数位置
	int flag_num = 0; //是否找到第一个非零数
	int index=0;//指数
	int num=0;
	int cnt=0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '.') {
			s_dot = i + 1;
			break;
		}
	}
	if (s_dot == 2) 
	{ //如果小数点前只有一位数字
		if (str[0] > '0' && str[0] <= '9') //如果小数点前的这个数字在1-9之间，直接输出该小数
		{
			printf("%se0", str);
			return 0;
		}
		else if(str[0]=='0')//如果第一位是0，需要继续往后找，找第一个非零数
		{
			for(int i=2;i<len;i++)
			{
				if(str[i]>='1'&&str[i]<='9'&&flag_num==0)
				{
					s_num=i+1;
					flag_num=1;
					num=str[i]-'0';//因为str[i]是字符，所以必须写个-'0'
					break;
				}
			}//找到第一个非零数
			if(s_num==len)//如果第一个非零数后面没有别的数字
			{
				index=s_dot-s_num;
				printf("%de%d",num,index);
				return 0;
			}
			for(int i=s_num;i<len;i++)//把第一个非零数后面的数字复制到ans里
			{
				ans[cnt+1]=str[i];
				cnt++;
			}
			ans[0]='.';
		index=s_dot-s_num;
		printf("%d%se%d",num,ans,index);
		return 0;
		}

	}//如果小数点前只有一位数字，讨论完毕。
	else//开始讨论小数点前不止有一个数（指数大于0）
	{
		index=s_dot-2;
		num=str[0]-'0';//科学计数法第一位数字
		for(int i=1;i<s_dot-1;i++)//把小数点之前的的复制到另一个字符串ans中
		{
			ans[i]=str[i];
		}
		for(int i=s_dot-1;i<len;i++)
		{
			ans[i]=str[i+1];
		}
		ans[0]='.';
		printf("%d%se%d",num,ans,index);
	}
	return 0;
}



