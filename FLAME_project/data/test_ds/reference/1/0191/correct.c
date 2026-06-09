#include <stdio.h>
#include <string.h>
int yizhi(char ten,char ninr)
{
	//char ten,ninr;
	if(((ten>='0'&&ten<='9')&&(ninr>='0'&&ninr<='9'))||((ten>='a'&&ten<='z')&&(ninr>='a'&&ninr<='z'))||((ten>='A'&&ten<='Z')&&(ninr>='A'&&ninr<='Z')))
	return 1;
}
int main()
{
	char ch[1000],chi[1000];
	scanf("%s",ch);
	int i=0,j=0,h,weishu;
	for(i=0;i<strlen(ch);i++)
	{
		chi[i]=ch[i];
	}
	char temp;
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]!='-')
		{
		
			printf("%c",ch[i]);
		}
		else if(ch[i]=='-')
		{
			if(yizhi(ch[i-1],ch[i+1])==1)
			{
				weishu=ch[i+1]-ch[i-1];
				for(j=0;j<weishu;j++)
				{
					printf("%c",ch[i-1]+j+1);
					
				}
				i=i+1;
			}
			else
			{
				printf("%c",ch[i]); 
			 } 
		}
	}
	
	return 0;
}

