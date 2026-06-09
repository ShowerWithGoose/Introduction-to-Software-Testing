#include<stdio.h>
#include<string.h>
char a[1000];

int main()
{
	scanf("%s",a);
	int cnt=0;
	int s=0;
	if(a[0]=='-'){
		printf("-");
		s++;
	}
	if(a[s]=='0')
	{
		s=s+2;
		for(;s<strlen(a);s++)
		{
			if(a[s]=='0')cnt++;
			else break;
		}
		cnt++;
		printf("%c",a[s]);
		int pos=s+1;
		for(int i=s+1;i<strlen(a);i++)
		{
			if(a[i]!='0')pos=i;
		}
		a[pos+1]=0;
		if(a[s+1]!=0)printf(".%s",a+s+1);
		printf("e-%d",cnt);
	}else{
		printf("%c",a[s]);
		s=s+1;
		int j=s;
		for(;s<strlen(a);s++)
		{
			if(a[s]!='.')cnt++;
			else break;
		}
		if(a[s]=='.'){
			int pos=s+1;
			for(int i=s+1;i<strlen(a);i++)
			{
				if(a[i]!='0')pos=i;
			}
			a[pos+1]=0;
			if(!a[s+1]==0)
			{
				printf(".");
				for(int i=j;i<strlen(a);i++)
				{
					if(a[i]!='.')
					printf("%c",a[i]);
				}
			}
		}else{
			int pos=s+1;
			for(int i=s+1;i<strlen(a);i++)
			{
				if(a[i]!='0')pos=i;
			}
			a[pos+1]=0;
			if(!a[s+1]==0)
			{
				printf(".");
				printf("%s",a+j);
			}
		}
		printf("e%d",cnt);
	}
	return 0;
}
//0.09123456789012

