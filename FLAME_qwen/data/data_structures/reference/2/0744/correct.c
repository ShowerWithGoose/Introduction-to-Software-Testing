#include<stdio.h>
#include<string.h>
//解题思路：把运算符和数字给分开 优先运算乘和除  算完之后再向前进一位
	char s[1000],s2[1000],b[1000]={0};
	int a[1000]={0};//存放数字
	int cnt=0,bit=0,k=0;//伴随数字 


int my_hanshu(char* p1,char* p2)//把字符串转换为数字返回 
{
	int sum=0,i;
	for(i=0;i<=p2-p1;++i)
	sum=sum*10+(*(p1+i)-'0');
	return sum; 
}

void my_fun(int i)
{
		int a1=i,a2=i+1;
			for(;a2<strlen(b)+1;++a2)a[a2]=a[a2+1];
			 a[a2]=0;
			for(;a1<strlen(b)-1;++a1)b[a1]=b[a1+1];//往前移动 
			 b[a1]=0;
			
}
int main()
{

	gets(s);
	int j1;
	for(j1=0;j1<strlen(s);++j1)
	if(s[j1]!=' ')s2[k]=s[j1],k++;
	s2[k]=0;

	int j;
	for(j=0;j<strlen(s2)-1;++j)//开始遍历 
		if(s2[j]<='9'&&s2[j]>='0')
		{
			int n=j; 
			for(;n<strlen(s2);++n)
			if(s2[n]>'9'||s2[n]<'0')break;
			a[cnt]=my_hanshu(s2+j,s2+n-1); 
			cnt++;
			j=n-1;
		 }else {
		 	b[bit]=s2[j];
		 	bit++;
		 }
	//分离完毕

	//开始计算 
	int i=0;
	for(;i<strlen(b);++i)//遍历计算符号 
	{
		if(b[i]=='*')
		{
			a[i]=a[i]*a[i+1];
			my_fun(i);
			 i--;
			 
		 }
		  else if(b[i]=='/')
		 {
		 	a[i]=a[i]/a[i+1];
			my_fun(i);
			 i--;
	}
}
	int k1=0;
	for(;k1<strlen(b);++k1)
	{    
		if(b[k1]=='+')
		{
			a[k1]=a[k1]+a[k1+1];
			my_fun(k1);
			 k1--;
		}
		else if(b[k1]=='-')
		{
			a[k1]=a[k1]-a[k1+1];
			my_fun(k1);
			 k1--;
		}
	}
    printf("%d",a[0]);
 }



