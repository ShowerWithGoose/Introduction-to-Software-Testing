#include<stdio.h>
#include<string.h>
int main()
{
	/*char s[1000];
	int sum=0;
	int i,j;
	gets(s);
	for(i=j=0;s[i]!='\0';i++)
		if(s[i]!=' ')
		s[j++]=s[i];
		s[j]='\0';
	puts(s);
	return 0;*/
	int i,j,n=0,m=0;
	char s[200];
	gets(s);
	 if(s[0]=='0')
	 {
	 	for(i=j=0;s[i]!='\0';i++)
	 {
	 		if(s[i]=='0')
	 	n+=1;//记录次数
	 	if(s[i]>='1'&&s[i]<='9')
	 	break;
	  } 
	  for(i=j=0;s[i]!='\0';i++)
		if(s[i]!='.')
		s[j++]=s[i];
		s[j]='\0';//去掉所有的小数点 
		if(strlen(s)>1+n)
		{
		  for(i=strlen(s)-1;i>=n+1;i--)
		 s[i+1]=s[i];
		 s[n+1]='.';	
		 }
		 for(i=n;i<=strlen(s)-1;i++)
		 printf("%c",s[i]); 
		printf("e-%d",n);
	 }
	 else
	 {
	 	for(i=0;s[i]!='\0';i++)
	 	{
	 		m++;
	 		if(s[i]=='.')
	 		break;
		 }
		for(i=j=0;s[i]!='\0';i++)
		if(s[i]!='.')
		s[j++]=s[i];
		s[j]='\0';
		 for(i=strlen(s)-1;i>=1;i--)
		 s[i+1]=s[i];
		 s[1]='.';
		 printf("%se%d",s,m-2);
	 }
	 return 0;
}

