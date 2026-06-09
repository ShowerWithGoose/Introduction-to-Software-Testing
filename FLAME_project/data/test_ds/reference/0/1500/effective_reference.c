#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define cin(k) scanf("%d",&k)
char ch[1000005];
signed main()
{
	scanf("%s",ch);
	int len=strlen(ch);
	printf("%c",ch[0]);
	for(int i=1;i<len-1;i++)
	{
		if(ch[i]=='-')
		{
			int w=0;
			if(ch[i-1]<='9'&&ch[i-1]>='0')
			{
				if(ch[i+1]<='9'&&ch[i+1]>='0')
				{
					if(ch[i-1]<ch[i+1])
					{
						for(int j=ch[i-1]+1;j<ch[i+1];j++)
							printf("%c",j);
						w=1;
					}
				}
			}
			if(ch[i-1]<='z'&&ch[i-1]>='a')
			{
				if(ch[i+1]<='z'&&ch[i+1]>='a')
				{
					if(ch[i-1]<ch[i+1])
					{
						for(int j=ch[i-1]+1;j<ch[i+1];j++)
							printf("%c",j);
						w=1;
					}
				}
			}
			if(ch[i-1]<='Z'&&ch[i-1]>='A')
			{
				if(ch[i+1]<='Z'&&ch[i+1]>='A')
				{
					if(ch[i-1]<ch[i+1])
					{
						for(int j=ch[i-1]+1;j<ch[i+1];j++)
							printf("%c",j);
						w=1;
					}
				}
			}
			if(!w)
				printf("-");
		}
		else
			printf("%c",ch[i]);
	}
	printf("%c", ch[len-1]);
}



