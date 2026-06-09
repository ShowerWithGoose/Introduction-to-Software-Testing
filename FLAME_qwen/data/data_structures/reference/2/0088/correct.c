#include<stdio.h>
#include<string.h>
void fix(char a[])
{
	int i,j;
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(a[i]!=' ')
		a[j++]=a[i];
	}	a[j]='\0';
}

int main()
{
	char cal[100],op[50];
	gets(cal);
	fix(cal);
	int i,j,a,l,k=0,num[100],ans[100],res=0;
	for(i=0,j=0;cal[i]!='\0';i++)
	{
	if(cal[i]=='+'||cal[i]=='-'||cal[i]=='*'||cal[i]=='/'||cal[i]=='=')
	op[j++]=cal[i];
	}
	op[j]='\0';

	//把运算符存入op[] 
	for(i=0,j=0;cal[i]!='\0';j++)
	{
		for(l=0;cal[i]!=op[j];i++)
		{
			l=l*10+(cal[i]-'0');
		}
		num[j]=l;
		i++;
	}
	for(i=0;i<strlen(op);i++)
	
	//把字符转换成数字存入num[]
		for(i=0;op[i]!=0;i++)
	{
		
		if(op[i]=='-')
		num[i+1]=num[i+1]*(-1);
		
	}
	
	
	
	
	for(i=0;op[i]!='\0';i++)
	{
		if(op[i]=='*')
		{
		num[i+1]=num[i]*num[i+1];
		num[i]=0;
		}
		if(op[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
		}
		
		
	 } 
	 
	for(i=0;i<strlen(op);i++)
		res+=num[i];
		
		
	
	
	printf("%d",res);
	return 0;
	
}



