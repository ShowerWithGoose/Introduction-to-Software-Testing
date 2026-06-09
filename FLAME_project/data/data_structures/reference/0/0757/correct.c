#include<stdio.h>
#include<string.h>
char input[100000];
int judge(int i)
{
	if(input[i-1]<='9'&&input[i-1]>='0'&&input[i+1]<='9'&&input[i+1]>='0')
	return 1;
	else if(input[i-1]<='z'&&input[i-1]>='a'&&input[i+1]<='z'&&input[i+1]>='a')
	return 1;
	else if(input[i-1]<='Z'&&input[i-1]>='A'&&input[i+1]<='Z'&&input[i+1]>='A')
	return 1; 
	else 
	return 0;
}
int place[10000];//符合条件的-左右的字母位置,数组储存位置
int figure;//打印字母个数 
char c;
int i=1,j=0,k=0;
int main()
{
	gets(input);
	for(i=0;i<strlen(input);i++) 
	{
		if(i>0&&input[i]=='-'&&judge(i)==1&&(input[i+1]-input[i-1]>1))//发现-号，且满足可展开条件 
		{//开始打印 
			c=input[i-1];
			figure=input[i+1]-input[i-1]-1;
			for(k=0;k<figure;k++)
			printf("%c",input[i-1]+k+1); 
		}
		else
		printf("%c",input[i]);
	} 
} 

