#include<stdio.h>
int main()
{
	char ch[50]={},a,b;
	int i,n;
	scanf("%s",ch); 
		for(i=0;i<=strlen(ch);i++)
	{
		if(ch[i]=='-')
		{
			if(a>='0'&&a<ch[i+1]&&ch[i+1]<='9')
			for(n=1;a<ch[i+1]-1;n++)
			{
				a=a+1;
				printf("%c",a);
			}
			else if(a>='a'&&a<ch[i+1]&&ch[i+1]<='z')
			for(n=1;a<ch[i+1]-1;n++)
			{
				a=a+1;
				printf("%c",a);
			}
			else if(a>='A'&&a<ch[i+1]&&ch[i+1]<='Z')
			for(n=1;a<ch[i+1]-1;n++)
			{
				a=a+1;
				printf("%c",a);
			}
			else
			printf("%c",ch[i]);
		}
		else 
		{
		printf("%c",ch[i]);
		a=ch[i];	
		}
	}
	return 0;
}

