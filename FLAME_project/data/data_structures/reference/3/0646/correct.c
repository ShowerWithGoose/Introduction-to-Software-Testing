#include<stdio.h>
#include<string.h>
char a[1000];

int main()
{
	scanf("%s",a);
	int cnt=0;
	int t=0;
	if(a[0]=='-'){
		printf("-");
		t++;
	}
	if(a[t]=='0')
	{
		t=t+2;
		for(;t<strlen(a);t++)
		{
			if(a[t]=='0')cnt++;
			else break;
		}
		cnt++;
		printf("%c",a[t]);
		int pos=t+1;
		for(int i=t+1;i<strlen(a);i++)
		{
			if(a[i]!='0')pos=i;
		}
		a[pos+1]=0;
		if(a[t+1]!=0)printf(".%s",a+t+1);
		printf("e-%d",cnt);
	}else{
		printf("%c",a[t]);
		t=t+1;
		int j=t;
		for(;t<strlen(a);t++)
		{
			if(a[t]!='.')cnt++;
			else break;
		}
		if(a[t]=='.'){
			int pos=t+1;
			for(int i=t+1;i<strlen(a);i++)
			{
				if(a[i]!='0')pos=i;
			}
			a[pos+1]=0;
			if(!a[t+1]==0)
			{
				printf(".");
				for(int i=j;i<strlen(a);i++)
				{
					if(a[i]!='.')
					printf("%c",a[i]);
				}
			}
		}else{
			int pos=t+1;
			for(int i=t+1;i<strlen(a);i++)
			{
				if(a[i]!='0')pos=i;
			}
			a[pos+1]=0;
			if(!a[t+1]==0)
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

