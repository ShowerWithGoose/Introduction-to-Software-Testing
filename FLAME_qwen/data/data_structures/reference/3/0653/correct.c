#include<stdio.h>
#include<string.h>
int main ()
{
	char s[1000];
	gets(s);
	int len=strlen(s),i,j,k;
	for( i=0;i<=len-1;i++)
	{
		if (s[i]=='.') j=i;
	}
	if(j==1)
	{
	 if(s[0]=='0')
	 {
		for(i=2;i<=len-1;i++)
		{
		   if(s[i]!='0')
		   {
		     k=i;break;
		   }
		}
		printf("%c",s[k]);
		if(k!=len-1) printf(".");
		int t=k;
		for(i=t+1;i<=len-1;i++)
		{
		   printf("%c",s[i]);
		}
		printf("e-%d",k-1);
	 } 
	
	 else 
	 {
		for(i=0;i<=len-1;i++)printf("%c",s[i]);
		printf("e0");
	 }
	}
	else
	{
		printf("%c.",s[0]);
		for(i=1;i<=j-1;i++)printf("%c",s[i]);
		for(i=j+1;i<=len-1;i++)printf("%c",s[i]);
		printf("e%d",j-1);
	}
	 
	
	return 0;
} 

