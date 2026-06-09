#include<stdio.h> 
#include<string.h>


int main()
{
	char s[105];
	scanf("%s",s);
	int j=0,loc1=0,loc2=0,flag1=1,flag2=1;
	int yet=0;
	int h=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[0]=='0')
		{
			h=2;
			while(s[h]=='0'){
				h++;
			}
			loc2=h;
			loc1=1;
			yet=1;
			break;
		}
		if(s[i]>='0'&&s[i]<='9'&&flag1)
		{
			loc2=i;
			flag1=0;
		}
		else if(s[i]=='.'&&flag2)
		{
			loc1=i;
			flag2=0;
		}
	
	}
	int tun=loc2-loc1;
	int hi=0;
	if(yet)
	{
		printf("%c",s[loc2]);	
		if(loc2+1!=strlen(s))
		{
			printf(".");
		}
		for(int k=loc2+1;k<strlen(s);k++)
		{
			if(s[k]!='.'){
				putchar(s[k]);
			} 
		}
		
		printf("e%d",-tun);
	}else {
		printf("%c",s[0]);
		if(loc2+1!=strlen(s))
		{
			printf(".");
		}
		for(int h=1;h<strlen(s);h++)
		{
			if(s[h]!='.')
			putchar(s[h]);
		}
		printf("e%d",-tun-1);
	}
	
	
	return 0;
}

