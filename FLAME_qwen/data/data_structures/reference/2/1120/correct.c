#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int num[100];
void delete(char [],char);
int is_sign(char );
void op(int*,int*,char);
int main()
{
	//规则：两符号之间夹着的是数字
	int sum=0;
	char s[100],sign[100]; 
	int i,j,k;
	gets(s);
	//删除空格
	delete(s,' ');
	//把字符转为数字,存到int数组当中 ;另建char数组，存放符号
	//若为负号，乘-1 
	char *p=s+1;
	num[0]=atoi(s);
	for(i=1,j=1,k=0;s[i]!='=';i++)
	{
		if(is_sign(s[i]))
		{
			if(s[i]=='-')
			{
			   sign[k++]=s[i];
			   num[j++]=(-1)*atoi(++p);
			   continue; 
			}
			sign[k++]=s[i];
			num[j++]=atoi(++p);
			continue;
		}
		p++;
	}
    sign[k]='=';sign[k+1]='\0';
    int len=strlen(sign);
	//先算乘除
	for(i=0;sign[i]!='\0';i++)
	{
	  if(sign[i]=='*'||'/')
	  op(num+i,num+i+1,sign[i]);
	}
	
	for(i=0;i<len+1;i++)
	sum+=num[i];
	
	printf("%d\n",sum);
	
	return 0;
}  
//四则运算 
void op(int *p1,int *p2,char c)
{
	if(c=='*')
    {
		*p2=(*p1)*(*p2);
		*p1=0;
	}
	if(c=='/') 
	{
		*p2=(*p1)/(*p2);
		*p1=0;
	}
}
//删除空白 
void delete(char s[],char c)
{
	int i,j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!=c)
		s[j++]=s[i];
	}
	s[j]='\0'; 
} 
//判断是否为符号 
int is_sign(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	return 1;
	return 0;
}

