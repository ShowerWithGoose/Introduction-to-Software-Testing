#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a='\0',b='\0',c='\0';
	char d[350];
	gets(d);
	int len=strlen(d);
	int i=0;
	char z,q,p; 
	for(i;i<len;i++)
	{
		b=d[i];
		if(i)
		a=d[i-1];c=d[i+1];
		if(b!='-')
		printf("%c",b);
		else
		{
		if(islower(a)&&islower(c)&&a<c){
		
		for(z=a+1;z<c;z++)
		{
			printf("%c",z);
		}
	}
		else if(isupper(a)&&isupper(c)&&a<c)
		{
		for(q=a+1;q<c;q++)
		{
			printf("%c",q);
		}
	}
		else if(isdigit(a)&&isdigit(c)&&a<c)
		{
		for(p=a+1;p<c;p++)
		{
			printf("%c",p);
		}
	}
		else
		printf("-");
	}
	}
		return 0;
}

