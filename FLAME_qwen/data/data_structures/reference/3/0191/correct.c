#include <stdio.h>
#include <string.h>
int main()
{
	
	char ch[103];
	scanf("%s",ch);
	int i;
	int count,weizhi,biaoji;
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]=='.')
		{
			weizhi=i;
			break;
		}
	}
	if(weizhi!=1)
	{
		
		printf("%c",ch[0]);
		printf(".");
		for(i=1;i<weizhi;i++)
		printf("%c",ch[i]);
		for(i=weizhi+1;i<strlen(ch);i++)
		printf("%c",ch[i]);
		printf("e");
		printf("%d",weizhi-1);
		
	}
	else
	{
		if(ch[0]=='0')
		{
			if(ch[2]!='0')
			{
				printf("%c",ch[2]);
				//printf(".");
				for(i=3;i<strlen(ch);i++)
				printf("%c",ch[i]);
				printf("e-1");
				
			}
			else
			{
				for(i=2;i<strlen(ch);i++)
				{
					if(ch[i]!='0')
					{
						weizhi=i;
						break;
					}
				}
				printf("%c",ch[weizhi]);
				if((ch[weizhi+1]<='9')&&(ch[weizhi+1]>='1'))
				printf(".");
				for(i=weizhi+1;i<strlen(ch);i++)
				{
					printf("%c",ch[i]);
				}
				printf("e-");
				printf("%d",weizhi-1);
			}
		}
		else if(ch[0]!='0')
		{
			for(i=0;i<strlen(ch);i++)
			printf("%c",ch[i]);
			printf("e0");
		}
		
	}
	return 0;
}

