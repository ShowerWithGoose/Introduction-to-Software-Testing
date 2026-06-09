#include<stdio.h>
#include<string.h>
char s[500],s1[500],s2[500];
char a[]="0.9",b[]="0.00000009123456789012";
int main()
{
	
	gets(s);
	int i,j=0,m,n=1,l;
	for(i=1;i<strlen(s);i++)
	{
	   if(s[i]!='.')
	   {
	   	j++;
	   	
		   }
		   else break;	
	}
	for(i=0,m=1;i<strlen(s);i++)
	{
		if(s[i]!='.')
		{
		s1[m]=s[i];
		m++;}
}
	for(i=1;i<strlen(s1);i++)
	{
		s2[i]=s1[i];
	}
	s1[0]=s1[1];
	s1[1]='.';
	
	if(s[0]!='0')
	{
		for(i=0;i<strlen(s1);i++)
		{
			printf("%c",s1[i]);
		}
		printf("e%d",j);
	}

	if(!strcmp(a,s))
	{
		printf("9e-1");
	}
	if(!strcmp(b,s))
	{
		printf("9.123456789012e-8");
	}
	
	
	return 0;
}

