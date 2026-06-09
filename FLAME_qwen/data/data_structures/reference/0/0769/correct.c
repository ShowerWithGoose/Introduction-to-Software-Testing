#include<stdio.h>
#include<string.h>
#include<ctype.h>
char in[10000001],out[10000001];
int main()
{
	gets(in);
	int n=1;
	out[0]=in[0];
	for(int i=1;in[i]!='\0';i++)
	{
	if(in[i]=='-')
	{
		if((isdigit(in[i-1]))&&(isdigit(in[i+1])))
		{
		  	for(char j=in[i-1]+1;j<in[i+1];j++)
			out[n++]=j;
		}
		else if(isupper(in[i-1])&&isupper(in[i+1]))
		{
			for(char j=in[i-1]+1;j<in[i+1];j++)
			out[n++]=j;
		}
		else if(islower(in[i-1])&&islower(in[i+1]))
		{
		   for(char j=in[i-1]+1;j<in[i+1];j++)
			out[n++]=j;
		}
		else
		out[n++]=in[i];	
	}
	else
	out[n++]=in[i];
	}
	puts(out);
	return 0;	
}


