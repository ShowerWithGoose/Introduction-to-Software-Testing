#include<stdio.h>
#include<string.h>
char str[10000];
int judge(char a,char b)
{
	if(a<='z'&&a>='a')
	{
		if(b<='z'&&b>='a'&&b>a) return 1;
		else return 0;
	}
	if(a<='Z'&&a>='A')
	{
		if(b<='Z'&&b>='A'&&b>a) return 1;
		else return 0;
	}
	if(a<='9'&&a>='0')
	{
		if(b<='9'&&b>='0'&&b>a) return 1;
		else return 0;
	}
}
int main()
{
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;)
	{
		if(str[i+1]!='-') printf("%c",str[i++]);
		else
		{
			if(!judge(str[i],str[i+2]))//不需调整情况 
			{
				printf("%c%c",str[i],str[i+1]);
				i+=2;
			}
			else//需要调整'
			{
				printf("%c",str[i]);
				int lens=str[i+2]-str[i];
				for(int j=1;j<lens;j++)
				{
					printf("%c",str[i]+j);
				}
				i+=2;
			} 
		}
	}		
}



