#include<stdio.h>
int main()
{
	int i,j=0,m=0,k;
	int p[505],n=0;//-位置 
	for(i=0;i<=505;i++)
	p[i]=505; 
	char f,b;
	char s[505];
	gets(s);
	for(i=0;i<=strlen(s)-1;i++)
	{
		if(s[i]=='-')
		{
			p[j]=i;//-出现的位置 
			j++;
			n++;
		}
	}

	if(p[0]+1==strlen(s))//如果-出现在最后一个 
	{
	
		puts(s);
		return 0;
	}
	
	
	
	
	else
	{
		
		i=0;
		for(k=0;k<=n;k++)//k是-的次数 
		{
			for(i;i<p[m]&&i<=strlen(s);i++)//先输出-之前的 
			{
				printf("%c",s[i]);
			}
			f=s[p[k]-1];
			b=s[p[k]+1];
			if(f+0<'9'&&f+0>='0'&&b+0>'0'&&b+0<='9'&&f<b)//数字 
			{
				for(j=f+1;j<=b;j++)
				{
					printf("%c",j);
				}
			}
			else if(f+0<122&&f+0>=97&&b+0>97&&b+0<=122&&f+0<b+0)//小写 
			{
				for(j=f+1;j<=b;j++)
				{
					printf("%c",j);
				}
			}
			else if(f+0<90&&f+0>=65&&b+0>65&&b+0<=90&&f+0<b+0)//大写 
			{
				for(j=f+1;j<=b;j++)
				{
					printf("%c",j);
				}
			}
			else
			{	
				for(j=p[m];j<p[m+1]&&j<=strlen(s);j++)
				printf("%c",s[j]);
				
			}
			i=p[m]+2;
			m++;
			
		}
	}
}
	
	


