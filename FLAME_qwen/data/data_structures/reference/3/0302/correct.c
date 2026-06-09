#include <stdio.h>
#include <string.h>
char in[105];
char out[105];
int main()
{
	gets(in);
	char hold;
	int i=1;
	int len1=strlen(in);
	if(in[0]!='0')
	{
		int flag=0;
		for(i=1;i<len1;i++)
		{
			if(in[i]!='.')
				flag++;
			else
				break;
		}
		if(flag==len1-1)
			for(i=0;i<len1;i++)
				printf("%c",in[i]);
		else
			{
				for(i;i>1;i--)
				{
					hold=in[i];
					in[i]=in[i-1];
					in[i-1]=hold;
				}
				for(i=0;i<len1;i++)
					printf("%c",in[i]);
				printf("e%d",flag);
			}
	}
	else
	{
		int flag=1;
		for(i=2;i<=len1;i++)
			if(in[i]=='0')
				flag++;
			else
				break;
		for(i=2;i<len1;i++)
			{
				if(in[i]!='0')
					{
						printf("%c",in[i]);
						break;
					}
			}
				if(flag!=len1-2)
					printf(".");
				int j=1+i;
		for(j;j<len1;j++)
			printf("%c",in[j]);
			printf("e-%d",flag);
	}
}






