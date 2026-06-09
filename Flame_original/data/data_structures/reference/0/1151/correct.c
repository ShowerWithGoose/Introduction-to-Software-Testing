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
	for(int q=1;q<len-1;q++)
	{
		if(ch[q]=='-')
		{
			int tag=0;
			if(ch[q-1]<='9'&&ch[q-1]>='0')
			{
				if(ch[q+1]<='9'&&ch[q+1]>='0')
				{
					if(ch[q-1]<ch[q+1])
					{
						for(int w=ch[q-1]+1;w<ch[q+1];w++)
							printf("%c",w);
						tag=1;
					}
				}
			}
			if(ch[q-1]<='z'&&ch[q-1]>='a')
			{
				if(ch[q+1]<='z'&&ch[q+1]>='a')
				{
					if(ch[q-1]<ch[q+1])
					{
						for(int w=ch[q-1]+1;w<ch[q+1];w++)
							printf("%c",w);
						tag=1;
					}
				}
			}
			if(ch[q-1]<='Z'&&ch[q-1]>='A')
			{
				if(ch[q+1]<='Z'&&ch[q+1]>='A')
				{
					if(ch[q-1]<ch[q+1])
					{
						for(int w=ch[q-1]+1;w<ch[q+1];w++)
							printf("%c",w);
						tag=1;
					}
				}
			}
			if(!tag)
				printf("-");
		}
		else
			printf("%c",ch[q]);
	}
	printf("%c", ch[len-1]);
}



