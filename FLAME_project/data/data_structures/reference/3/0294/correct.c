#include <stdio.h>
#include <string.h>
int main()
{
	char ch[150];
	int before[150],after[150];
	gets(ch);
	int i=0,j=0,cnt=0,cnt2=0,k=0,m=0,n=0;
	for(i=0;ch[i]!='.';i++)
	{
		before[i]=ch[i]-'0';
		cnt++;
	}
	for(j=i+1;ch[j]!='\0';j++)
	{
		after[j-i-1]=ch[j]-'0';
		if(after[j-i-1]!=0)
		{
			m=1;
		}
		if(m==1)
		{
			cnt2++;
		} 
	}
	if(before[0]!=0)
	{
		printf("%d.",before[0]);
		for(m=1;m<cnt;m++)
		{
			printf("%d",before[m]);
		}
		for(m=i+1;m<j;m++)
		{
			printf("%d",after[m-i-1]);
		}
		printf("e%d",cnt-1);
	}
	else
	{
		printf("%d",after[j-cnt2-i-1]);
		if(cnt2>1)
		{
			printf(".");
			for(m=j-cnt2-i;m<j-i-1;m++)
			{
				printf("%d",after[m]);
			}
		}
		printf("e-%d",j-i-cnt2);
	}
	return 0;
} 

