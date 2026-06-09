#include<stdio.h>
#include<string.h>
char str[10000],s[10000],y1[10000];
int x[10000],y[10000],x1[10000];//y表示符号位置，x表示数字 
int i,j,k,l=0;
int m,n=0;
int mark,mark_1,mark_2=0;
int sum=0;
int main()
{
	gets(str);//读入原始字符串
	for(i=0,j=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')
		s[j++]=str[i];
	}//删去空格存入新串，j得到字串的长度,其中含有= 
	for(k=0,l=0;k<j;k++)
	{
		if(s[k]=='+'||s[k]=='-'||s[k]=='*'||s[k]=='/'||s[k]=='=')
		{
			y[l]=k;
			l++;
		}
	}//找到符号的位置 ,l即符号个数,包含=.
	for(i=0;i<y[0];i++)//第一个数字特殊
	{
		if(i==y[0]-1)
		x[0]+=s[i]-'0';
		else
		x[0]=(x[0]+s[i]-'0')*10;
	}
	for(i=0;i<l-1;i++)//符号数 
	{
		mark=y[i+1]-y[i];
		mark_1=y[i+1];
		mark_2=y[i];
		for(k=1;k<mark;k++)
		{
		if(k==mark-1)
		x[i+1]=x[i+1]+(s[mark_2+k]-'0');
		else
		x[i+1]=(x[i+1]+s[mark_2+k]-'0')*10;
		}
	}//存入所有数字，i表示数字个数，和符号数一样(含有等号） 
	 for(i=0;i<l;i++)//乘除运算 
	{
	 	if(s[y[i]]=='*')
	 	{
	 		x[i+1]=x[i]*x[i+1];	
		}
	
		else if(s[y[i]]=='/')
		{
			x[i+1]=x[i]/x[i+1]; 
		}
		else if(s[y[i]]=='+'||s[y[i]]=='-'||s[y[i]]=='=')//含有等号 
		{
			x1[m]=x[i];
			y1[m]=s[y[i]];//m表示了需要参加加法运算的个数，数组存了位置 
			m++;
		}
	}
	sum=x1[0];
	for(n=0;n<m-1;n++)//加减运算
	{
		if(y1[n]=='+')
		sum+=x1[n+1];
		else if(y1[n]=='-')
		sum-=x1[n+1];
	} 
	printf("%d",sum); 
	return 0;
} 

