#include<stdio.h>
#include<string.h>
int main()
{
	int x,i,j;

	char s[105];
	gets(s);
	x=strlen(s); //x 为字符串长度 
	while(s[i]!='.')
	{
		i++;
	}
	//最终得到i为  s【i】= ‘. ’ 
	
	
	//以下为平行关系 
	if(i>1)
	{
		int m;
		printf("%c",s[0]);
		printf(".");
		for(m=1;m<=x-1;m++)
		{
			if(s[m]!='.')
			printf("%c",s[m]);
		}
		printf("e%d",i-1);
	}              //问题所在 
	else if(i=1&&s[0]!='0')
	{
		printf("%s",s);
		printf("e0");
	}
	
	else if(i=1&&s[0]=='0')
	{
		j=1;
		while(s[i+j]!=' '&&s[i+j]=='0')
		{
			j++;
		}
		int k=i+j;  //第一次修改 把三个n 改为 i 
		if((x-k)>1)
		{
			printf("%c.",s[k]);
			for(k=k+1;k<x;k++)
			{
				printf("%c",s[k]);
			}
		}
		else
		{
			printf("%c",s[k]);
		}
		printf("e-%d",j);
	}
	
	
	
	return 0;
}

