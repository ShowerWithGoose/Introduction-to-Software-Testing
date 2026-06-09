#include<stdio.h>
#include<string.h>
int main()
{
	char s[105];
	int i=0,k=0,m,n,len;
	gets(s);
	len=strlen(s);
	for(i=0;i<=len-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9'&&k>0)
		    printf("%c",s[i]);
		if(s[i]>='1'&&s[i]<='9'&&i!=len-1&&k==0) 
		    printf("%c.",s[i]),k++,n=i;
	    if(s[i]>='1'&&s[i]<='9'&&i==len-1&&k==0) 
		    printf("%c",s[i]),k++,n=i;
		if(s[i]=='.') m=i;
	}
	if(s[0]=='0')  printf("e-%d",n-m);
	if(s[0]>='1'&&s[0]<='9') printf("e%d",m-n-1); 
	return 0;
} 

