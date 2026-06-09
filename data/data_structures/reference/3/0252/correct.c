#include<stdio.h>
#include<string.h>
int find(char *str,int p)//找小数点 
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='.')
		{
			p=i;
			break;
		}
	}
	return p;
}
int findnum(char *str,int p)//找第一个非零位数 
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]>'0'&&str[i]<='9')
		{
			p=i;
			break;
		}
	}
	return p; 
}
int main()
{
	char str[100];
	gets(str);
	int p=find(str,p);
	int num=findnum(str,num);
	int e_num;//e后面接的数 
	if(p<num) e_num=num-p;
	else e_num=p-num-1;
    char sub[100];//输出串 
    sub[0]=str[num];
    if(num==strlen(str)-1)//只有最后一位非零 
	{
		sub[1]='e';
		sub[2]='-';
		if(e_num>9) //换成两位 
		{
			sub[3]=e_num/10+'0';
			sub[4]=e_num%10+'0';
			sub[5]='\0';
		}
		else 
		{
			sub[3]=e_num+'0';
			sub[4]='\0';
		}
	} 
    else
	{
    	sub[1]='.';
    	int i,j=2;
		for(i=num+1;i<strlen(str);i++)
		{
			if(str[i]!='.')
			{
				sub[j++]=str[i];
			}
		}
		sub[j++]='e';
		if(p<num) 
		{
			sub[j++]='-';
		}
		if(e_num>9) 
		{
			sub[j++]=e_num/10+'0';
			sub[j++]=e_num%10+'0';
		}
		else sub[j++]=e_num+'0';
		sub[j]='\0';
	} 
	puts(sub);
	return 0;
} 



