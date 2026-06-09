#include<stdio.h>
#include<string.h>
int suanshu(int a,char b,int c);
int main()
{
	int num1,num2,num;
	char fuhao1,fuhao2,fuhao;
	scanf("%d %c",&num1,&fuhao1);
	if(fuhao1=='=')
	{
		printf("%d\n",num1);
		return 0;
	}
	while(fuhao1!='=')
	{
		while(fuhao1=='*'||fuhao1=='/')
		{
			scanf("%d %c",&num2,&fuhao2);
			num1=suanshu(num1,fuhao1,num2);
			fuhao1=fuhao2;
		}
		if(fuhao2=='=')
		break;
		scanf("%d %c",&num,&fuhao);
		while(fuhao=='*'||fuhao=='/')
		{
			scanf("%d %c",&num2,&fuhao2);
			num=suanshu(num,fuhao,num2);
			fuhao=fuhao2;
		}
		num1=suanshu(num1,fuhao1,num);
		fuhao1=fuhao;
		if(fuhao1=='=')
		break;
	 } 
	 printf("%d",num1);
	 return 0;
}


int suanshu(int a,char b,int c)
{
	switch(b)
	{
		case'+':a=a+c;
		        break;
		case'-':a=a-c;
		        break;
		case'*':a=a*c;
		        break;
		case'/':if(c!=0) 
		        a=a/c;
		        break;
	}
	return a;  
}

