#include <stdio.h> 
#include <string.h>
int main()
{
	int e=0,n=0,m=0,s=0,sgn=0,st=0;
	char in[102];
	scanf("%s",in);
	m=strlen(in);
	if(in[n]=='-')
	{
		sgn=1;
		n++;
	}
	if(sgn==1)
	{
		printf("%c",'-');
	}
	if(in[n]=='0')
	{
		st=1;
	}
	if(st==0)
	{
		printf("%c",in[n]);
		n++;
		if(n!=m)
		{
			printf(".");
		}
		while(n<m)
	{
		if(in[n]=='.')
		{
			s=1;
		}
		else if(in[n]>='0'&&in[n]<='9')
		{
			if(s==0)
			{
				e++;
			}
			printf("%c",in[n]);
		}
		n++;
	}
	printf("e");
	printf("%d",e);
	}
	else
	{
		n++;
		n++;
		while(in[n]=='0')
		{
			e++;
			n++;
		}
		printf("%c",in[n]);
		e++;
		n++;
		if(n!=m)
		{
			printf(".");
		}
		while(n<m)
    	{
	    	if(in[n]>='0'&&in[n]<='9')
	    	{
			printf("%c",in[n]);
	    	}
	    	n++;
    	}
    	printf("e-%d",e);
	}
}



