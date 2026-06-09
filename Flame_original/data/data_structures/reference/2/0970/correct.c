#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	char str[100+3],op[10];
	gets(str);
	int count=0,i,j,k;
	for(i=0,j=0;i<strlen(str);i++)
	{
		if(str[i]!=' ')//去空格 
			str[j++]=str[i];
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')//取运算符 
			op[count++]=str[i];
	}
	str[j]='\0';
	//printf("count=%d\n",count);//检查运算符个数 
	//puts(str);//检查去空格效果 
	
	int num[10+3];
	num[0]=atoi(str);
	for(i=0,k=1;i<strlen(str);i++)//取数字 
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			num[k++]=atoi(str+i+1);
		}
	}
	/*for(i=0;i<=count;i++)//取数字效果调试 
	{
		printf("num[%d]=%d\n",i,num[i]);
	}*/
	
	int end=0,czs=count;
	for(i=0;i<count;i++)//先乘除 
	{
		if(op[i]=='*')
		{
			end=num[i]*num[i+1];
			num[i]=end;
			for(j=i;j<count;j++)
			{
				num[j+1]=num[j+2];
				op[j]=op[j+1];
			}
			i--;count--;
		}
		else if(op[i]=='/')
		{
			end=num[i]/num[i+1];
			num[i]=end;
			for(j=i;j<count;j++)
			{
				num[j+1]=num[j+2];
				op[j]=op[j+1];
			}
			i--;count--;
		}
	}
	
	for(i=0;i<count;i++)//后加减 
	{
		if(op[i]=='+')
		{
			end=num[i]+num[i+1];
			num[i]=end;
			for(j=i;j<count;j++)
			{
				num[j+1]=num[j+2];
				op[j]=op[j+1];
			}
			i--;count--;
		}
		else if(op[i]=='-')
		{
			end=num[i]-num[i+1];
			num[i]=end;
			for(j=i;j<count;j++)
			{
				num[j+1]=num[j+2];
				op[j]=op[j+1];
			}
			i--;count--;
		}
	}
	
	//printf("czs=%d\n",czs);
	printf("%d\n",num[0]);
 	system("pause");
	return 0;
}


