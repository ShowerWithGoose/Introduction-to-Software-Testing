#include<stdio.h>
int main()
{
	char s[110]= {};
	gets(s);
	int num=0;
	for(int i=0; s[i]!='.'; i++)
		num++;
	if(num==1)
	{
		if(s[0]!='0')
		{
			for(int i=0; s[i]; i++)
				printf("%c",s[i]);
			printf("e0");
		}
		else if(s[0]=='0')
		{
			int ling=0,cnt=0;

			for(int i=2; s[i]=='0'; i++)
				ling++;
			for(int j=2; s[j]; j++)
				if(s[j]!='0')
					cnt++;
			if(ling==0&&cnt!=1)
			{
				printf("%c.",s[2]);
				for(int k=3; s[k]; k++)
					printf("%c",s[k]);
				printf("e-1");
			}
			else if(ling==0&&cnt==1)
				printf("%ce-1",s[2]);
			else if(ling!=0&&cnt==1)
				printf("%ce-%d",s[ling+2],ling+1);
			else if(ling!=0&&cnt!=1)
			{
				printf("%c.",s[ling+2]);
				for(int o=ling+3; s[o]; o++)
					printf("%c",s[o]);
				printf("e-%d",ling+1);
			}
		}
	}
	else if(num!=1)
	{
		printf("%c.",s[0]);
		for(int i=1;i<num;i++)
			printf("%c",s[i]);
		for(int i=num+1;s[i];i++)
			printf("%c",s[i]);
		printf("e%d",num-1);
	}
	return 0;
}

