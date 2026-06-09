#include<stdio.h>
int main()
{
	char s[1024];
gets(s);
	int i,j,k,m;
	for(i=0;s[i]!='\0';i++)
	{
		j=0;k=0;m=0;
		if(s[i]=='-')
		{
		if(s[i-1]>=s[i+1])
		{
			printf("%c",s[i]);
			}
		else if(s[i-1]>=48&&s[i-1]<57&&s[i+1]<=57&&s[i+1]>=48)
		{
		j=s[i-1];k=s[i+1];
		for(m=j+1;m<k;m++)
		{
			printf("%c",m);
		}
			continue;
		}
		else if(s[i-1]>=65&&s[i-1]<90&&s[i+1]>65&&s[i+1]<=90)
		{
			j=s[i-1];k=s[i+1];
			for(m=j+1;m<k;m++)
			{
				printf("%c",m);
			}
			continue;
		}
		else if(s[i-1]>=97&&s[i-1]<122&&s[i+1]<=122&&s[i+1]>97)
		{
			j=s[i-1];k=s[i+1];
			for(m=j+1;m<k;m++)
			{
				printf("%c",m);
			}
			continue;
		}
	}
	printf("%c",s[i]);
		
	}
	
return 0;
}




