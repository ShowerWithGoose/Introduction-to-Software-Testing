#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define bufsiz 512
int op_num(char,int,int);
int isnum(char);
int main()
{
	char s[bufsiz],op[bufsiz];
	int num[bufsiz],ans[bufsiz];
	int i,i_num,i_op,j,k,k1,count;
	int sum,result=0;
	gets(s);
	for(i=0,i_num=0,i_op=0;i<strlen(s);i++)
	{
		if(s[i]=='='||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			op[i_op]=s[i];
			i_op++;
		}	
		if(s[i]>='0'&&s[i]<='9')
		{
			for(sum=0,j=0;isdigit(s[i+j])!=0;j++)
				sum=sum*10+s[i+j]-'0';
			num[i_num]=sum;
			i_num++;
			i+=j-1;//将已读的数字跳过		
		}
	} 
	count=i_num;
	if(op[0]=='=')
	{
		printf("%d",num[0]);
		return 0;
	}	
	if(op[0]!='+'&&op[0]!='-')
	{
		for(i=0,k=0;i<count;i++,k++)
			if(op[i]=='*'||op[i]=='/')
			{
				for(j=0,ans[k]=num[i];op[i+j]=='*'||op[i+j]=='/';j++)
					ans[k]=op_num(op[i+j],ans[k],num[i+j+1]);	
				ans[k]=op[i-1]=='-'?ans[k]*(-1):ans[k];
				i+=j;
			}
			else
				ans[k]=op[i-1]=='-'?(-1)*num[i]:num[i];				
	}
	else
	{
		ans[0]=num[0];
		for(i=1,k=1;i<count;i++,k++)
			if(op[i]=='*'||op[i]=='/')
			{
				for(j=0,ans[k]=num[i];op[i+j]=='*'||op[i+j]=='/';j++)
					ans[k]=op_num(op[i+j],ans[k],num[i+j+1]);	
				ans[k]=op[i-1]=='-'?ans[k]*(-1):ans[k];
				i+=j;
			}
			else
				ans[k]=op[i-1]=='-'?(-1)*num[i]:num[i];
	}
	k1=k;
	for(k=0;k<k1;k++)
		result+=ans[k];	
	printf("%d",result);
	return 0;
} 
int op_num(char op,int a,int b)
{
	switch(op)
	{
		case '+':return a+b;break;
		case '-':return a-b;break;
		case '*':return a*b;break;
		case '/':return a/b;break;
	}
}


