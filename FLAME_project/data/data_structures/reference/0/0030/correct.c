#include<stdio.h>
#include<string.h> 
int main()
{	
	int i;
	int d;
	char b[100]={0};
	scanf("%s",b);
	for(i=0;b[i]!='\0';i++)//遍历 
	{
//		printf("> %d\n",i);
		int c= 0;
		if(b[i]=='-'){//有-的情况 
			if(b[i-1]<b[i+1]&&'a'<=b[i-1]&&b[i-1]<='z'&&b[i+1]<='z')
				c=b[i-1];
			else if(b[i-1]<b[i+1]&&'A'<=b[i-1]&&b[i+1]<='Z')
				c=b[i-1];
			else if(b[i-1]<b[i+1]&&'0'<=b[i-1]&&b[i+1]<='9')//-左边 
				c=b[i-1];
			if(c)//-左侧存在 
			{
				for(d=b[i-1]+1;d<b[i+1];d++) 
				
				printf ("%c",d);
			} 
			else printf("%c",b[i]);
		}
		else printf("%c",b[i]);
	}
}

