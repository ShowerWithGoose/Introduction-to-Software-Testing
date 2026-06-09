#include <stdio.h>
#include <string.h>
#include <math.h>
void squeez(char s[],char c)//删除s中的c字符 
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=c)
		{
			s[j++]=s[i];
		}
	}
	s[j]='\0';
 } 
 
 
 
 
 void squeez2(int s[],int c,int sum)//删除s中的c数字 
{
	int i,j;
	for(i=j=0;i<sum;i++)
	{
		if(s[i]!=c)
		{
			s[j++]=s[i];
		}
	}
 } 
 
 
 
int main()
{
	char arr[100];
	char let[100];
	int num[100]={0};
	gets(arr);
	squeez(arr,' ');//除去arr中的空格 
	int i,n,temp,j,l,n_j;//n记录arr的长度
	int i_n=0,i_l=0;//分别表示let，num数组的第几位 
	n = strlen(arr);
	for(i=0;i<n;i++)//把字符存在了let上面，数字存在了num里面 
	{
		if(arr[i]>='0'&&arr[i]<='9')
		{
			temp = 0;
			for(j=0;arr[i+j]>='0'&&arr[i+j]<='9';j++);
			j--;
			n_j = j;//n_j记录j循环次数，然后arr就可以跳过多个数了 
			for(l=0;l<=j;l++)
			{
				temp += (arr[i+l]-'0')*pow(10,j-l);
			}
			num[i_n++] = temp;
			i = i+n_j;
		}
		else
		{
			let[i_l++] = arr[i];
		}
	}
	int n_l,n_n;//n_l是let的长度，n_n是num的长度
	n_l = i_l;
	n_n = i_n;
	temp = 0;
	for(i=0;i<n_l;i++)
	{
		if(let[i]=='*')
		{
			temp = num[i]*num[i+1];
			num[i+1] = temp;
			num[i] = -1;
			let[i] = ' ';
		}
		else if(let[i]=='/')
		{
			temp = num[i]/num[i+1];
			num[i+1] = temp;
			num[i] = -1;
			let[i]=' ';
		}
		else;
	}
	squeez(let,' ');
	squeez2(num,-1,n_n);
	temp = num[0];
	n_l = strlen(let);
	for(i=0;i<n_l;i++)
	{
		if(let[i]=='+')
		{
			temp += num[i+1];
		}
		else if(let[i]=='-')
		{
			temp -= num[i+1];
		}
		else
		{
			printf("%d",temp);
			return 0;
		} 
	}
	
	return 0;
	
	
	
	
	
	
}

