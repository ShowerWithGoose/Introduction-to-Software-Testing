#include<stdio.h>
#include<string.h>
char s[1000];
int main()
{
	scanf("%s",&s);
	int len=strlen(s);
	int i,j=2,m,k;
	if(s[0]=='0')
	{
		while(s[j]=='0')
		j++;
		k=j;
		if(len==j+1)
		{
			printf("%de-%d",s[j]-'0',j-1);
		}
		else
		{
			printf("%d.",s[j]-'0');
			j++;
			while(j<len)
			{
				printf("%d",s[j]-'0');
				j++;
			}
			printf("e-%d",k-1);
		}
	}
	else
	{
		for(i=0;i<len;i++)
		{
			if(s[i]=='.')
			m=i;
		}
		printf("%d.",s[0]-'0');
		for(i=1;i<m;i++)
		printf("%d",s[i]-'0');
		for(i=m+1;i<len;i++)
		printf("%d",s[i]-'0');
		printf("e%d",m-1);
	}
}


