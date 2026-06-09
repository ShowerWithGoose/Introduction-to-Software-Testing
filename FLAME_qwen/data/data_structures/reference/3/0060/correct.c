#include<stdio.h>
#include<string.h>
int main()
{
	char dat[110],test[110]="";
	gets(dat);
	int j,s,s0;
	s=strlen(dat);
	
	for(j=0;;j++)//.
	{
		if(dat[j]=='.')
		{
			break;
		}
	}
	for(s0=s-1;;s0--)//0
	{
		if(dat[s0]!='0')
		{
			break;
		}
	}
	for(int i=0;i<j;i++)//test
	{	
		test[i]=dat[i];
	}
	for(int i=j;i<=s0-1;i++)//test
	{
		test[i]=dat[i+1];
	}
	//printf("%s",test);
	if(test[0]=='0')//0.000...
	{
		int i;
		for(i=0;;i++)
		{
			if(test[i]!='0')
			{
				break;
			}
		}
		if(strlen(test)-i>1)
		{
			printf("%c.",test[i]);
			for(int k=i+1;k<=strlen(test)-1;k++)
			{
				printf("%c",test[k]);
			}
			printf("e-%d",i);
		}
		else
		{
			printf("%c",test[i]);
			printf("e-%d",i);
		}
	}
	else//n...
	{
		printf("%c.",test[0]);
		for(int k=1;k<=strlen(test)-1;k++)
		{
			printf("%c",test[k]);
		}
		printf("e%d",j-1);
	}
	
	return 0;
}

