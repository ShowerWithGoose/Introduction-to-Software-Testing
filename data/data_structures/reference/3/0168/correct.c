#include<stdio.h>
#include<string.h>
int main()
{
	char s[105],temp,*p;
	int e=0,i=1,l;
	gets(s);
	if(s[1]=='.')
	{
		if(s[0]>='1'&&s[0]<='9')
		printf("%s",s);
		if(s[0]=='0')
		{
			while(s[i+1]=='0')
			{
				s[i+1]='.';
				s[i]='0';
				e--;
				i++;
			}
			e--;
			if(s[i+2]!='\0')
			{
				temp=s[i+1];
			 	s[i+1]='.';
				s[i]=temp;
				p=&s[i];
				printf("%s",p);
			}
			if(s[i+2]=='\0')
			printf("%c",s[i+1]);	
		}
	}
	else
	{
		for(i=2;i<strlen(s);i++)
		{
			if(s[i]=='.')
			break;
		}
		for(l=i;l>=2;l--)
		{
			s[l]=s[l-1];
		}
		e=i-1;
		s[1]='.';
		printf("%s",s);
	}
	printf("e%d",e);
	return 0;
} 

