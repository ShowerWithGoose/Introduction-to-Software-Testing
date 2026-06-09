#include <stdio.h>
#include <string.h>
int main()
{
	int i,j=0,t=0;
	char s[100],op,ed,g[100],l[100];
	char*fh;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='-')
		t++;
	}
	while((fh=strchr(s,'-'))!=NULL&&t>0)
	{
	j=0;
	op=*(fh-1);
	ed=*(fh+1);
	*(fh-1)='\0';
	strcpy(l,fh+2);
	if(op<='9'&&op>='0'&&ed<='9'&&ed>='0'&&op<ed)
	{
		for(i=op-'0',j=0;i<=ed-'0';i++,j++)
		{
			g[j]=i+'0';
		}
		g[j]='\0';
	}
	else if(op<='z'&&op>='a'&&ed<='z'&&ed>='a'&&op<ed)
	{
		for(i=op-'a';i<=ed-'a';i++,j++)
		{
			g[j]=i+'a';
		}
		g[j]='\0';
	}
	else if(op<='Z'&&op>='A'&&ed<='Z'&&ed>='A'&&op<ed)
	{
		for(i=op-'A';i<=ed-'A';i++,j++)
		{
			g[j]=i+'A';
		}
		g[j]='\0';
	}
	else
	{
	   	g[0]=op;
	   	g[1]='-';
	   	g[2]=ed;
	   	g[3]='\0';
	   	t--;
	   	
	}
	strcat(s,g);
	strcat(s,l);
	}
	puts(s);
}

