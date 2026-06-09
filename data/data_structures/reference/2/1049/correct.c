#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[300];
	char str[50];//存运算符 
	int num[200]={0};//存每个数字
	int sum[50]={0};//存每一组乘除式子的和 
	int i=0,j=0,k=0,t=0;
	int count=0;
	int flag=1; 
	gets(s);
	for(i=0,j=0;s[i]!='\0';i++,j++)//去掉算式中的空格 
	{
		for(;s[i]==' ';i++);
		s[j]=s[i];
	}
	s[j]='\0';
	for(i=0,j=0,k=0;s[i]!='\0';i++)//把数字存储在整数型数字里，运算符存储在字符数组里 
	{
		while(s[i]>='0'&&s[i]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
		{
			num[j]=(num[j]+(s[i]-'0'))*10;
			i++;
		}
		if(s[i]>='0'&&s[i]<='9') num[j++]+=s[i]-'0';
		else str[k++]=s[i];
	}
	s[i]='\0';
	//printf("%d\n%d\n%d\n",num[0],num[1],num[2]);//实验用printf    记得删除
	//printf("%c\n%c\n%c\n",str[0],str[1],str[2]);//实验用printf    记得删除  
	for(k=0,t=0;str[k]!='\0';k++)//读取运算符，进行运算 
	{
		flag=1;
		while(str[k]=='*'||str[k]=='/')//将乘除式子组合运算好 
		{
			if(flag) sum[t]=num[k];
			if(str[k]=='*') sum[t]*=num[k+1];
			else sum[t]/=num[k+1];
			k++;
			flag=0;
		}
		if(flag==0) t++;
	}
	//printf("%d\n%d\n%d\n",sum[0],sum[1],sum[2]);//实验用printf    记得删除 
	flag=1;
	for(k=0,t=0;str[k]!='\0';k++)//相加减 
	{
		if(flag)
		{
			if(str[k]=='*'||str[k]=='/')
			{
				count=sum[t++];
				while(str[k]=='*'||str[k]=='/') k++;
				flag=0;
			}
			else
			{
				count=num[k];
				flag=0;
			} 
		}
		if((str[k]=='+'||str[k]=='-')&&(str[k+1]=='*'||str[k+1]=='/'))
		{
			if(str[k]=='+') count+=sum[t++];
			else count-=sum[t++];
			while(str[++k]=='*'&&str[++k]=='/');
			k=k-1;
		}
		else if(str[k]=='+'||str[k]=='-')
		{
			if(str[k]=='+') count+=num[k+1];
			else count-=num[k+1];
		}
	}
	printf("%d\n",count);
	


return 0;
}
/*码完此题的感悟*/ 

