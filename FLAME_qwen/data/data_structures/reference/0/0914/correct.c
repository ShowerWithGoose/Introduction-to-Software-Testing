#include <stdio.h> 
#include <string.h>
int main()
{
	int n=0,m=0;
	char p;
	char in[10000];
	scanf("%s",in);
	m=strlen(in);
	while(n<m)
	{
		if(in[n]=='-')
		{
			p=in[n-1]+1;
			if(in[n-1]<in[n+1]&&in[n-1]<='z'&&in[n+1]<='z'&&in[n-1]>='a'&&in[n+1]>='a')
			{
				
				while(p<in[n+1])
				{
					printf("%c",p);
					p++;
				}
			}
			else if(in[n-1]<in[n+1]&&in[n-1]<='Z'&&in[n+1]<='Z'&&in[n-1]>='A'&&in[n+1]>='A')
			{
				while(p<in[n+1])
				{
					printf("%c",p);
					p++;
				}
			}
			else if(in[n-1]<in[n+1]&&in[n-1]<='9'&&in[n+1]<='9'&&in[n-1]>='0'&&in[n+1]>='0')
			{
				while(p<in[n+1])
				{
					printf("%c",p);
					p++;
				}
			}
			else
			{
				printf("%c",in[n]);
			}
		}
		else
		{
			printf("%c",in[n]);
		}
		n++;
	}
	return 0;
}

