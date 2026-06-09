#include<stdio.h>
#include<string.h>
int ans,k,num,l,flag;
char in[10000];
int book[10000];		//把运算式放置在book中 放置的同时完成乘除运算 最后算加减法 
int chdigit(char c);	//没用isdigit 
void squeez(char s[]);	//去除空格的函数 
int main()
{
	gets(in);
	squeez(in);
	for(int i=0;in[i]!='='&&in[i-1]!='=';i++)
	{
		if(in[i]=='+')
			book[k++]=-1;	//用负一代表加法 
		if(in[i]=='-')
			book[k++]=-2;	//用负二代表减法 
		if(chdigit(in[i]))
			{
				for(int j=i;chdigit(in[j]);j++)
				{
					num=num*10+(in[j]+1-'1');
					l++;
				}	
				if(in[i-1]=='*')	//数字参与连续乘除法运算就与上一个存好的数进行计算(运算符前面的数） 
					book[k-1]*=num;
				else if(in[i-1]=='/')
					book[k-1]/=num;
				else
					book[k++]=num;	//数字暂时不参与乘除法运算就先在book数组里存下一个位置 
				num=0;
				i+=l-1;
				l=0;		
				}
	}
	int result=0;	//输出结果 
	for(int q=0;q<10000;q++)
	{
		if(book[q]==-1)
			result+=book[++q];
		else if(book[q]==-2)
			result-=book[++q];
		else
			result+=book[q];
		
	}
	printf("%d",result);
}
void squeez(char s[])
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=' ')
		s[j++]=s[i];
	}
	s[j]='\0';
}
int chdigit(char c)
{
	return (c>='0'&&c<='9')?1:0;
}


